//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_JSONLOCALDATABASE_H
#define UDP_SERVER_JIVE_JSONLOCALDATABASE_H

#include <QMap>
#include "IDataBaseConnector.h"
#include "IJsonLookupDataBase.h"
#include "ISipLookup.h"
#include <QJsonObject>

namespace dbconnector {
    class JsonLocalDataBase : public IJsonLookupDataBase, public IDataBaseConnector, public ISipLookup  {
    public:
        JsonLocalDataBase();
        ~JsonLocalDataBase();
        /**
         * Method does not do anything
         * @return Always return true
         */
        bool initConnection() override;

        /**
         * Method does not do anything
         * @return Always return true
         */
        bool terminateConnection() override;

        /**
         * Initializes the map from the specified JSON file
         * @param fileName The name of the JSON file
         * @return True if no error happened
         */
        bool createFromJsonFile(QString fileName) override;

        /**
        * Method lookup the SIP element from the lookupId
        * @param lookupId The "addressOfRecord" element used to lookup the request
        * @return Return the JSON element if found or "{}" otherwise
        */
        QString lookupFromId(QString lookupId) override;
    private:
        QMap<QString,QString> _textDb;

        static const QString ADDR_KEY;

        /**
         * Finds the youngest record according to the "created" field.
         * @param req1 The record1
         * @param req2 The record2
         * @return The youngest record. If both are equal. Record 2 is returned.
         */
        QJsonObject getYoungestRequest(const QJsonObject &req1, const QJsonObject &req2);
    };
}


#endif //UDP_SERVER_JIVE_JSONLOCALDATABASE_H
