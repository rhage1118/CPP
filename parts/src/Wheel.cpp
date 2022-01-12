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
    std::cout << "Wheel: base constructor" << std::endl;
}

Wheel::Wheel(const Wheel& other) noexcept
 : tire(other.tire)
{
    std::cout << "Wheel: copy constructor" << std::endl;
}

Wheel::~Wheel() noexcept
{
    std::cout << "Wheel destructor" << std::endl;
}

Wheel& Wheel::operator=(const Wheel& other) noexcept
{
    std::cout << "Wheel copy assignment" << std::endl;
    if (this != &other) {
        tire = other.tire;
    }
    
    return *this;
}

Wheel::Wheel(Wheel&& other) noexcept
{
    std::cout << "Wheel move constructor" << std::endl;
    tire = std::move(other.tire);
}

Wheel& Wheel::operator=(Wheel&& other) noexcept
{
    std::cout << "Wheel move assignment" << std::endl;
    if (this != &other) {
        tire = std::move(other.tire);
    }
    return *this;
}


void Wheel::display() const
{
    std::cout << "Wheel::display\n";
}
