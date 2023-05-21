cmake_minimum_required(VERSION 3.13.4)

set(PROJECT_NAME "library")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SOURCES ../srcs/*.cpp)
file(GLOB HEADERS ../incl/*.hpp)
list(APPEND HEADERS ../../Headers.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_compile_options(${PROJECT_NAME} PRIVATE -W -Werror -Wextra)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
)

execute_process(
    COMMAND cmake --build .
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../game/build"
)
