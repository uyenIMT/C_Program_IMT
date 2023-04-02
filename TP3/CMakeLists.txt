cmake_minimum_required(VERSION 3.0)
project(TP3)

# Set the compiler to gcc
set(CMAKE_C_COMPILER gcc)

# Set compiler flags for all targets
set(CMAKE_C_FLAGS "-lm")

# Specify header file dependencies for binary_to_text.o and packing_NGUYEN.o
set(DEPS_BINARY_TO_TEXT "binary_to_text.h")
set(DEPS_PACKING_NGUYEN "packing_NGUYEN.h")

# Compile the exercise TP3.1
add_executable(main_Uyen_E3.1.out main_Uyen_E3.1.c)
target_link_libraries(main_Uyen_E3.1.out ${CMAKE_C_FLAGS})

# Compile the exercise TP3.2
add_library(binary_to_text OBJECT binary_to_text.c ${DEPS_BINARY_TO_TEXT})
add_executable(main_Uyen_E3.2.out main_Uyen_E3.2.c $<TARGET_OBJECTS:binary_to_text>)
target_link_libraries(main_Uyen_E3.2.out ${CMAKE_C_FLAGS})

# Compile the exercise TP3.3
add_library(packing_NGUYEN OBJECT packing_NGUYEN.c ${DEPS_PACKING_NGUYEN})
add_executable(main_Uyen_E3.3.out main_Uyen_E3.3.c $<TARGET_OBJECTS:packing_NGUYEN>)
target_link_libraries(main_Uyen_E3.3.out ${CMAKE_C_FLAGS})