
#include "nodes.h"



wsn::model::Nodes::Nodes(std::vector<std::unique_ptr<wsn::model::Node>> &nodes) : nodes(std::move(nodes)) {

}

wsn::model::Nodes::~Nodes() {
}

wsn::model::Node &wsn::model::Nodes::getNodeById(unsigned long id) {
    return *nodes.at(id);
}

unsigned long wsn::model::Nodes::nodeCounts() {
    return nodes.size();
}


void wsn::model::Nodes::addNode(std::unique_ptr<wsn::model::Node> node) {
    nodes.push_back(std::move(node));
}

wsn::model::Node &wsn::model::Nodes::at(unsigned long number) {
    return *nodes.at(number);
}

const wsn::model::Node &wsn::model::Nodes::at(unsigned long number) const {
    return *nodes.at(number);;
}








