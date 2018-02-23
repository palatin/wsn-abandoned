

#ifndef WSN_NODE_H
#define WSN_NODE_H



#include "../point.h"

#include <vector>
#include <queue>
#include <memory>



#include "../../notification/notification_center.h"


#include "node_link.h"
#include "../data/data.h"

#include "../data/command.h"




namespace wsn {

    namespace protocol {
        namespace  network {
            class NetworkProtocol;
        }
    }



    namespace model {

        class Transmitter;



        typedef std::unique_ptr<Transmitter> TransmitterPtr;
        typedef std::vector<NodeLink> Links;
        typedef std::vector<wsn::model::Command> Commands;
        typedef std::deque<wsn::model::Data> DataList;


        class Node {

        public:
            //NodeType  type;

            Node(unsigned long id, Point location, double energy, float memoryLimit, TransmitterPtr transmitter);
            Node(Node &&node) noexcept;

            virtual ~Node() = default;

            unsigned long getID() const;
            Point getLocation() const;
            double getEnergy() const;
            float getMemoryLimit() const;
            float getCurrentMemory() const;
            bool isAlive() const;
            Links getLinks() const;
            DataList getData() const;
            Commands getCommands() const;

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
            bool alive = true;
            const TransmitterPtr transmitter;
            wsn::notification::NotificationCenter &notificationCenter = wsn::notification::NotificationCenter::getInstance();

            bool addLink(const NodeLink &link);
            void removeLink(unsigned long position);
            virtual bool sendData(const Data &data, const Node &receiver);
            virtual bool receiveData(const Data &data);
            bool processData(const Data &data);
            bool canStore(double dataSize) const;
            void setEnergy(double energy);
            void killNode();
            bool spendEnergy(double energy);


            friend class wsn::protocol::network::NetworkProtocol;

            friend class Transmitter;


        };



    }
}

#endif //WSN_NODE_H
