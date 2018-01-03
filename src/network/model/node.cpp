//
// Created by Игорь on 30.12.2017.
//

#include "node.h"


namespace wsn {

    namespace model {

        Node::~Node() {

            delete location;
            delete link;
        }
    }

}