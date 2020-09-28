#include<iostream>
#include<stdio.h>
#include "my_lib.h"
#include "linalg.h"
#include "boost/version.hpp"
#include "loguru.hpp"

void print_hello_world(){
    LOG_F(INFO, "Call: print_hello_world()!");
    printf("Printf: Hello World CMake Bestpractice test \n");
}
void cout_hello_world(){
    LOG_F(INFO, "Call: cout_hello_world()!");
    std::cout << "Cout: Hello My CMake Bestpractice test" << std::endl;
}
linalg::aliases::float3 print_linalg_vector(){
    LOG_F(INFO, "Call: print_linalg_vector()!");
    linalg::aliases::float3 my_float3{1,2,3};
    std::cout << "Vec: " << my_float3[0] << ", "<< my_float3[1] << ", " << my_float3[2] << std::endl;
    return my_float3;
}

void print_boost_version(){
    LOG_F(INFO, "Call: print_boost_version()!");
    std::cout << "Boost version: "<< BOOST_VERSION << std::endl;
}

std::int32_t computer_average(std::int32_t  a, std::int32_t  b){

    return (a+b) / 2;
}