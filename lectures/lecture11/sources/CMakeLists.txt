cmake_minimum_required(VERSION 3.5)

project(5.smart_pointers)

file( GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
message(STATUS "Found source files: " "${SRC} ")

foreach( FILE ${SRC} )
    string( REPLACE ".cpp" "" TARGET ${FILE})
    add_executable( ${TARGET} ${FILE} )
    set_target_properties(${TARGET} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
    set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
    set_target_properties(${TARGET} PROPERTIES LINK_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
endforeach( FILE ${SRC} )
