cmake_minimum_required (VERSION 3.12)
project(task4 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

################################
# build source
################################

add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/template_vector.hpp
)

################################
# build tests
################################

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()


add_executable(
  tests_run
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_template_vector.cpp
)

target_include_directories(tests_run
  PRIVATE  
  ${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries(
  tests_run
  GTest::gtest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests_run)