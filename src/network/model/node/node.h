

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

        typedef std::vector<NodeLink> Links;
        typedef std::vector<wsn::model::Command> Commands;
        typedef std::deque<wsn::model::Data> DataList;

        class Node {

        public:
            //NodeType  type;

            Node(unsigned long id, Point location, double energy, float memoryLimit);
            Node(Node &&node) noexcept;
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
            Links links;
            std::deque<wsn::model::Data> dataDeque;
            std::vector<wsn::model::Command> commands;
            const float memoryLimit;
            float currentMemory = 0;

            Node(Node &node);
            Node& operator=(Node &node);
            bool addLink(const NodeLink &link);
            const Links& getLinks() const;
            void removeLink(unsigned long position);
            const DataList& getData() const;
            const Commands& getCommands() const;
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
