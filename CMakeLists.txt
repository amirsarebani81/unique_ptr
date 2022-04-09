cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b007c54f2944e193ac44fba1bc997cb65826a0b9.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_options(-fsanitize=address --coverage)
add_link_options(-fsanitize=address --coverage)

enable_testing()

add_executable(
  unique_ptr_test
  ./unique_ptr.hpp
  ./unique_ptr_test.cpp
)

target_link_libraries(
  unique_ptr_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(unique_ptr_test)