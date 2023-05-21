cmake_minimum_required(VERSION 3.13.4)

set(PROJECT_NAME "cube")

project(${PROJECT_NAME})

file(GLOB SRCS srcs/*.c)
file(GLOB HEADERS include/*.h)

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lmlx/libmlx.a)
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework AppKit")

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
)

execute_process(
  COMMAND make re
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../lmlx"
)