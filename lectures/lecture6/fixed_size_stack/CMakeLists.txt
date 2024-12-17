cmake_minimum_required (VERSION 3.22)

SET(TASK_NAME fixed_size_stack)


################################
# build tests
################################

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

include_directories(${GTEST_INCLUDE_DIRS})

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  ${TASK_NAME}
  tests.cpp
)

target_include_directories(
  ${TASK_NAME}
  PRIVATE  
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ${TASK_NAME}
  GTest::gtest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TASK_NAME})