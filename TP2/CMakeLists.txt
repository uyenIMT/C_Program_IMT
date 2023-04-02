# set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# set the project name
project(exercises)

# set the compiler to GCC
set(CMAKE_C_COMPILER gcc)

# Create a library for exchange.o
add_library(exchange exchange.c)

# Declare the output executable targets
add_executable(main2.1.out main_Uyen_E2.1.c)
add_executable(main2.2.out main_Uyen_E2.2.c)
add_executable(main2.3.out main_Uyen_E2.3.c)
add_executable(main2.4.out main_Uyen_E2.4.c)

# Link the exchange library to the targets
target_link_libraries(main2.1.out exchange)
target_link_libraries(main2.2.out exchange)
target_link_libraries(main2.3.out exchange)
target_link_libraries(main2.4.out exchange)