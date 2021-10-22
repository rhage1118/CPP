//
//  Vehicle.hpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>

typedef enum Colour {
        Red = 1,
        Yellow,
        Green
} Colour_t;

class Vehicle {
public:
    Vehicle();
    Vehicle(Colour_t color);
private:
    Colour_t colour;
};

#endif /* Vehicle_hpp */
