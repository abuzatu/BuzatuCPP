cmake_minimum_required(VERSION 3.7)
project(testZMQ)
set(CMAKE_CXX_STANDARD 14) # change here for 14, 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(RUNTIME_OUTPUT_DIRECTORY ../build)

#find cppzmq wrapper, installed by make of cppzmq
find_package(cppzmq)

add_executable(testZMQ1 testZMQ1.cpp)
target_link_libraries(testZMQ1 cppzmq)

add_executable(testZMQ2 testZMQ2.cpp)
target_link_libraries(testZMQ2 cppzmq)

