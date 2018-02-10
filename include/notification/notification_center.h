

#ifndef WSN_NOTIFICATION_CENTER_H
#define WSN_NOTIFICATION_CENTER_H

#include <map>
#include <set>
#include <mutex>
#include "observer.h"
#include "event.h"


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

            void subscribe(const Event &event, Observer *observer);

            void subscribe(const Event &event, std::set<Observer*> &observers);

            void unsubscribe(const Event &event, Observer *observer);

            void unsubscribe(const Event &event);

            void notify(const Event &event, void const * const sender);


        private:
            NotificationCenter() {};
            std::map<Event, std::set<Observer*>> observers;
            std::mutex mutex;


        };
    }
}

#endif //WSN_NOTIFICATION_CENTER_H
