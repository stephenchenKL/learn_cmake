#include <iostream>
#include "cmakeTutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <cmath>
#endif

int main(){

    std::cout << "Learn cmake\n";

    std::cout << " Version " << cmakeTutorial_VERSION_MAJOR << "."
              << cmakeTutorial_VERSION_MINOR << std::endl;

#ifdef USE_MYMATH
    std::cout <<"mysqrt(4) = " << mysqrt(4);
#else
    std::cout <<"sqrt(4) = "  << sqrt(4);
#endif

    return 0;
}