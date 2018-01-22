

#include "node.h"


namespace wsn {

    namespace model {


        Node::Node(unsigned long id, Point location, float energy, double memoryLimit) : id(id), location(location), energy(energy), memoryLimit(memoryLimit) {

        }

        Node::~Node() {

        }

        unsigned long Node::getID() const {
            return id;
        }

        float Node::getEnergy() const {
            return energy;
        }

        Point Node::getPoint() const {
            return location;
        }

        double Node::getMemoryLimit() const {
            return memoryLimit;
        }

        double Node::getCurrentMemory() const {
            return currentMemory;
        }

        bool Node::addLink(NodeLink link) {
            if(!canStore(NODE_LINK_MEMORY))
                return false;
            this->links.push_back(link);
        }



        bool Node::receiveData(const Data &data) const {
            return this->processData(data);
        }


        bool Node::processData(const Data &data) const {

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