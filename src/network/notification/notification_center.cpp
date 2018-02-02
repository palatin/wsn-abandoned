

#include "notification_center.h"

void wsn::notification::NotificationCenter::subscribe(const wsn::notification::Event &event, wsn::notification::Observer *observer) {
    mutex.lock();
    observers[event].insert(observer);
    mutex.unlock();
}

void wsn::notification::NotificationCenter::subscribe(const wsn::notification::Event &event, std::set<Observer*> &observers) {

    mutex.lock();
    this->observers[event].insert(observers.begin(), observers.end());
    mutex.unlock();
}

void wsn::notification::NotificationCenter::unsubscribe(const wsn::notification::Event &event, wsn::notification::Observer *observer) {
    mutex.lock();
    observers[event].erase(observer);
    mutex.unlock();
}

void wsn::notification::NotificationCenter::unsubscribe(const wsn::notification::Event &event) {
    mutex.lock();
    observers.erase(event);
    mutex.unlock();
}

void wsn::notification::NotificationCenter::notify(const wsn::notification::Event &event, const void *const sender) {
    mutex.lock();
    for(auto observer : observers[event]) {
        observer->handleEvent(event, sender);
    }
    mutex.unlock();
}






