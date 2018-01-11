//
// Created by Игорь on 31.12.2017.
//

#ifndef WSN_WSNCONTROLLER_H
#define WSN_WSNCONTROLLER_H


#include <vector>
#include "../model/node/node.h"



namespace wsn {

    namespace controller {

        class WSNController {

        public:
            WSNController();
            void loadNetwork(std::vector<wsn::model::Node> nodes);
            void startNetwork();


        };

    }
}

#endif
