# add the creation of the executable that produces the table of sqrt for several values
add_executable(MakeTable MakeTable.cxx)

# add the command to generate the source code
# https://cmake.org/cmake/help/latest/command/add_custom_command.html
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)

# add the binary tree directory to the search path for include files
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# add the creation of a static library called libMathFunctions.a
add_library(MathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

# to install our math library
message(STATUS "Installing MathFunctions library and header in folder ${CMAKE_INSTALL_PREFIX}")
# the result will be: -- Installing: /usr/local/bin/libMathFunctions.a
install(TARGETS MathFunctions DESTINATION bin)
# the result will be:  /usr/local/include/MathFunctions.h
install(FILES MathFunctions.h DESTINATION include)
# the result will be: -- Installing: /usr/local/include/Table.h
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/Table.h" DESTINATION include)
