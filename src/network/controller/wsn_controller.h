//
// Created by Игорь on 31.12.2017.
//

#ifndef WSN_WSNCONTROLLER_H
#define WSN_WSNCONTROLLER_H


#include <vector>
#include "../model/node.h"



namespace wsn {

    namespace controller {

        class WSNController {

        public:
            void WSNController()
            void loadNetwork(std::vector<wsn::model::Node> nodes);
            void startNetwork();


        };

    }
}

#endif
