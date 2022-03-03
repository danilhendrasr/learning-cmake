cmake_minimum_required(VERSION 3.10)

project(LearningCMake VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(LearningCMake tutorial.cpp)

configure_file(TutorialConfig.h.in TutorialConfig.hpp)
target_include_directories(LearningCMake PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )