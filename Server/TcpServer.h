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
        ~TcpServer();
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
         * Callback for timer expiring
         */
        void onTimerElapsed();
        /**
         * Callback method that send responses to the client
         * @param message The message to send
         * @param id ID of the client
         */
        void onMessageToSend(QString message, int id);


    private:
        /** Parameters received from extern */
        dbconnector::IJsonLookupDataBase* _pCallback;
        cmdprocessor::ICmdStack *_pStack;

        /**Member parameters */
        QTcpServer* _pServer;
        QVector<QTcpSocket*> _socketList;
        QSignalMapper* _pMapper;
        QTimer      _timer;
        int _timeout;
        ServerCmdCallback _myCallback;


    };
}


#endif //UDP_SERVER_JIVE_TCPSERVER_H
