//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#ifndef UDP_SERVER_JIVE_CMDSTACK_H
#define UDP_SERVER_JIVE_CMDSTACK_H

#include <QVector>
#include "ICmdStack.h"
#include "../DataBaseConnector/ISipLookup.h"

namespace cmdprocessor{
        class SipLookupCmdProcessor : public ICmdStack {
        public :

            SipLookupCmdProcessor(dbconnector::ISipLookup *pLookup);

            void push(QString cmd) override;

            void process();

            QString processCmd(QString cmd) override;

        private:
            QVector<QString> _cmdList;
            dbconnector::ISipLookup *_pLookup;

        };

}


#endif //UDP_SERVER_JIVE_CMDSTACK_H
