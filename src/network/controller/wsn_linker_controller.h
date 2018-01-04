

#ifndef WSN_WSN_LINKER_CONTROLLER_H
#define WSN_WSN_LINKER_CONTROLLER_H


#include "../model/node.h"
#include "../model/nodes.h"
#include "../util/geometry.h"
#include <vector>




namespace wsn {

    namespace controller {

        //class have to create minimal path from nodes to targets
        class WSNLinkerController {

            virtual   void bindNodes(wsn::model:: Nodes &nodes) =0;

        protected:
            wsn::util::Geometry *geometry;

        };
    }
}

#endif //WSN_WSN_LINKER_CONTROLLER_H
