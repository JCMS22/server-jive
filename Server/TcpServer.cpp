//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#include <QCoreApplication>
#include "TcpServer.h"
#include <QTcpSocket>


server::TcpServer::TcpServer(dbconnector::IJsonLookupDataBase* callback) : _currTimerId(0),
                                                                          _timeout(0), _pCallback(callback),_pStack(nullptr) {

}
void server::TcpServer::open(sServerConfig config) {
    _pServer = new QTcpServer();
    bool res = _pServer->listen(QHostAddress::LocalHost, config.port);
    if(!res){
        qDebug("Error opening TCP server\n");
        terminate();
    }else {
        /* Register connection callback and timeout timer */
        connect(_pServer,SIGNAL(newConnection()),this, SLOT(connected()));
        connect(&_timer,SIGNAL(timeout()),this, SLOT(onTimerElapsed()));
        _timer.setInterval(config.timeoutMs);
        _timer.start(config.timeoutMs);
        qDebug("Tcp Server running");

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
        _pSocket = _pServer->nextPendingConnection();
        connect(_pSocket, SIGNAL(readyRead()), SLOT(onData()));

    }
    _timer.start();

}


void server::TcpServer::onData() {
    _timer.stop();
    QByteArray message = _pSocket->readAll();
    QString cmd(message);
    if(_pStack){
        QString res = _pStack->processCmd(cmd);
        _pSocket->write(res.toLatin1());
    }else{
        /* Nothing to do */
    }
    _timer.start();

}

void server::TcpServer::onTimerElapsed() {
    terminate();

}

void server::TcpServer::setCmdStack(cmdprocessor::ICmdStack *pStack) {
    _pStack = pStack;
}


