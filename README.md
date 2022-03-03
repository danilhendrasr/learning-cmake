# Learning CMake
The tutorial can be found in the following link: https://cmake.org/cmake/help/v3.22/guide/tutorial/index.html.

## How to run
Just copy the following script to your terminal. It will immediately runs the program once done building & installing.
```bash
git clone https://github.com/danilhendrasr/learning-cmake
cd learning-cmake
mkdir build && cd build
cmake ../ -DUSE_MYMATH=OFF && cmake --build . && cmake --install .
LearningCMake 25
```
