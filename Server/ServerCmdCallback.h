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
        /**
         * Receives response and send the signal that the message is ready
         * @param response The response to send
         * @param id ID of the executed command
         */
        void callback(QString response, int id) override;
        signals:
        /**
         * Signal sent to notify that the message is ready
         * @param response The response to send
         * @param id ID of the executed command
         */
        void sendMessage(QString response, int id);
    };
}


#endif //UDP_SERVER_JIVE_SERVERCMDCALLBACK_H
