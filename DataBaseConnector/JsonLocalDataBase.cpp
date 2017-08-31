//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "JsonLocalDataBase.h"

namespace dbconnector {
    const QString JsonLocalDataBase::ADDR_KEY("addressOfRecord");

    bool JsonLocalDataBase::initConnection(){
        return true;
    }

    bool JsonLocalDataBase::terminateConnection(){
        return true;
    }

    bool JsonLocalDataBase::createFromJsonFile(QString fileName){
        QFile file(fileName);
        bool res  = file.open(QIODevice::ReadOnly);
        if(res){
            QString line = file.readLine();
            while(line.size() > 0){
              QJsonObject jdoc =  QJsonDocument::fromJson(line.toLatin1()).object();
                if(jdoc.size() == 0){
                    qDebug("Error parsing json file\n");
                    res = false;
                    break;
                }else{
                   QString key = jdoc.value(ADDR_KEY).toString();
                    this->_textDb.insert(key,line);
                }
                line = file.readLine();
            }
            file.close();
        }else{
            qDebug("Failed to open file :" + fileName.toLatin1());
        }
        return res;
    }

    QString JsonLocalDataBase::lookupFromId(QString lookupId){
        return this->_textDb[lookupId];
    }


}