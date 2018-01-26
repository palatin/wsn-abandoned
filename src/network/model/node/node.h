

#ifndef WSN_NODE_H
#define WSN_NODE_H



#include "../point.h"

#include <vector>
#include <queue>

#include "node_link.h"
#include "../data/data.h"

#include "../data/command.h"


namespace wsn {

    namespace protocol {
        namespace  network {
            template <class NodeType>
            class NetworkProtocol;
        }
    }

    namespace controller {
        namespace  physics {
            template <class NodeType>
            class PhysicsController;
        }
    }


    namespace model {



        class Node {

        public:
            //NodeType  type;

            Node(unsigned long id, Point location, double energy, float memoryLimit);
            ~Node();

            unsigned long getID() const;
            Point getLocation() const;
            double getEnergy() const;
            float getMemoryLimit() const;
            float getCurrentMemory() const;


            inline bool operator==(const Node &node) const {
                return this->id == node.id;
            }



        private:
            unsigned long id = 0;
            const Point location;
            double energy = 0;
            std::vector<NodeLink> links;
            std::deque<wsn::model::Data> dataDeque;
            std::vector<wsn::model::Command> commands;
            //memory that node can store in bytes
            const float memoryLimit;
            float currentMemory = 0;
            bool addLink(NodeLink link);
            //bool sendData(const Data &data, Node *receiver) const;
            const std::deque<wsn::model::Data>& getData() const;
            const std::vector<wsn::model::Command>& getCommands() const;
            bool receiveData(const Data &data);
            bool processData(const Data &data);
            bool canStore(double dataSize) const;
            void setEnergy(double energy);


            template <typename NodeType>
            friend class wsn::protocol::network::NetworkProtocol;

            template <typename NodeType>
            friend class wsn::controller::physics::PhysicsController;


        };

    }
}

#endif //WSN_NODE_H
