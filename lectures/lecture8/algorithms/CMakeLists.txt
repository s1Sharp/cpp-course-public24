cmake_minimum_required(VERSION 3.22)

project(STL_algorithms)

file( GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
message(STATUS "Found source files: " ${SRC})

foreach( FILE ${SRC} )
    string( REPLACE ".cpp" "" TARGET ${FILE} )
    add_executable( ${TARGET} ${FILE} )
    set_target_properties(${TARGET} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
endforeach( FILE ${SRC} )