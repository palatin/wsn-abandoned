

#ifndef WSN_NODELINK_H
#define WSN_NODELINK_H


namespace wsn {

    namespace model {

        //forward-declarations
        class Node;

        struct NodeLink {

            Node *link;
            float distance;

        };
    }
}

#endif //WSN_NODELINK_H
