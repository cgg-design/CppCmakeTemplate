#pragma once

#include<cstdint>
#include "linalg.h"
// deklaration und doc string commentare
/**
 * @brief This function prints sallo world.
 * 
 */
void print_hello_world() ;
/**
 * @brief This function prints cout hello world.
 * 
 */
void cout_hello_world();
/**
 * @brief This function prints the content of a vector.
 * 
 */
linalg::aliases::float3 print_linalg_vector();
/**
 * @brief This function prints the installes boots version
 * 
 */
void print_boost_version();

/**
 * @brief This function compute the interger average of two integers numbers
 * 
 * @param a Thie first integer value
 * @param b The second integer value
 * @return std::int32_t 
 */

std::int32_t computer_average(std::int32_t  a, std::int32_t  b);