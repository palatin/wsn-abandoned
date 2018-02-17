

#ifndef WSN_ARRAY_HELPER_H
#define WSN_ARRAY_HELPER_H


#include <stdexcept>
#include<tuple>

namespace wsn {

    namespace util {

        class ArrayHelper {

        public:

            template<typename T>
            static std::tuple<unsigned long, T*> getSmallestElement(T *array, unsigned long arrlen);

            template<typename T>
            static std::tuple<unsigned long, T*> getLargestElement(T *array, unsigned long arrlen);

        };

        template<typename T>
        std::tuple<unsigned long, T*> ArrayHelper::getSmallestElement(T *array, unsigned long  arrlen) {

            if (arrlen < 1)
                throw std::invalid_argument("empty array");

            T *arrcopyPtr = array + 1;

            T *smallest = array;

            unsigned long  index = 0;

            for (unsigned int i = 1; i < arrlen; i++, arrcopyPtr++) {
                if (*smallest > *arrcopyPtr) {
                    smallest = arrcopyPtr;
                    index = i;
                }
            }
            auto value = std::make_tuple(index, smallest);
            return value;

        }

        template<typename T>
        std::tuple<unsigned long, T*> ArrayHelper::getLargestElement(T *array, unsigned long arrlen) {

            if (arrlen < 1)
                throw std::invalid_argument("empty array");

            T *arrcopyPtr = array + 1;

            T *biggest = array;

            unsigned long  index = 0;

            for (unsigned int i = 1; i < arrlen; i++, arrcopyPtr++) {
                if (*biggest < *arrcopyPtr) {
                    biggest = arrcopyPtr;
                    index = i;
                }
            }
            auto value = std::make_tuple(index, biggest);
            return value;

        }
    }
}


#endif //WSN_ARRAY_HELPER_H
