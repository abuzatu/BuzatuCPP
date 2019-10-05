# add the creation of a static library called libMathFunctions.a
add_library(MathFunctions mysqrt.cxx)

# to install our math library
message(STATUS "Installing MathFunctions library and header in folder ${CMAKE_INSTALL_PREFIX}")
# the result will be: -- Installing: /usr/local/bin/libMathFunctions.a
install(TARGETS MathFunctions DESTINATION bin)
# the result will be:  /usr/local/include/MathFunctions.h
install(FILES MathFunctions.h DESTINATION include)
