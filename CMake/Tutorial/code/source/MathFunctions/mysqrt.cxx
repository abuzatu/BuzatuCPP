#include <stdio.h>
#include <math.h>
// to make available in the code variables that are taken originally from the CMakeLists.txt
#include "TutorialConfig.h"

double mysqrt(double inputValue) {
  if (inputValue<0) {
    return 0.0;
  } else {
#if defined (HAVE_EXP) && defined (HAVE_LOG)
    printf("We have exp and log, so we use return exp(log(inputValue)*0.5);\n");
    return exp(log(inputValue)*0.5);
#else
    printf("We don't have exp and log, so we use return sqrt(inputValue);\n");
    return sqrt(inputValue);
#endif
  }
}
