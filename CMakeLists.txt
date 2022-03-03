cmake_minimum_required(VERSION 3.10)

project(LearningCMake VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial-provided math implementations" ON)
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

add_executable(LearningCMake tutorial.cpp)

target_link_libraries(LearningCMake PUBLIC ${EXTRA_LIBS})

configure_file(TutorialConfig.h.in TutorialConfig.hpp)
target_include_directories(LearningCMake PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )

install(TARGETS LearningCMake DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.hpp"
  DESTINATION include
  )