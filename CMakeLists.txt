cmake_minimum_required(VERSION 3.14)
project(determinant)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_compile_options(-O3 -Wall -Werror)
add_executable(determinant
  src/main.cpp
  src/matrix.cpp
  src/determinant.cpp
)

add_executable(determinant_tests
  src/matrix.cpp
  src/determinant.cpp
  tests/tests.cpp  
)

target_link_libraries(determinant_tests
  PRIVATE
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(determinant_tests)