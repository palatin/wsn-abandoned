

#include "node.h"


namespace wsn {

    namespace model {


        Node::Node(unsigned long id, Point location, double energy, float memoryLimit) : id(id), location(location), energy(energy), memoryLimit(memoryLimit) {

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
            if(this->energy < 0) {
                //TODO notify about dead
            }
        }

        bool Node::addLink(NodeLink link) {
            if(!canStore(NODE_LINK_MEMORY))
                return false;
            this->links.push_back(link);
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
            return dataSize + currentMemory < memoryLimit;
        }

        const std::vector<wsn::model::Command> &Node::getCommands() const{
            return commands;
        }

        const std::deque<wsn::model::Data> &Node::getData() const {
            return dataDeque;
        }

    }

}