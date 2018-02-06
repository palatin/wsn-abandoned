

#include "wsn_controller.h"


void wsn::controller::WSNController::addComponent(wsn::controller::WSNComponentPtr component) {
    stop();
    wsnComponents.push_back(std::move(component));
    start();
}

void wsn::controller::WSNController::start() {
    if(isRunning == false) {
        this->updateThread = std::thread(&WSNController::update, this);
        isRunning = true;
    }
}

void wsn::controller::WSNController::stop() {
    isRunning = false;
    updateThread.join();
}

void wsn::controller::WSNController::setUpdateSpeed(float speed) {
    this->updateSpeed = speed;
}



void wsn::controller::WSNController::update() {

    while(isRunning) {

        for (auto &component : wsnComponents) {
            component->update();
        }

        std::this_thread::sleep_for(std::chrono::seconds(updateSpeed));
    }

}




