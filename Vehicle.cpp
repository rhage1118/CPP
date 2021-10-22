//
//  Vehicle.cpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#include <string.h>
#include "Vehicle.hpp"


Vehicle::Vehicle() :
    maker(NULL), colour(Red)
{
}

Vehicle::Vehicle(const char *const maker, Colour_t colour) :
    colour(colour)
{
    this->maker = new char[strlen(maker) + 1];
    strcpy(this->maker, maker);
}

Vehicle::~Vehicle()
{
    if (maker) {
        delete [] maker;
    }
}


int
Vehicle::x()
{
    return 0;
}

