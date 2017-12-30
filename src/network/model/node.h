//
// Created by Игорь on 30.12.2017.
//

#ifndef WSNEMULATOR_NODE_H
#define WSNEMULATOR_NODE_H


#include "point.h"

class Node {



private:
    Point *location;
    float *energy;
    Node *link;
};


#endif //WSNEMULATOR_NODE_H
