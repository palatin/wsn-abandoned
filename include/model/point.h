

#ifndef WSN_POINT_H
#define WSN_POINT_H

#include <tuple>


namespace wsn {
    namespace model {


        struct Point {

            Point() = default;
            Point(float x, float y, float z);

            float x;
            float y;
            float z;

            inline bool operator==(const Point &value) {
                return (x == value.x) && (y == value.y) && (z == value.z);
            }

            inline bool operator!=(const Point &value) {
                return !(*this == value);
            }

            inline void operator+=(const Point &value) {
                x += value.x;
                y += value.y;
                z += value.z;
            }

            inline void operator/=(float value) {
                x /= value;
                y /= value;
                z /= value;
            }

            friend inline bool operator<(const Point &first, const Point &second) {
                return std::tie(first.x, first.y, first.z) < std::tie(second.x, second.y, second.z);
            }
        };

    }
}
#endif
