cmake_minimum_required(VERSION 3.0)
project(Tutorial)
# The version number
set(Tutorial_VERSION_MAJOR 2)
set(Tutorial_VERSION_MINOR 3)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# include the header where our mysqrt() function is declared
include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")

# add to build first the subdirectory where our static library will be compiled and linked
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)
# to link to Tutorial our static library
target_link_libraries(Tutorial MathFunctions)
