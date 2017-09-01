//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "JsonLocalDataBase.h"
#include <QDebug>
#include <QDate>

namespace dbconnector {
    const QString JsonLocalDataBase::ADDR_KEY("addressOfRecord");

    bool JsonLocalDataBase::initConnection() {
        return true;
    }

    bool JsonLocalDataBase::terminateConnection() {
        return true;
    }

    bool JsonLocalDataBase::createFromJsonFile(QString fileName) {
        /* Parse the file and consider each line as JSON record */
        QFile file(fileName);
        bool res = file.open(QIODevice::ReadOnly);
        if (res) {
            /* Add each line in the map */
            QString line = file.readLine();
            while (line.size() > 0) {
                QJsonObject jdoc = QJsonDocument::fromJson(line.toLatin1()).object();
                if (jdoc.size() == 0) {
                    qDebug("Error parsing json file\n");
                    res = false;
                    break;
                } else {
                    /*Build a map of the json record */
                    QString key = jdoc.value(ADDR_KEY).toString();
                    /* Check if we have already stored the key. If we did, we keep the youngest request */

                    if (_textDb.contains(key)) {
                        QJsonObject oldObj = QJsonDocument::fromJson(_textDb[key].toLatin1()).object();
                        auto result = getYoungestRequest(jdoc, oldObj);
                        if (result == jdoc) {
                            _textDb[key] = line;
                        } else {
                            /*keep old one*/
                        }
                    } else {
                        _textDb[key] = line;
                    }
                    line = file.readLine();
                }
            }
            file.close();
        } else {
            qDebug() << "Failed to open file : " << fileName;
        }
        return res;
    }
    QString JsonLocalDataBase::lookupFromId(QString lookupId) {
        return this->_textDb[lookupId];
    }

    JsonLocalDataBase::JsonLocalDataBase() {

    }

    JsonLocalDataBase::~JsonLocalDataBase() {

    }

    QJsonObject JsonLocalDataBase::getYoungestRequest(const QJsonObject &req1, const QJsonObject &req2) {
        /* There is probably a cleaner way to do this.
         * We should be able to parse the whole string using ISO or RFC format
         * */
        QJsonObject returnValue;
        auto str1 = req1["created"].toString().split("T")[0];
        auto str2 = req2["created"].toString().split("T")[0];

        QDate date1 = QDate::fromString(str1,"yyyy'-'MM'-'dd" );
        QDate date2 = QDate::fromString(str2, "yyyy'-'MM'-'dd");

        if (date1 > date2) {
            returnValue = req1;

        } else if (date1 == date2) {
            auto hours1 = req1["created"].toString().split("T")[1].split("Z")[0];
            QTime time1;
            time1.setHMS(hours1.split(":")[0].toInt(),
                         hours1.split(":")[1].toInt(),
                         hours1.split(":")[2].split(".")[0].toInt(),
                         hours1.split(".")[1].toInt()
            );
            auto hours2 = req2["created"].toString().split("T")[1].split("Z")[0];
            QTime time2;
            time2.setHMS(hours2.split(":")[0].toInt(),
                         hours2.split(":")[1].toInt(),
                         hours2.split(":")[2].split(".")[0].toInt(),
                         hours2.split(".")[1].toInt()
            );
            if (time1 > time2) {

                returnValue = req1;
            } else {
                returnValue = req2;
            }
        } else {
            returnValue = req2;
        }

        return returnValue;
    }

}