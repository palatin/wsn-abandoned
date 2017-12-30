//
// Created by Игорь on 30.12.2017.
//

#ifndef WSNEMULATOR_POINT_H
#define WSNEMULATOR_POINT_H


class Point {

public:
    Point(float *x, float *y);

    float distanceBetweenPoints(float first, float second);

private:
    float *x;
    float *y;
};


#endif //WSNEMULATOR_POINT_H
