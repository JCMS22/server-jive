//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#include <QString>

#ifndef UDP_SERVER_JIVE_ICMDPROCESSOR_H
#define UDP_SERVER_JIVE_ICMDPROCESSOR_H



namespace cmdprocessor{
    class ICmdStack {
    public:
        virtual void push(QString cmd) = 0;
        virtual QString processCmd(QString cmd)=0;
    };
}

#endif //UDP_SERVER_JIVE_ICMDPROCESSOR_H