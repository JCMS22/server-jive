#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "DataBaseConnector/JsonLocalDataBase.h"
#include "Server/TcpServer.h"
#include "Server/ServerTypes.h"
#include <QFile>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QFile file("./JSON/registrations.json");

    dbconnector::JsonLocalDataBase jldb;
    if(jldb.createFromJsonFile("./JSON/registrations.json")) {
        QString res = jldb.lookupFromId("0146a51532d4fdb52d000100620002");
        qDebug(res.toLatin1());
    }else{

    }

    server::TcpServer tcpServer(&jldb);
    server::sServerConfig config;
    config.timeoutMs = 10000;
    config.port = 6969;
    tcpServer.open(config);

    return a.exec();
}

/*int main() {
    std::cout << "Hello, World!" << std::endl;
    nlohmann::json  j;
    QFile file("./JSON/registrations.json");


    dbconnector::JsonLocalDataBase db;
    db.createFromJson(j);
    return 0;
}*/