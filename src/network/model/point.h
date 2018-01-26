

#ifndef WSN_POINT_H
#define WSN_POINT_H


namespace wsn {
    namespace model {


        struct Point {

        public:
            Point(float x, float y, float z);

            float x;
            float y;
            float z;
        };

    }
}
#endif
