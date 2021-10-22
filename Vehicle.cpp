//
//  Vehicle.cpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#include <iostream>
#include <initializer_list>
#include <string.h>
#include "Vehicle.hpp"

Vehicle::Vehicle() noexcept :
    maker(nullptr),
    colour(None)
{
    std::cout << "default constructor\n";
}

Vehicle::Vehicle(const char *const maker, const Colour_t colour) noexcept :
    colour(colour)
{
    std::cout << "constructor\n";
    if (maker == NULL) {
        this->maker = nullptr;
    } else {
        size_t const len = strlen(maker);
        this->maker = new char[len + 1];
        snprintf(this->maker, len+1, "%s", maker);
    }
}

Vehicle::~Vehicle() noexcept
{
    // Rule of Three: Destructor
    std::cout << "destructor\n";
    
    delete [] maker;
    maker = nullptr;
}

Vehicle::Vehicle(const Vehicle& other) noexcept :
    Vehicle(other.maker, other.colour)
{
    // Rule of Three: Copy Constructor
    std::cout << "copy constructor\n";
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    // Rule of Three: Copy Assignment
    std::cout << "copy assignment\n";
    if (this != &other) {
        delete [] maker;

        if (other.maker != nullptr) {
            size_t const len = strlen(other.maker);
            maker = new char[len + 1];
            snprintf(maker, len+1, "%s", other.maker);
        } else {
            maker = nullptr;
        }
        colour = other.colour;
        
        for(int i=0; i<4; i++) {
            wheel[i] = other.wheel[i];
        }
    }
    return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept :
    maker( std::move(other.maker) ),
    colour( std::move(other.colour) )
{
    // Rule of Five: Move Constructor
    std::cout << "move constructor\n";

    for(int i=0; i<4; i++) {
        wheel[i] = std::move(other.wheel[i]);
    }
    
    other.maker = nullptr;
    other.colour = None;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
    // Rule of Five: Move assignment
    std::cout << "move assignment\n";

    // clear my own resoources
    delete [] maker;

    // steal other resource
    maker = std::move(other.maker);
    colour = std::move(other.colour);
    for(int i=0; i<4; i++) {
        wheel[i] = std::move(other.wheel[i]);
    }

    // empty other resource
    other.maker = nullptr;
    other.colour = None;

    return *this;
}

int
Vehicle::move() const
{
    std::cout << "Vehicle::move(), maker=" << maker << ", Colour=" << colour << "\n";
    return 0;
}

