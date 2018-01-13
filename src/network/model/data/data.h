
#ifndef WSN_DATA_H
#define WSN_DATA_H


#include "../node/node.h"

namespace wsn {

    namespace model {

        class Data {

        public:
            double getDataLength();


        private:
            double bytes;
            const Node *sender;
            const Node *receiver;


        };

        double Data::getDataLength() {
            return bytes;
        }


    }

}

#endif //WSN_DATA_H
