cmake_minimum_required(VERSION 3.10)

project(scpi_exch_example_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_FLAGS -Wall -Wextra -Werror)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
endif()

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/)
set(SOURCES ${SOURCE_DIR}/example_1.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} scpiexch)
