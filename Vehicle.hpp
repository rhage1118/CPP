//
//  Vehicle.hpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include "Wheel.hpp"

typedef enum Colour {
        None = 0,
        Red,
        Yellow,
        Green
} Colour_t;

class Vehicle {
public:
    explicit Vehicle() noexcept;
    explicit Vehicle(const char *const maker, const Colour_t color=None) noexcept;
    
    // Rule of Three
    virtual ~Vehicle() noexcept;
    Vehicle(const Vehicle& other) noexcept;
    Vehicle& operator=(const Vehicle& other);
    // Rule of Five
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(Vehicle&& other) noexcept;
    
    virtual int move() const;
    
private:
    char*       maker;
    Colour_t    colour;
    Wheel       wheel[4];
};

#endif /* Vehicle_hpp */
