//
// Created by Jean-Christophe Lavoie on 2017-08-31.
//

#ifndef UDP_SERVER_JIVE_ISIPLOOKUP_H
#define UDP_SERVER_JIVE_ISIPLOOKUP_H

#include <QString>

namespace dbconnector {
    class ISipLookup {
    public:
        /**
         * Method lookup the SIP element from the lookupId
         * @param lookupId The "addressOfRecord" element used to lookup the request
         * @return Return the JSON element if found or "{}" otherwise
         */
        virtual QString lookupFromId(QString lookupId) =0;
    };

}


#endif //UDP_SERVER_JIVE_ISIPLOOKUP_H
