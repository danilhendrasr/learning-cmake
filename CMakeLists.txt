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

enable_testing()

add_test(NAME Runs COMMAND LearningCMake 25)

add_test(NAME Usage COMMAND LearningCMake)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
  )
endfunction()

do_test(LearningCMake 4 "4 is 2")
do_test(LearningCMake 9 "9 is 3")
do_test(LearningCMake 5 "5 is 2.236")
do_test(LearningCMake 7 "7 is 2.645")
do_test(LearningCMake 25 "25 is 5")
do_test(LearningCMake -25 "-25 is (-nan|nan|0)")
do_test(LearningCMake 0.0001 "0.0001 is 0.01")