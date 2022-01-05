//
//  main.cpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#include <iostream>
#include "Vehicle.hpp"

// GNU Scientific Library
#include <gsl/gsl_sf_bessel.h>

static void fn(Vehicle&& input)
{
    input.move();
}


int main(int argc, const char * argv[]) {
    
    Vehicle v2("c_maker", Red);
    Vehicle v3(v2);

    fn(std::move(v2));
    
    double y = gsl_sf_bessel_J0 (5);
    printf("gsl y=%lf\n", y);
    
    return 0;
}
