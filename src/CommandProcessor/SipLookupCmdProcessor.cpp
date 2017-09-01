//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//


#include "SipLookupCmdProcessor.h"
#include "ICmdResponseCallback.h"


cmdprocessor::SipLookupCmdProcessor::SipLookupCmdProcessor(dbconnector::ISipLookup *pLookup) : _pLookup(pLookup) {
    /* Use Queue connection as we want to behave as only a push method */
    connect(this,SIGNAL(sendCmdSignal(QString,int,ICmdResponseCallback*)),this,
            SLOT(receiveCmdSignal(QString,int,ICmdResponseCallback*)), Qt::QueuedConnection);
}

void cmdprocessor::SipLookupCmdProcessor::push(QString cmd, int id, ICmdResponseCallback *pCallback) {
   emit sendCmdSignal(cmd,id,pCallback);
}

QString cmdprocessor::SipLookupCmdProcessor::processCmd(QString cmd) {
    QString res =_pLookup->lookupFromId(cmd);
    if(res.length() == 0){
        res = "\n";
    }
    return res;
}

void cmdprocessor::SipLookupCmdProcessor::receiveCmdSignal(QString cmd, int id,
                                                           cmdprocessor::ICmdResponseCallback *pCallback) {
    auto response = processCmd(cmd);
    pCallback->callback(response,id);

}

cmdprocessor::SipLookupCmdProcessor::~SipLookupCmdProcessor() {

}



