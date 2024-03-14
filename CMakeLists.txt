cmake_minimum_required(VERSION 3.15)
project(wedserver)
include_directories(
    ${PROJECT_SOURCE_DIR}/common
    ${PROJECT_SOURCE_DIR}/http
    ${PROJECT_SOURCE_DIR}/thread
    ${PROJECT_SOURCE_DIR}/tcp
    ${PROJECT_SOURCE_DIR}/reactor
)

add_subdirectory(tcp)
add_subdirectory(common)
add_subdirectory(thread)
add_subdirectory(http)
add_subdirectory(reactor)
link_directories(${PROJECT_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(server main.cpp)
target_link_libraries(server tcp)