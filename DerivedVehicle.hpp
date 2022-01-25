//
//  DerivedVehicle.hpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-24.
//

#ifndef DerivedVehicle_hpp
#define DerivedVehicle_hpp

#include "Vehicle.hpp"

class DerivedVehicle : public Vehicle {
public:
    DerivedVehicle() noexcept = default;
    
    // Rule of Three
    virtual ~DerivedVehicle() noexcept = default;
    DerivedVehicle(const DerivedVehicle& other) noexcept = default;
    DerivedVehicle& operator=(const DerivedVehicle& other) = default;
    // Rule of Five
    DerivedVehicle(DerivedVehicle&& other) noexcept = default;
    DerivedVehicle& operator=(DerivedVehicle&& other) noexcept = default;
    
    virtual int move() const override final;
};

#endif /* DerivedVehicle_hpp */
