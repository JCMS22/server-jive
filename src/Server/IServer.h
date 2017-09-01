//
// Created by Jean-Christophe Lavoie on 2017-08-30.
//

#ifndef UDP_SERVER_JIVE_ISERVER_H
#define UDP_SERVER_JIVE_ISERVER_H

#include <sstream>
#include <QTime>
#include "ServerTypes.h"
#include "../CommandProcessor/ICmdStack.h"

namespace server {
    class IServer {
    public:

        /**
         * Open a server with the specific configuration
         * @param config Configuration of the server to open
         */
        virtual void open(sServerConfig config)=0;
        /**
         * Closes the server connection
         */
        virtual void terminate()=0;
        /**
         * Set the stack to which push commands
         * @param pStack The pointer to the stack
         */
        virtual void setCmdStack(cmdprocessor::ICmdStack* pStack)=0;
    };


}


#endif //UDP_SERVER_JIVE_ISERVER_H
