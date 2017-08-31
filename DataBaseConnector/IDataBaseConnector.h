//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_IDATABASECONNECTOR_H
#define UDP_SERVER_JIVE_IDATABASECONNECTOR_H

#include <string>

namespace dbconnector {

    class IDataBaseConnector {
    public:
        /**
         * Initializes the database connector
         * @return True if connection was succesfull
         */
        virtual bool initConnection() = 0;

        /**
         * Terminates the connection with the database
         * @return True if no error happened during disconnection
         */
        virtual bool terminateConnection() = 0;

    };
}


#endif //UDP_SERVER_JIVE_IDATABASECONNECTOR_H
