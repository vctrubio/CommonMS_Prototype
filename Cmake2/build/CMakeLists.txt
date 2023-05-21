cmake_minimum_required(VERSION 3.19.2)

project("bank")

file(GLOB SOURCES ../srcs/*.cpp)
file(GLOB HEADERS ../incl/*.hpp)
list(APPEND HEADERS ../../Headers.hpp)

add_executable("bank" $(SOURCES))
