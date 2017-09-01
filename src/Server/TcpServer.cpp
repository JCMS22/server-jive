//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#include <QCoreApplication>
#include "TcpServer.h"
#include <QTcpSocket>


server::TcpServer::TcpServer(dbconnector::IJsonLookupDataBase* callback) :
                                                                          _timeout(0), _pCallback(callback),_pStack(nullptr) {

}
void server::TcpServer::open(sServerConfig config) {
    _pServer = new QTcpServer();
    bool res = _pServer->listen(QHostAddress::LocalHost, config.port);
    if(!res){
        qDebug("Error opening TCP server\n");
        terminate();
    }else {
        _pMapper = new QSignalMapper(this);
        /* Register connection callback and timeout timer */
        connect(_pServer,SIGNAL(newConnection()),this, SLOT(connected()));
        connect(&_timer,SIGNAL(timeout()),this, SLOT(onTimerElapsed()));

        /* Register callback used by the command processor */
        connect(&_myCallback, SIGNAL(sendMessage(QString,int)),
                this, SLOT(onMessageToSend(QString,int)), Qt::QueuedConnection);

        /* Start the timeout after which we close */
        _timer.setInterval(config.timeoutMs);
        _timer.start(config.timeoutMs);


        qDebug() << "Tcp server running on port :" << QString::number(config.port);

    }



}

void server::TcpServer::terminate() {
    _pServer->close();
    QCoreApplication::exit();
}


void server::TcpServer::connected() {
    _timer.stop();
    qDebug("Received new connection\n");
    while (_pServer->hasPendingConnections())
    {
        /* Map the connections in case we have multiple incoming clients */
        auto client = _pServer->nextPendingConnection();
        _socketList.push_back(client);
        _pMapper->setMapping(client, _socketList.length()-1);
        connect(client, SIGNAL(readyRead()), _pMapper, SLOT(map()));
        connect(_pMapper, SIGNAL(mapped(int)),this,SLOT(onData(int)));

    }
    _timer.start();

}


void server::TcpServer::onData(int clientId) {
    _timer.stop();
    auto client = _socketList[clientId];

    if(client){
        while(client->bytesAvailable()) {
            auto message = client->readAll();
            QString cmd(message);
            if (_pStack) {
                _pStack->push(cmd, clientId, &_myCallback);
            } else {
                /* Nothing to do */
            }
        }
    }else {
        /*Shouldn't happen. Might not be needed */
        qDebug("Received invalid client callback\n");
    }
    _timer.start();

}

void server::TcpServer::onTimerElapsed() {
    qDebug("No response have been received for more than 10s, bye!");
    terminate();

}

void server::TcpServer::setCmdStack(cmdprocessor::ICmdStack *pStack) {
    _pStack = pStack;
}

void server::TcpServer::onMessageToSend(QString message, int id){
    auto client = _socketList[id];
    if(client){
        client->write(message.toLatin1());
    }else{
        qDebug("TcpServer : Received invalid client id\n");
    }
}

server::TcpServer::~TcpServer() {
    delete _pMapper;
    delete _pServer;
}


