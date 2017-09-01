//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_IJSONLOOKUPDATABASE_H
#define UDP_SERVER_JIVE_IJSONLOOKUPDATABASE_H

#include <string>

namespace dbconnector {

    class IJsonLookupDataBase {
    public:
        /**
         * Initializes the DataBase from a JSON file
         * @param fileName The name of the JSON file
         * @return True if the file was sucessfully parsed and the database created
         */
        virtual bool createFromJsonFile(QString fileName) =0;

    };
}


#endif //UDP_SERVER_JIVE_IJSONLOOKUPDATABASE_H
