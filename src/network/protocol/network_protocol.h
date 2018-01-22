

#ifndef WSN_NETWORK_PROTOCOL_H
#define WSN_NETWORK_PROTOCOL_H


#include <vector>
#include <queue>
#include "../model/data/data.h"
#include "../model/data/command.h"

namespace wsn {

    namespace model {
        //forward declaration to wsn::model::Node
        class Node;


    }

    namespace protocol {

        namespace network {

            using model::Data;
            using model::Node;

            //class Data;

            class NetworkProtocol {

            public:
                NetworkProtocol();

                virtual void step(long time) = 0;


            protected:
                bool sendData(const Data &data, const Node *receiver) const;
                const std::vector<wsn::model::Command>& getCommands(const Node *node);
                const std::deque<wsn::model::Data>& getData(const Node *node);

                //virtual void test(const model::Node &node) = 0;

            private:
                //bool receiveData(const Data &data) const;
                //bool processData(const Data &data) const;
            };

        }
    }
}


#endif //WSN_NETWORK_PROTOCOL_H
