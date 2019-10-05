cmake_minimum_required(VERSION 3.0)
project(Tutorial)
# The version number
set(Tutorial_VERSION_MAJOR 2)
set(Tutorial_VERSION_MINOR 3)

# should we use our own math functions?
option(USE_MYMATH "Use math implementation provided by tutorial" ON)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library? if yes, add to the extra libs variable, else do not add it
if(USE_MYMATH)
  # include the header where our mysqrt() function is declared
  include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
  # add to build first the subdirectory where our static library will be compiled and linked
  add_subdirectory(MathFunctions)
  # add to the EXTRA_LIBS variable also the library MathFunctions
  # note the EXTRA_LIBS can also be empty and if we are not adding, it remains empty
  set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

# add the executable
add_executable(Tutorial tutorial.cxx)
# to link to Tutorial the EXTRA_LIBS, for now only the MathFunctions, if needed, else 
target_link_libraries(Tutorial ${EXTRA_LIBS})

# to install the executable
message(STATUS "Installing the Tutorial executable and header in folder ${CMAKE_INSTALL_PREFIX}")
# place the executable called Tutorial in /usr/local/bin/Tutorial
# so you can then run from any folder Tutorial and the executable will run
# the result will be: -- Installing: /usr/local/bin/Tutorial
install(TARGETS Tutorial DESTINATION bin)
# install the TutorialConfig.h file, so you can use hte header somewhere else
# the result will be: -- Installing: /usr/local/include/TutorialConfig.h
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
