

#ifndef WSN_ARRAY_HELPER_H
#define WSN_ARRAY_HELPER_H


#include <stdexcept>
#include<tuple>

namespace wsn {

    namespace util {

        class ArrayHelper {

        public:

            template<typename T>
            static std::tuple<unsigned long, T*> getSmallestElement(const T *array, unsigned long arrlen);

            template<typename T>
            static std::tuple<unsigned long, T*> getBiggestElement(const T *array, unsigned long arrlen);

        };



        template<typename T>
        std::tuple<unsigned long, T*> ArrayHelper::getSmallestElement(const T *array, unsigned long  arrlen) {

            if (arrlen < 1)
                throw std::invalid_argument("empty array");

            const T *arrcopy = array;

            T smallest = *array;

            unsigned long  index = 0;

            for (unsigned int i = 1; i < arrlen - 1; i++, arrcopy++) {
                if (smallest > *array) {
                    smallest = *array;
                    index = i;
                }
            }

            return {index, smallest};

        }

        template<typename T>
        std::tuple<unsigned long, T*> ArrayHelper::getBiggestElement(const T *array, unsigned long  arrlen) {

            if (arrlen < 1)
                throw std::invalid_argument("empty array");

            const T *arrcopy = array;

            T biggest = *array;

            unsigned long  index = 0;

            for (unsigned int i = 1; i < arrlen - 1; i++, arrcopy++) {
                if (biggest < *array) {
                    biggest = *array;
                    index = i;
                }
            }

            return {index, biggest};

        }
    }
}


#endif //WSN_ARRAY_HELPER_H
