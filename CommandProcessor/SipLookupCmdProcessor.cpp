//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#include "SipLookupCmdProcessor.h"


cmdprocessor::SipLookupCmdProcessor::SipLookupCmdProcessor(dbconnector::ISipLookup *pLookup) : _pLookup(pLookup) {

}

void cmdprocessor::SipLookupCmdProcessor::push(QString cmd) {
    _cmdList.push_back(cmd);
}

void cmdprocessor::SipLookupCmdProcessor::process() {
    for(QString cmd : _cmdList ){
        QString res = processCmd(cmd);
    }

}

QString cmdprocessor::SipLookupCmdProcessor::processCmd(QString cmd) {
    QString res =_pLookup->lookupFromId(cmd);
    if(res.length() == 0){
        res = "{}";
    }
    return res;
}



