//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_TCPSERVER_H
#define UDP_SERVER_JIVE_TCPSERVER_H

#include "IServer.h"
#include "../DataBaseConnector/IJsonLookupDataBase.h"
#include <QTcpServer>
namespace server {

    class TcpServer :  public QObject, public IServer {
    Q_OBJECT
    public:
        TcpServer(dbconnector::IJsonLookupDataBase* callback);
        void open(sServerConfig config) override;
        void terminate() override;


    public slots:
        void connected();
        void onData();
    protected:
        void timerEvent(QTimerEvent *event) override;


    private:
        dbconnector::IJsonLookupDataBase* _pCallback;
        QTcpServer* _pServer;
        QTcpSocket* _pSocket;
        int _currTimerId;
        int _timeout;
    };
}


#endif //UDP_SERVER_JIVE_TCPSERVER_H
