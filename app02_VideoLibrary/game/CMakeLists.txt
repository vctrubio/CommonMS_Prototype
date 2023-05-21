cmake_minimum_required(VERSION 3.19.2)
project(cube)

set(CMAKE_C_STANDARD 11)

file(GLOB SRCS srcs/*.c)
file(GLOB HEADERS include/*.h)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lmlx/libmlx.a)
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework AppKit")

execute_process(
  COMMAND make re
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lmlx
)