#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <thread>
#include <notification/event/node_death_event.h>
#include "notification/event/event.h"


#include "../../include/notification/observer.h"
#include "../../include/notification/notification_center.h"


namespace wsn {

    namespace notification {

        using ::testing::_;

        class MockObserver :  public Observer {

        public:
            MOCK_METHOD1(handleEvent, void(const Event &event));

        };



        TEST(NotificationTest, Subscribe) {
            MockObserver observer;
            const NodeDeathEvent ev(nullptr);
            EXPECT_CALL(observer, handleEvent(_)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(EventType::NodeDeath, &observer);
            notificationCenter.notify(ev);
        }

        TEST(NotificationTest, Unsubscribe) {
            MockObserver observer;
            const NodeDeathEvent ev(nullptr);
            EXPECT_CALL(observer, handleEvent(_)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(EventType::NodeDeath, &observer);
            notificationCenter.notify(ev);
            notificationCenter.unsubscribe(EventType::NodeDeath, &observer);
            notificationCenter.notify(ev);
        }

        TEST(NotificationTest, UnsubscribeMultiObservers) {
            MockObserver observer;
            MockObserver observer2;
            const NodeDeathEvent ev(nullptr);
            EXPECT_CALL(observer, handleEvent(_)).Times(1);
            EXPECT_CALL(observer2, handleEvent(_)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(EventType::NodeDeath, &observer);
            notificationCenter.subscribe(EventType::NodeDeath, &observer2);
            notificationCenter.notify(ev);
            notificationCenter.unsubscribe(EventType::NodeDeath);
            notificationCenter.notify(ev);
        }

        TEST(NotificationCenter, SubscribeWithMultiObserversBySet) {
            MockObserver observer;
            MockObserver observer2;
            MockObserver observer3;
            const NodeDeathEvent ev(nullptr);
            std::set<Observer*> observers {&observer, &observer2};
            EXPECT_CALL(observer, handleEvent(_)).Times(1);
            EXPECT_CALL(observer2, handleEvent(_)).Times(1);
            EXPECT_CALL(observer3, handleEvent(_)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(EventType::NodeDeath, observers);
            notificationCenter.subscribe(EventType::NodeDeath, &observer3);
            notificationCenter.notify(ev);
        }

        TEST(NotificationCenter, SubscribeWithMultiObservers) {
            MockObserver observer;
            MockObserver observer2;
            const NodeDeathEvent ev(nullptr);
            EXPECT_CALL(observer, handleEvent(_)).Times(1);
            EXPECT_CALL(observer2, handleEvent(_)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(EventType::NodeDeath, &observer);
            notificationCenter.subscribe(EventType::NodeDeath, &observer2);
            notificationCenter.notify(ev);
        }



    }
}
