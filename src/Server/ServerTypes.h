//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_SERVERTYPES_H
#define UDP_SERVER_JIVE_SERVERTYPES_H

#include <cstdint>
namespace server {
    enum eServerType {
        TCP,
        /*
        UDP,
        WebSocket,
        ...*/
    };
    struct sServerConfig {
        eServerType serverType;
        uint16_t timeoutMs;
        uint16_t port;
    };
}



#endif //UDP_SERVER_JIVE_SERVERTYPES_H


