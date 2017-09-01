//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#include "ServerCmdCallback.h"

void server::ServerCmdCallback::callback(QString response, int id) {
        emit sendMessage(response,id);

}

