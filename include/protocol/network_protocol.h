

#ifndef WSN_NETWORK_PROTOCOL_H
#define WSN_NETWORK_PROTOCOL_H


#include <vector>
#include <queue>
#include <memory>

#include "../model/data/data.h"
#include "../model/data/command.h"
#include "../core/wsn_component.h"
#include "../model/nodes.h"

namespace wsn {

    namespace model {
        //forward declaration to wsn::model::Node
        class Node;
        class NodeLink;


    }

    namespace protocol {

        namespace network {



            using model::Data;
            using model::Node;
            using model::NodeLink;

            typedef std::vector<NodeLink> Links;
            typedef std::vector<wsn::model::Command> Commands;
            typedef std::deque<wsn::model::Data> DataList;




            class NetworkProtocol : public wsn::core::WSNComponent {



            public:


                explicit NetworkProtocol(wsn::model::NodesPtr nodesPtr) : nodes(nodesPtr) {}
                virtual ~NetworkProtocol() = default;

                virtual void update() = 0;


            protected:
                wsn::model::NodesPtr nodes;


                bool sendData(const Data &data, Node &sender, Node &receiver) const {
                    return sender.sendData(data, receiver);
                }

                bool receiveData(const Data &data, Node &receiver) const {
                    return receiver.receiveData(data);
                }


                bool addLink(Node &node, const wsn::model::NodeLink &link) {
                    return node.addLink(link);
                }

                void removeLink(Node &node, unsigned long position) {
                    return node.removeLink(position);
                }


            };



        }
    }
}



#endif //WSN_NETWORK_PROTOCOL_H
