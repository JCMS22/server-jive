#include <iostream>
#include "DataBaseConnector/JsonLocalDataBase.h"
#include "Server/TcpServer.h"
#include "CommandProcessor/SipLookupCmdProcessor.h"
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    dbconnector::JsonLocalDataBase jldb;
    if(!jldb.createFromJsonFile("./JSON/registrations.json")) {
        qDebug("Failed to load database file");
    }else{

    }

    /* Initialize server and database */
    server::TcpServer tcpServer(&jldb);
    tcpServer.setCmdStack(new cmdprocessor::SipLookupCmdProcessor(&jldb));
    server::sServerConfig config;
    config.timeoutMs = 10000;
    config.port = 6969;
    tcpServer.open(config);

    return a.exec();
}
