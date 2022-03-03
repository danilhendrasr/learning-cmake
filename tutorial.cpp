// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "TutorialConfig.hpp"

#ifdef USE_MYMATH
#include "MathFunctions.hpp"
#endif

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << LearningCMake_VERSION_MAJOR << "."
      << LearningCMake_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  // calculate square root
  const double outputValue = sqrt(inputValue);
#endif

  std::cout << "The sqrt of " << inputValue << " is " << outputValue
    << std::endl;
  return 0;
}
