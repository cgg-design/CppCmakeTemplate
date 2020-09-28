#include<iostream>
#include "my_lib.h"
#include "ProjectConfig.h"
#include "loguru.hpp"

int main(int argc, char **argv){

    std::cout << PROJECT_VERSION_MAJOR << "."
              << PROJECT_VERSION_MINOR << "."
              << PROJECT_VERSION_PATCH << std::endl;
    //in der CMake datei einen option definieren
    cout_hello_world();

    print_linalg_vector();

    print_boost_version();

    loguru::init(argc, argv);
    LOG_F(INFO, "Hello loguru from main!");

    return 0;
}