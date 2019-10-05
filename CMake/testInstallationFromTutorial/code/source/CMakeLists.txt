cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11) # change here for 14, 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(RUNTIME_OUTPUT_DIRECTORY ../build)
add_executable(test test.cpp)
target_link_libraries(test /usr/local/bin/libMathFunctions.a)
