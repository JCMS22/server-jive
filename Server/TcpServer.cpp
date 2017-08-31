//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#include <QCoreApplication>
#include "TcpServer.h"
#include <QTcpSocket>


server::TcpServer::TcpServer(dbconnector::IJsonLookupDataBase* callback) : _currTimerId(0),
                                                                          _timeout(0), _pCallback(callback) {

}
void server::TcpServer::open(sServerConfig config) {
    _pServer = new QTcpServer();
    _timeout = config.timeoutMs;
    bool res = _pServer->listen(QHostAddress::LocalHost, config.port);
    if(!res){
        qDebug("Error opening TCP server\n");
        terminate();
    }else {
        this->_currTimerId = this->startTimer(_timeout);
        qDebug("Tcp Server running on port : " + config.port);
        connect(_pServer,SIGNAL(newConnection()),this, SLOT(connected()));
    }



}

void server::TcpServer::terminate() {
    _pServer->close();
    QCoreApplication::exit();
}






void server::TcpServer::timerEvent(QTimerEvent *event) {
        QObject::timerEvent(event);
        qDebug("No request has been received for 10s, bye!\n");
        this->killTimer(this->_currTimerId);
        this->terminate();
    }

void server::TcpServer::connected() {
    this->killTimer(_currTimerId);
    qDebug("Received new connection\n");
    while (_pServer->hasPendingConnections())
    {
        _pSocket = _pServer->nextPendingConnection();
        connect(_pSocket, SIGNAL(readyRead()), SLOT(onData()));

    }
    _currTimerId = this->startTimer(_timeout);

}


void server::TcpServer::onData() {
    QString bitch("hello biatch");
    QByteArray message = _pSocket->readAll();
    QString strMsg(message);
    QString response = _pCallback->lookupFromId(strMsg);
    _pSocket->write(response.toLatin1());

}


