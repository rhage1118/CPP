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
    // Since this function is passing an rvalue, we can steal the resource
    // The move constructor will be invoked now, at the end... the resources will be destructed
    Vehicle steal( std::move(input) );
    
    // do stuff
    steal.move();
}


int main(int argc, const char * argv[]) {
    
    Vehicle v1;
    Vehicle v2("c_maker", Red);
    Vehicle v3(v2);

    v1 = v2;
    
    /*
    Vehicle invalid = "c_maker";  <--- implicit call to constructor, not allowed since constructor is explicit
    */
    
    fn(std::move(v2));
    
    double y = gsl_sf_bessel_J0 (5);
    printf("gsl y=%lf\n", y);
    
    return 0;
}
