// A simple program that computes the square root of a number
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "TutorialConfig.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << LearningCMake_VERSION_MAJOR << "."
      << LearningCMake_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = atof(argv[1]);

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The sqrt of " << inputValue << " is " << outputValue
    << std::endl;
  return 0;
}
