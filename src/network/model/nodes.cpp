
#include "nodes.h"



wsn::model::Nodes::~Nodes() {
    delete &nodes;
}

wsn::model::Node &wsn::model::Nodes::getNodeById(unsigned long id) {

    return  *nodes.at(id);
}

unsigned long wsn::model::Nodes::nodeCounts() {
    return nodes.size();
}


