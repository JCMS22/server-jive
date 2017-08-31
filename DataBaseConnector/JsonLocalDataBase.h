//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_JSONLOCALDATABASE_H
#define UDP_SERVER_JIVE_JSONLOCALDATABASE_H

#include <QMap>
#include "IDataBaseConnector.h"
#include "IJsonLookupDataBase.h"

namespace dbconnector {
    class JsonLocalDataBase : public IJsonLookupDataBase, public IDataBaseConnector  {
    public:
        bool initConnection() override;

        bool terminateConnection() override;

        bool createFromJsonFile(QString fileName) override;

        QString lookupFromId(QString lookupId) override;
    private:
        QMap<QString,QString> _textDb;
        static const QString ADDR_KEY;
    };
}


#endif //UDP_SERVER_JIVE_JSONLOCALDATABASE_H
