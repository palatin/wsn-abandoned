
#include <gtest/gtest.h>
#include <util/array_helper.h>

namespace wsn {

    namespace util {

        TEST(ArrayHelperTest, FindSmallestELement) {

            ArrayHelper arrayHelper;
            std::vector<float> values = {6, 4.6f, 8, 4.56f, 4.52f, 9, 5};

            auto smallest = arrayHelper.getSmallestElement(&values[0], values.size());
            ASSERT_EQ(std::get<0>(smallest), 4);
            ASSERT_EQ(*std::get<1>(smallest), values[4]);
        }

        TEST(ArrayHelperTest, FindSmallestElementEmptyArray) {

            ArrayHelper arrayHelper;
            std::vector<float> values;


            EXPECT_THROW(arrayHelper.getSmallestElement(&values[0], values.size()), std::invalid_argument);
        }

        TEST(ArrayHelperTest, FindLargestElement) {

            ArrayHelper arrayHelper;
            std::vector<float> values = {6, 4.6f, 8, 4.56f, 4.52f, 9, 5};

            auto smallest = arrayHelper.getLargestElement(&values[0], values.size());
            ASSERT_EQ(std::get<0>(smallest), 5);
            ASSERT_EQ(*std::get<1>(smallest), values[5]);
        }

        TEST(ArrayHelperTest, FindLargestElementEmptyArray) {

            ArrayHelper arrayHelper;
            std::vector<float> values;


            EXPECT_THROW(arrayHelper.getLargestElement(&values[0], values.size()), std::invalid_argument);
        }


    }

}

