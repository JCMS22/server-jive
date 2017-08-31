//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_IJSONLOOKUPDATABASE_H
#define UDP_SERVER_JIVE_IJSONLOOKUPDATABASE_H

#include <string>

namespace dbconnector {

    class IJsonLookupDataBase {
    public:
        virtual bool createFromJsonFile(QString fileName) =0;

        virtual QString lookupFromId(QString lookupId) =0;

    };
}


#endif //UDP_SERVER_JIVE_IJSONLOOKUPDATABASE_H
