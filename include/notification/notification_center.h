

#ifndef WSN_NOTIFICATION_CENTER_H
#define WSN_NOTIFICATION_CENTER_H

#include <map>
#include <set>
#include <mutex>
#include "observer.h"
#include "../notification/event/event.h"


namespace wsn {

    namespace notification {

        class NotificationCenter {

        public:
            static NotificationCenter &getInstance() {

                static NotificationCenter instance;

                return instance;
            }

            NotificationCenter(NotificationCenter const &) = delete;

            void operator=(NotificationCenter const &) = delete;

            void subscribe(const EventType &event, Observer *observer);

            void subscribe(const EventType &event, std::set<Observer*> &observers);

            void unsubscribe(const EventType &event, Observer *observer);

            void unsubscribe(const EventType &event);

            void notify(const Event &event);


        private:
            NotificationCenter() {};
            std::map<EventType, std::set<Observer*>> observers;
            std::mutex mutex;


        };
    }
}

#endif //WSN_NOTIFICATION_CENTER_H
