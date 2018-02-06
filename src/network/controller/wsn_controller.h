//
// Created by Игорь on 31.12.2017.
//

#ifndef WSN_WSNCONTROLLER_H
#define WSN_WSNCONTROLLER_H


#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <mutex>
#include "../model/node/node.h"
#include "../protocol/network_protocol.h"
#include "../core/wsn_component.h"


namespace wsn {

    namespace controller {

        typedef std::unique_ptr<wsn::core::WSNComponent> WSNComponentPtr;
        typedef std::vector<WSNComponentPtr> WSNComponents;


        class WSNController {

        public:
            WSNController();

            void addComponent(WSNComponentPtr component);
            void start();
            void stop();

            ///
            /// @param speed - time in seconds
            void setUpdateSpeed(float speed);

            //void loadNetwork(std::vector<wsn::model::Node> nodes);
            //void startNetwork();


        private:
            WSNComponents wsnComponents;
            std::thread updateThread;
            std::atomic<bool> isRunning;
            std::atomic<float> updateSpeed = 0;

            void update();

        };



    }
}

#endif
