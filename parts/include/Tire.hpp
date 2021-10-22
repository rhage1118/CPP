//
//  Tire.hpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-06.
//

#ifndef Tire_hpp
#define Tire_hpp

class Tire
{
public:
    // Default + Rule of Three
    constexpr Tire() noexcept = default;
    constexpr Tire(const Tire&) noexcept = default;
    ~Tire() noexcept = default;
    Tire& operator=(const Tire&) noexcept = default;
    // Rule of Five
    Tire(Tire&&) noexcept = default;
    Tire& operator=(Tire&&) noexcept = default;

private:
};

#endif /* Tire_hpp */
