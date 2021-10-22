//
//  Wheel.cpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-05.
//

#include <iostream>
#include "Wheel.hpp"

Wheel::Wheel() noexcept
    : tire()
{
    std::cout << "Wheel: base constructor\n";
}

Wheel::Wheel(const Wheel& other) noexcept
 : tire(other.tire)
{
    std::cout << "Wheel: copy constructor\n";
}

Wheel::~Wheel() noexcept
{
    std::cout << "Wheel destructor\n";
}

Wheel& Wheel::operator=(const Wheel& other) noexcept
{
    std::cout << "Wheel copy assignment\n";
    if (this != &other) {
        tire = other.tire;
    }
    
    return *this;
}

Wheel::Wheel(Wheel&& other) noexcept
{
    std::cout << "Wheel move constructor\n";
    tire = std::move(other.tire);
}

Wheel& Wheel::operator=(Wheel&& other) noexcept
{
    std::cout << "Wheel move assignment\n";
    if (this != &other) {
        tire = std::move(other.tire);
    }
    return *this;
}


void Wheel::display() const
{
    std::cout << "Wheel::display\n";
}
