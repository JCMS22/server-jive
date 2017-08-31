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

        virtual void open(sServerConfig config)=0;
        virtual void terminate()=0;
        virtual void setCmdStack(cmdprocessor::ICmdStack* pStack)=0;
    };


}


#endif //UDP_SERVER_JIVE_ISERVER_H
