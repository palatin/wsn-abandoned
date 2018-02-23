
#ifndef WSN_SINK_H
#define WSN_SINK_H

#include "node.h"

namespace wsn {

    namespace model {

        class Sink : public Node {


        public:
            Sink(unsigned long id, const Point &location);
            ~Sink() = default;

        private:
            bool sendData(const Data &data, const Node &receiver) override;

            bool receiveData(const Data &data) override;

            //bool receiveData(const Data &data);


        };

    }
}

#endif //WSN_SINK_H
