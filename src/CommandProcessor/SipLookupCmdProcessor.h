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
            ~SipLookupCmdProcessor();

            /**
             * Push a command to the Processor. Signal is send to process the command
             * @param cmd The command to execute
             * @param id The ID of the command
             * @param pCallback The callback to which send the response
             */
            void push(QString cmd, int id, ICmdResponseCallback *pCallback) override;

            /**
             * Processes the command and return the answer
             * @param cmd The command to execute
             * @return The response to the command
             */
            QString processCmd(QString cmd) override;

           signals:
            /**
             * Signal sent when when push is called
             * @param cmd The command to execute
             * @param id The ID of the command
             * @param pCallback The callback to which send the response
             */
                void  sendCmdSignal(QString cmd, int id, ICmdResponseCallback* pCallback);
           public slots:
            /**
             * Slot that receives the command to execute. Will send  the answer through the callback
             * @param cmd The command to execute
             * @param id The ID of the command
             * @param pCallback The callback to which send the response
             */
                void receiveCmdSignal(QString cmd, int id, ICmdResponseCallback* pCallback);


        private:
            /**
             * Interface to the lookup database
             */
            dbconnector::ISipLookup *_pLookup;


        };

}


#endif //UDP_SERVER_JIVE_CMDSTACK_H
