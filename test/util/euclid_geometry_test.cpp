
#include <gtest/gtest.h>
#include "../../include/model/point.h"
#include "../../include/util/euclid_geometry.h"


namespace wsn {

    namespace util {

        using wsn::model::Point;

        class EuclidGeometryTest : public testing::Test {


        protected:
            void SetUp() override {
                geometry = new EuclidGeometry();
            }

            void TearDown() override {
                delete geometry;
            }

            EuclidGeometry *geometry;
        };

        TEST_F(EuclidGeometryTest, CalculateDistance) {

            Point first(12.2, 1.6, -2);
            Point second(0.5, 9.87, 4.5);
            ASSERT_FLOAT_EQ(geometry->distanceBetweenPoints(first, second), 15.733178);
        }
    }
}