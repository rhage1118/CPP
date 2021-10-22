//
//  main.cpp
//  XCode_CPP
//
//  Created by Ramsey Hage on 2021-10-21.
//
//  /usr/local/opt/llvm/bin/clang-tidy  -header-filter=.* --checks=.* *cpp -- -I/Users/rhage/Git_Local/thread/include -I/Users/rhage/Git_Local/parts/include  -std=c++20
//

#include <iostream>

#include <typeinfo>

#include "Runner.hpp"
#include "Vehicle.hpp"

#ifdef GSL_ON
// GNU Scientific Library
#include <gsl/gsl_sf_bessel.h>
#endif

template <typename T>
static void helper(T& input)
{
    std::cout << "============> lvalue helper selected\n";
}

template <typename T>
static void helper(T&& input)
{
    std::cout << "============> rvalue helper selected\n";
}

template <typename T>
static void helper(const T& input)
{
    std::cout << "============> const lvalue helper selected\n";
}

template <typename T>
static void perfect_forward(T&& input)
{
    // "input" is a perfect forward template
    // Because we are in template, we use std::forward to next level
    
    helper(std::forward<T>(input));
}

int main(int argc, const char * argv[])
{
    do_runners();

    Vehicle v1;
    Vehicle v2("c_maker", Red);
    const Vehicle v3(v2);

    perfect_forward(v1);            // lvalue
    perfect_forward(Vehicle());     // rvalue
    perfect_forward(v3);            // const lvalue / const Vehicle

#ifdef GSL_ON
    double y = gsl_sf_bessel_J0 (5);
    printf("gsl y=%lf\n", y);
#endif

    return 0;
}
