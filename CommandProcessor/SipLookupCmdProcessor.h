//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#ifndef UDP_SERVER_JIVE_CMDSTACK_H
#define UDP_SERVER_JIVE_CMDSTACK_H

#include <QVector>
#include <QtCore>
#include "ICmdStack.h"
#include "../DataBaseConnector/ISipLookup.h"
#include "ICmdResponseCallback.h"

namespace cmdprocessor{
        class SipLookupCmdProcessor : public  QObject, public ICmdStack {
            Q_OBJECT
        public :

            SipLookupCmdProcessor(dbconnector::ISipLookup *pLookup);

            void push(QString cmd, int id, ICmdResponseCallback *pCallback) override;

            void process();

            QString processCmd(QString cmd) override;

           signals:
                void  sendCmdSignal(QString cmd, int id, ICmdResponseCallback* pCallback);
           public slots:
                void receiveCmdSignal(QString cmd, int id, ICmdResponseCallback* pCallback);


        private:
            dbconnector::ISipLookup *_pLookup;


        };

}


#endif //UDP_SERVER_JIVE_CMDSTACK_H
