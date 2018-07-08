

#ifndef WSN_RANDOM_H
#define WSN_RANDOM_H

#include <random>

namespace wsn {

    namespace util {


        class Random {

        public:

            Random();

            int randomIntInRange(int min, int max) const;
            long randomLongInRange(long min, long max) const;

            float randomFloatInRange(float min, float max) const;

            std::vector<long> uniqueRandomLongsInRange(long min, long max, unsigned long count) const;

        };

    }

}

#endif //WSN_RANDOM_H
