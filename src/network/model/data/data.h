
#ifndef WSN_DATA_H
#define WSN_DATA_H


#include "../node/node.h"

namespace wsn {

    namespace model {

        class Data {

        public:
            double getDataLength() const;


        private:
            double bytes;
            const Node *sender;
            const Node *receiver;


        };



    }

}

#endif //WSN_DATA_H
