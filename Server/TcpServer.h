//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_TCPSERVER_H
#define UDP_SERVER_JIVE_TCPSERVER_H

#include "IServer.h"
#include "../DataBaseConnector/IJsonLookupDataBase.h"
#include <QTcpServer>
#include <QTimer>

namespace server {

    class TcpServer :  public QObject, public IServer {
    Q_OBJECT
    public:
        TcpServer(dbconnector::IJsonLookupDataBase* callback);
        void open(sServerConfig config) override;
        void terminate() override;
        void setCmdStack(cmdprocessor::ICmdStack *pStack) override;


    public slots:
        void connected();
        void onData();
        void onTimerElapsed();


    private:
        dbconnector::IJsonLookupDataBase* _pCallback;
        QTcpServer* _pServer;
        QTcpSocket* _pSocket;
        QTimer      _timer;
        int _currTimerId;
        int _timeout;



        cmdprocessor::ICmdStack *_pStack;
    };
}


#endif //UDP_SERVER_JIVE_TCPSERVER_H
