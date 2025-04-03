cmake_minimum_required (VERSION 3.22)
project(figure_example VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

################################
# build source
################################

add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/figure_example.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Circle.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Rect.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Triangle.cpp
)
