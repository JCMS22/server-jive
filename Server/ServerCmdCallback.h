//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#ifndef UDP_SERVER_JIVE_SERVERCMDCALLBACK_H
#define UDP_SERVER_JIVE_SERVERCMDCALLBACK_H

#include <QObject>
#include "../CommandProcessor/ICmdResponseCallback.h"

namespace server {
    class ServerCmdCallback : public QObject, public cmdprocessor::ICmdResponseCallback {
        Q_OBJECT
    public:
        void callback(QString response, int id) override;
        signals:
        void sendMessage(QString response, int id);
    };
}


#endif //UDP_SERVER_JIVE_SERVERCMDCALLBACK_H
