#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <thread>
#include "../../../src/network/notification/event.h"


#include "../../../src/network/notification/observer.h"
#include "../../../src/network/notification/notification_center.h"


namespace wsn {

    namespace notification {

        using ::testing::_;

        class MockObserver :  public Observer {

        public:
            MOCK_METHOD2(handleEvent, void(wsn::notification::Event event, const void* const sender));

        };



        TEST(NotificationTest, Subscribe) {
            MockObserver observer;
            EXPECT_CALL(observer, handleEvent(Event::NodeDeath, _)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(Event::NodeDeath, &observer);
            notificationCenter.notify(Event::NodeDeath, nullptr);
        }

        TEST(NotificationTest, Unsubscribe) {
            MockObserver observer;
            EXPECT_CALL(observer, handleEvent(Event::NodeDeath, _)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(Event::NodeDeath, &observer);
            notificationCenter.notify(Event::NodeDeath, nullptr);
            notificationCenter.unsubscribe(Event::NodeDeath, &observer);
            notificationCenter.notify(Event::NodeDeath, nullptr);
        }

        TEST(NotificationTest, UnsubscribeMultiObservers) {
            MockObserver observer;
            MockObserver observer2;
            EXPECT_CALL(observer, handleEvent(Event::NodeDeath, _)).Times(1);
            EXPECT_CALL(observer2, handleEvent(Event::NodeDeath, _)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(Event::NodeDeath, &observer);
            notificationCenter.subscribe(Event::NodeDeath, &observer2);
            notificationCenter.notify(Event::NodeDeath, nullptr);
            notificationCenter.unsubscribe(Event::NodeDeath);
            notificationCenter.notify(Event::NodeDeath, nullptr);
        }

        TEST(NotificationCenter, SubscribeWithMultiObserversBySet) {
            MockObserver observer;
            MockObserver observer2;
            MockObserver observer3;
            std::set<Observer*> observers {&observer, &observer2};
            EXPECT_CALL(observer, handleEvent(Event::NodeDeath, _)).Times(1);
            EXPECT_CALL(observer2, handleEvent(Event::NodeDeath, _)).Times(1);
            EXPECT_CALL(observer3, handleEvent(Event::NodeDeath, _)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(Event::NodeDeath, observers);
            notificationCenter.subscribe(Event::NodeDeath, &observer3);
            notificationCenter.notify(Event::NodeDeath, nullptr);
        }

        TEST(NotificationCenter, SubscribeWithMultiObservers) {
            MockObserver observer;
            MockObserver observer2;
            EXPECT_CALL(observer, handleEvent(Event::NodeDeath, _)).Times(1);
            EXPECT_CALL(observer2, handleEvent(Event::NodeDeath, _)).Times(1);
            auto &notificationCenter = NotificationCenter::getInstance();
            notificationCenter.subscribe(Event::NodeDeath, &observer);
            notificationCenter.subscribe(Event::NodeDeath, &observer2);
            notificationCenter.notify(Event::NodeDeath, nullptr);
        }



    }
}
