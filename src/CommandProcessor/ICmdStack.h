//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#include <QString>
#include "ICmdResponseCallback.h"

#ifndef UDP_SERVER_JIVE_ICMDPROCESSOR_H
#define UDP_SERVER_JIVE_ICMDPROCESSOR_H



namespace cmdprocessor{
    class ICmdStack {
    public:
        /**
         * Push the request to the stack and immediatly return
         * @param cmd The command to execute
         * @param id The ID of the command
         * @param pCallback The callback to whom send the response
         */
        virtual void push(QString cmd, int id, ICmdResponseCallback *pCallback) = 0;

        /**
         * Execute the command and return with the answer
         * @param cmd The command to execute
         * @return The response of the command
         */
        virtual QString processCmd(QString cmd)=0;
    };
}

#endif //UDP_SERVER_JIVE_ICMDPROCESSOR_H