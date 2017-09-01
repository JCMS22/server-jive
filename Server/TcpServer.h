//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_TCPSERVER_H
#define UDP_SERVER_JIVE_TCPSERVER_H

#include "IServer.h"
#include "../DataBaseConnector/IJsonLookupDataBase.h"
#include "ServerCmdCallback.h"
#include <QTcpServer>
#include <QTimer>
#include <QSignalMapper>

namespace server {

    class TcpServer :  public QObject, public IServer {
    Q_OBJECT
    public:
        TcpServer(dbconnector::IJsonLookupDataBase* callback);
        /**
         * Open the server with the specified config
         * @param config Configuration of the server
         */
        void open(sServerConfig config) override;
        /**
         * Terminate the server connection
         */
        void terminate() override;
        /**
         * Sets the stack to push commands
         * @param pStack The pointer to the stack
         */
        void setCmdStack(cmdprocessor::ICmdStack *pStack) override;


    public slots:
        /**
         * Slot receiving the connected event
         */
        void connected();
        /**
         * Slot receiving data from a client
         * @param clientId ID of the client
         */
        void onData(int clientId);
        /**
         *
         */
        void onTimerElapsed();
        void onMessageToSend(QString message, int id);


    private:
        dbconnector::IJsonLookupDataBase* _pCallback;
        QTcpServer* _pServer;
        QVector<QTcpSocket*> _socketList;
        QSignalMapper* _pMapper;
        QTimer      _timer;
        int _currTimerId;
        int _timeout;
        cmdprocessor::ICmdStack *_pStack;
        ServerCmdCallback _myCallback;


    };
}


#endif //UDP_SERVER_JIVE_TCPSERVER_H
