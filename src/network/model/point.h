//
// Created by Игорь on 30.12.2017.
//

#ifndef WSN_POINT_H
#define WSN_POINT_H


namespace wsn {
    namespace model {
        class Point {

        public:
            Point(float *x, float *y);

            float distanceBetweenPoints(float first, float second);

        private:
            float *x;
            float *y;
        };

    }
}
#endif
