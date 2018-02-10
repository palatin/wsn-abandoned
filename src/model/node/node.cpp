

#include <notification/notification_center.h>
#include "model/node/node.h"


namespace wsn {

    namespace model {


        Node::Node(unsigned long id, Point location, double energy, float memoryLimit) : id(id), location(location), energy(energy), memoryLimit(memoryLimit) {

        }

        Node::Node(Node &&node) noexcept : location(node.location), memoryLimit(node.memoryLimit)  {
            this->energy = node.energy;
            node.energy = 0;
            this->id = node.id;
            node.id = 0;
            this->commands = std::move(node.commands);
            this->dataDeque = std::move(node.dataDeque);
            this->links = std::move(links);

        }

        Node::~Node() {

        }

        unsigned long Node::getID() const {
            return id;
        }

        double Node::getEnergy() const {
            return energy;
        }

        Point Node::getLocation() const {
            return location;
        }

        float Node::getMemoryLimit() const {
            return memoryLimit;
        }

        float Node::getCurrentMemory() const {
            return currentMemory;
        }


        void Node::setEnergy(double energy) {
            this->energy = energy;
            if(this->energy == 0) {
                killNode();
            }
        }

        bool model::Node::isAlive() const {
            return false;
        }

        void model::Node::killNode() {
            if(alive) {
                alive = false;
                notificationCenter.notify(wsn::notification::Event::NodeDeath, this);
            }
        }

        bool Node::addLink(const NodeLink &link) {
            if(!canStore(NODE_LINK_MEMORY))
                return false;
            this->links.push_back(link);
            return true;
        }




        bool Node::receiveData(const Data &data) {

            return this->processData(data);
        }


        bool Node::processData(const Data &data) {

            if(!canStore(data.getDataLength()))
                return false;

            currentMemory += data.getDataLength();
            if(auto *command = dynamic_cast<const Command*>(&data); command != nullptr && data.getReceiver() == this) {
                commands.push_back(*command);
                return true;
            }

            dataDeque.push_back(data);

            return true;
        }


        bool Node::canStore(double dataSize) const {
            return dataSize + currentMemory <= memoryLimit;
        }

        const Links& Node::getLinks() const {
            return links;
        }

        void Node::removeLink(unsigned long position) {
            links.erase(links.begin() + position);
            currentMemory -= NODE_LINK_MEMORY;
        }

        const Commands& Node::getCommands() const{
            return commands;
        }

        const DataList& Node::getData() const {
            return dataDeque;
        }



    }

}