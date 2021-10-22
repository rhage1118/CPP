//
//  Wheel.hpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-05.
//

#ifndef Wheel_hpp
#define Wheel_hpp

#include "Tire.hpp"

class Wheel {
public:
    // Default + Rule of Three
    Wheel() noexcept;
    Wheel(const Wheel&) noexcept;
    ~Wheel() noexcept;
    Wheel& operator=(const Wheel&) noexcept;
    // Rule of Five
    Wheel(Wheel&&) noexcept;
    Wheel& operator=(Wheel&&) noexcept;
    
    void display() const;
private:
    Tire    tire;
};

#endif /* Wheel_hpp */
