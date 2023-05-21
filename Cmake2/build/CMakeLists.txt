cmake_minimum_required(VERSION 3.19.2)

project("bank")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES ../srcs/*.cpp)
file(GLOB HEADERS ../incl/*.hpp)
list(APPEND HEADERS ../../Headers.hpp)

add_executable("bank" ${SOURCES} ${HEADERS})
