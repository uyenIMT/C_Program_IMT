cmake_minimum_required(VERSION 3.0)

project(TP1)

# Set the compiler to gcc
set(CMAKE_C_COMPILER gcc)

# Declare the output files
add_executable(myprog.hello main_1_myfirstprogram.c)
add_executable(main_Uyen_E1.2.out main_2_printsize.c)
add_executable(main_Uyen_E1.3.1.out main_3.1_logical_use.c)
add_library(logical OBJECT logical.c)
add_executable(main_Uyen_E1.3.2.out main_3.2.c $<TARGET_OBJECTS:logical>)
add_executable(main2.4.1.out main_4.1_print_character.c)
add_executable(main2.4.2.out main_4.2_cur_ex.c)

# Set compiler flags
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

# Clean target
add_custom_target(clean-all
COMMAND ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/clean-all.cmake"
)

# Create clean-all.cmake file
file(WRITE ${CMAKE_SOURCE_DIR}/clean-all.cmake
"file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/)
file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/.o)
")