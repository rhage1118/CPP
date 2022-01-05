//
//  Vehicle.cpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#include <iostream>
#include <string.h>
#include "Vehicle.hpp"

Vehicle::Vehicle() noexcept :
    maker(nullptr),
    colour(None)
{
}

Vehicle::Vehicle(const char *const maker, const Colour_t colour) noexcept :
    colour(colour)
{
    std::cout << "constructor" << std::endl;
    if (maker == NULL) {
        this->maker = nullptr;
    } else {
        this->maker = new char[strlen(maker) + 1];
        strcpy(this->maker, maker);
    }
}

Vehicle::~Vehicle() noexcept
{
    // Rule of Three: Destructor
    std::cout << "desstructor" << std::endl;
    
    delete [] maker;
}

Vehicle::Vehicle(const Vehicle& other) noexcept :
    Vehicle(other.maker, other.colour)
{
    // Rule of Three: Copy Constructor
    std::cout << "copy constructor" << std::endl;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    // Rule of Three: Copy Assignment
    std::cout << "copy assignment" << std::endl;
    if (&other != this) {
        delete [] maker;

        if (other.maker != nullptr) {
            maker = new char[strlen(other.maker) + 1];
            strcpy(maker, other.maker);
        } else {
            maker = nullptr;
        }
        colour = other.colour;
    }
    return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept :
    maker( std::move(other.maker) ),
    colour( std::move(other.colour) )
{
    // Rule of Five: Move Constructor
    std::cout << "move constructor" << std::endl;
    other.maker = nullptr;
    other.colour = None;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
    // Rule of Five: Move assignment
    std::cout << "move assignment" << std::endl;

    // clear my own resoources
    delete [] maker;

    // steal other resource
    maker = std::move(other.maker);
    colour = std::move(other.colour);
    
    // empty other resource
    other.maker = nullptr;
    other.colour = None;

    return *this;
}

int
Vehicle::move() const
{
    std::cout << "Vehicle::move(), maker=" << maker << ", Colour=" << colour << std::endl;
    return 0;
}

