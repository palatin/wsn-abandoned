

#ifndef WSN_NODE_H
#define WSN_NODE_H



#include "../point.h"

#include <vector>
#include <queue>

#include "node_link.h"
#include "../data/data.h"
#include "../../protocol/network_protocol.h"
#include "../data/command.h"


namespace wsn {

    namespace model {



        class Node {

        public:
            //NodeType  type;

            Node(unsigned long id, Point location, float energy, double memoryLimit);
            ~Node();

            unsigned long getID() const;
            Point getPoint() const;
            float getEnergy() const;
            double getMemoryLimit() const;
            double getCurrentMemory() const;


            //void step(long time);
            inline bool operator==(const Node &node) const {
                return this->id == node.id;
            }



        private:
            unsigned long id = 0;
            Point location;
            float energy = 0;
            std::vector<NodeLink> links;
            mutable std::deque<wsn::model::Data> dataDeque;
            mutable std::vector<wsn::model::Command> commands;
            //memory that node can store in bytes
            double memoryLimit = 0;
            mutable double currentMemory = 0;


            bool addLink(NodeLink link);
            //bool sendData(const Data &data, Node *receiver) const;
            const std::deque<wsn::model::Data>& getData() const;
            const std::vector<wsn::model::Command>& getCommands() const;
            bool receiveData(const Data &data) const;
            bool processData(const Data &data) const;
            bool canStore(double dataSize) const;

            friend wsn::protocol::network::NetworkProtocol;


        };

    }
}

#endif //WSN_NODE_H
