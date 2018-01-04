
#include "nodes.h"



wsn::model::Node *wsn::model::Nodes::getNodeById(unsigned int id) {
    //TODO
    return nodes.at(id);
}

unsigned long wsn::model::Nodes::nodeCounts() {
    return nodes.size();
}
