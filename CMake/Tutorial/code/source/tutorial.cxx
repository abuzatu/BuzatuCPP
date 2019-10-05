// A simple program that computes the square root of a number

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// this include makes available to the code the variables
// Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR
// USE_MYMATH
#include "TutorialConfig.h"

// if we want to use our own math library (defined in main CMakeLists.txt)
// then include the header, else do not
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

// main
int main (int argc, char *argv[])
{
  fprintf(stdout,"%s Running code with version major.minor=%d.%d\n",
	  argv[0],
	  Tutorial_VERSION_MAJOR,
	  Tutorial_VERSION_MINOR
	  );
#ifdef USE_MYMATH
  fprintf(stdout,"The CMakeLists.txt file says we use our own math library.\n");
#else
  fprintf(stdout,"The CMakeLists.txt file says we use the C++ already defined math libray.\n");
#endif
  if (argc < 2)
    {
      fprintf(stdout,"Usage: %s number\n",argv[0]);
      return 1;
    }
  // if we want to use our own math library (defined in main CMakeLists.txt)
  // use our function mysqrt(), else use the C++ existing sqrt()
  double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif
  fprintf(stdout,"The square root of %g is %g\n",
    inputValue, outputValue);
  return 0;
}
