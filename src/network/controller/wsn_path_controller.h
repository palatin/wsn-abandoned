

#ifndef WSN_WSNPATHCONTROLLER_H
#define WSN_WSNPATHCONTROLLER_H


#include "../model/node.h"
#include <vector>




namespace wsn {

    namespace controller {

        //class have to create minimal path from nodes to targets
        class WSNPathController {

            virtual   void bindNodes(std::vector <wsn::model::Node> nodes) =0;

        };
    }
}

#endif //WSN_WSNPATHCONTROLLER_H
