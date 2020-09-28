########### Bauen  ###########
# Build: cmake -D USE_PRINTF=ON ..

cmake_minimum_required(VERSION 3.12)

# variable deklarieren und initialisieren
# set the project name and version
set(PROJECT "Benchmarking")
project("${PROJECT}_Project" VERSION 1.2.3 LANGUAGES CXX)
# Global CMake variables are here
set(CMAKE_CXX_STANDARD          17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSION         OFF) # nicht verwenden den Compiler, der nicht vom anderen genutzt ist.

# Project/library name
set(LIBRARY_NAME       "${PROJECT}_MyLib")
# define variable for lianalg
set(LIBRARY_LINALG     "${PROJECT}_LinAlg")
# -----------------------------------
set(LIBRARY_LOG         "${PROJECT}_loguru") # damit wird später PROJECT_loguru (loguru = originalproject name aus CMakeLists)
set(LIBRARY_BENCH       "${PROJECT}_celero") # damit wird später PROJECT_celero (celero = originalproject name aus CMakeLists)
# --------------------------------
set(MAIN               "${PROJECT}_Executable")
# for the Unittest
set(TEST_MAIN "${PROJECT}_unit_tests")
# --------------------- Code coverage ----------------------
#Explicite setzen, ob ich Code coverage wirklich nurzen will, default wert OFF
option(USE_GCOV "Create a GCov-enable build" OFF)
option(USE_BENCHMARKS "Create a Benchmark-enablebuils" OFF)
#--------------------- end cov ----------------------
#Configuration file
configure_file("${PROJECT_SOURCE_DIR}/include/ProjectConfig.h.in"
               "${PROJECT_BINARY_DIR}/ProjectConfig.h" @ONLY)
#--------------------- Doxygen start ----------------------
# wo liegt die cmake module(Include own cmake Files)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
#lieg vor?
include(Documentation)
# CTest ist vorinstaliertes module um unittest zu erstellen
include(CTest) # add_test() gehört zu CTest
#-------------------- gTest  -----------------------
# wenn der User GCove nutzen will, mit ON gestzt hat
# auf sichere UNIX system braucht die abfrage nicht sondern direkt : include(CodeCoverage)
if(USE_GCOV)
    # check used Compiler, GNU (gcc/g++)  oder clang
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        include(CodeCoverage)
    else()
    # Wenn MFVS Compiler ist (Windows) wird nicht funktionieren
        message("You must use a GNU or Clang Compiler for Code Coverage!")
    endif()
endif()
# include(CodeCoverage)
#--------------------- Doxygen end ----------------------
# add conan installed packages: die generierte file nach dem  installation vom conan hinzufügen
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # zu finden fom funktion
conan_basic_setup() # mit der aufruf erfolgt die conan method aufruf

# add conan 
########################### New ###########################
# Add external : hier würder der compiler die cmal liste finden
add_subdirectory(external)
# Add libraries
add_subdirectory(src)
# Add executable
add_subdirectory(app)
# Add tests
add_subdirectory(tests)
# Add benchmarks
add_subdirectory(benchmarks)



