

#ifndef WSN_POINT_H
#define WSN_POINT_H


namespace wsn {
    namespace model {


        struct Point {

            Point() = default;
            Point(float x, float y, float z);

            float x;
            float y;
            float z;

            bool operator==(const Point &value) {
                return (x == value.x) && (y == value.y) && (z == value.z);
            }

            bool operator!=(const Point &value) {
                return !(*this == value);
            }

            Point& operator+=(const Point &value) {
                x += value.x;
                y += value.y;
                z += value.z;
            }

            Point& operator/=(float value) {
                x /= value;
                y /= value;
                z /= value;
            }
        };

    }
}
#endif
