

#ifndef WSN_WSN_CLUSTER_TREE_LINKER_CONTROLLER_H
#define WSN_WSN_CLUSTER_TREE_LINKER_CONTROLLER_H


#include "wsn_linker_controller.h"

namespace wsn {

    namespace controller {

        class WSNClusterTreeLinkerController : WSNLinkerController {

        public:
            void bindNodes(wsn::model:: Nodes &nodes);

        private:
            void clustering(wsn::model:: Nodes &nodes);

        };

    }
}


#endif //WSN_WSN_CLUSTER_TREE_LINKER_CONTROLLER_H
