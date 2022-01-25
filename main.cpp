//
//  main.cpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//

#include <iostream>
#include <typeinfo>

#include "Vehicle.hpp"

#if 0
// GNU Scientific Library
#include <gsl/gsl_sf_bessel.h>
#endif

constexpr void foo(Vehicle &input)
{
    input.move();
}

template <typename T>
static constexpr void helper(T input)
{
    //std::cout << "typeid: " << typeid(input).name() << std::endl;
}

template <typename T>
static constexpr void perfect_forward(T&& input)
{
    // "input" is a perfect forward template
    // Because we are in template, we use std::forward to next level
    
    helper(std::forward<T>(input));
}

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
    const Vehicle v3(v2);

    v1 = v2;
    foo(v1);
    
    perfect_forward(v1);            // lvalue
    perfect_forward( Vehicle() );   // rvalue
    perfect_forward( v3 );          // const lvalue / const Vehicle
    
    /*
    Vehicle invalid = "c_maker";  <--- implicit call to constructor, not allowed since constructor is explicit
    */
    
    fn(std::move(v2));
    
#if 0
    double y = gsl_sf_bessel_J0 (5);
    printf("gsl y=%lf\n", y);
#endif
    
    return 0;
}
