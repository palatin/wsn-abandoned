

#ifndef WSN_NODELINK_H
#define WSN_NODELINK_H

#define NODE_LINK_MEMORY 10

namespace wsn {

    namespace model {

        //forward-declarations
        class Node;

        struct NodeLink {

            NodeLink(Node* link, float distance);

            Node *link;
            float distance;


            inline bool operator==(const NodeLink &nodeLink) const {
                return this->link == nodeLink.link;
            }
        };
    }
}

#endif //WSN_NODELINK_H
