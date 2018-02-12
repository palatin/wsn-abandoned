

#include "notification/notification_center.h"

void wsn::notification::NotificationCenter::subscribe(const wsn::notification::EventType &event, wsn::notification::Observer *observer) {
    mutex.lock();
    observers[event].insert(observer);
    mutex.unlock();
}

void wsn::notification::NotificationCenter::subscribe(const wsn::notification::EventType &event, std::set<Observer*> &observers) {

    mutex.lock();
    this->observers[event].insert(observers.begin(), observers.end());
    mutex.unlock();
}

void wsn::notification::NotificationCenter::unsubscribe(const wsn::notification::EventType &event, wsn::notification::Observer *observer) {
    mutex.lock();
    observers[event].erase(observer);
    mutex.unlock();
}

void wsn::notification::NotificationCenter::unsubscribe(const wsn::notification::EventType &event) {
    mutex.lock();
    observers.erase(event);
    mutex.unlock();
}

void wsn::notification::NotificationCenter::notify(const wsn::notification::Event &event) {
    mutex.lock();
    for(auto observer : observers[event.getEventType()]) {
        observer->handleEvent(event);
    }
    mutex.unlock();
}






