//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_IDATABASECONNECTOR_H
#define UDP_SERVER_JIVE_IDATABASECONNECTOR_H

#include <string>

namespace dbconnector {

    class IDataBaseConnector {
    public:
        virtual bool initConnection() = 0;

        virtual bool terminateConnection() = 0;

    };
}


#endif //UDP_SERVER_JIVE_IDATABASECONNECTOR_H
