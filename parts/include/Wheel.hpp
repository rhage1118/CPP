//
//  Wheel.hpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-05.
//

#ifndef Wheel_hpp
#define Wheel_hpp

class Wheel {
public:
    // Default + Rule of Three
    Wheel() noexcept = default;
    Wheel(const Wheel&) noexcept = default;
    ~Wheel() noexcept = default;
    Wheel& operator=(const Wheel&) noexcept = default;
    // Rule of Five
    Wheel(Wheel&&) noexcept = default;
    Wheel& operator=(Wheel&&) noexcept = default;
    
    void display() const;
private:
    /*
    Tire    tire;
    Rim     rim;*/
};

#endif /* Wheel_hpp */
