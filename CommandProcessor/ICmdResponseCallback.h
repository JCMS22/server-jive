//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#ifndef UDP_SERVER_JIVE_ICMDRESPONSECALLBACK_H
#define UDP_SERVER_JIVE_ICMDRESPONSECALLBACK_H

#include <QString>

namespace cmdprocessor{

    class ICmdResponseCallback {
    public:
        virtual void callback(QString response, int id)= 0;

    };
}
#endif //UDP_SERVER_JIVE_ICMDRESPONSECALLBACK_H
