
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../include/core/wsn_component.h"
#include "../../include/controller/wsn_controller.h"


namespace wsn {

    namespace controller {

        using ::testing::_;
        using ::testing::AtLeast;

        class SpyWSNComponent :  public wsn::core::WSNComponent {

        public:
            void update() override {
                updateCalled++;
            }

            int updateCalled = 0;

        };



        class WSNControllerTest : public testing::Test {

        protected:
            void SetUp() override {
                this->wsnController = new WSNController();
            }

            void TearDown() override {

                delete wsnController;
            }


            WSNController *wsnController;
        };

        TEST_F(WSNControllerTest, UpdateComponent) {
            auto ptr = std::make_unique<SpyWSNComponent>();
            auto *obj = ptr.get();

            wsnController->addComponent(std::move(ptr));

            wsnController->start();
            sleep(1);
            wsnController->stop();
            EXPECT_TRUE(obj->updateCalled > 0);
        }

        TEST_F(WSNControllerTest, InsertComponentsWhileRunning) {
            auto ptr = std::make_unique<SpyWSNComponent>();
            auto *obj = ptr.get();

            wsnController->addComponent(std::move(ptr));

            wsnController->start();
            for (int i = 0; i < 100000; ++i) {
                wsnController->addComponent(std::make_unique<SpyWSNComponent>());
            }

            wsnController->start();
            sleep(1);
            wsnController->stop();
            EXPECT_TRUE(obj->updateCalled > 0);
        }




    }
}