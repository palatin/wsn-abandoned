

#ifndef WSN_ARRAY_HELPER_H
#define WSN_ARRAY_HELPER_H


#include <stdexcept>

namespace wsn {

    namespace util {

        class ArrayHelper {

        public:

            template<typename T>
            static unsigned long  getSmallestElementIndex(const T *array, unsigned long arrlen);

        };



        template<typename T>
        unsigned long  ArrayHelper::getSmallestElementIndex(const T *array, unsigned long  arrlen) {

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

            return index;

        }
    }
}


#endif //WSN_ARRAY_HELPER_H
