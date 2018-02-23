

#ifndef WSN_NODES_FACTORY_H
#define WSN_NODES_FACTORY_H


#include "../model/nodes.h"

namespace wsn {

    namespace factory {

        template<typename NodeType>
        class NodesFactory {

        public:
            NodesFactory() = default;


            virtual std::shared_ptr<wsn::model::Nodes> buildNodes() = 0;

        };
    }
}
#endif //WSN_NODES_FACTORY_H
