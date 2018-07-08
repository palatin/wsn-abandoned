

#include <random>
#include <algorithm>
#include "util/random.h"


wsn::util::Random::Random() {

}


int wsn::util::Random::randomIntInRange(int min, int max) const {
    return 0;
}

long wsn::util::Random::randomLongInRange(long min, long max) const {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<long> dist(min, max);
    return dist(mt);
}

float wsn::util::Random::randomFloatInRange(float min, float max) const {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(mt);
}


std::vector<long> wsn::util::Random::uniqueRandomLongsInRange(long min, long max, unsigned long count) const {

    std::random_device rd;
    std::vector<long> numbers(abs(min) + max);

    //generate numbers from 0 - nodeCount to choose CHs
    std::iota(numbers.begin(), numbers.end(), min);

    std::shuffle(numbers.begin(), numbers.end(), std::mt19937(rd()));


    return std::vector<long>(numbers.begin(), numbers.begin() + count);;
}

