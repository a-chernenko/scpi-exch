cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME socketapi)
set(PROJECT_LANGUAGES C)

project(${PROJECT_NAME} ${PROJECT_LANGUAGES})

set(SOURCES
	src/socket_api_high.c
	src/socket_api_low.c
)

set(HEADERS
	include/socket_api_high.h
	include/socket_api_low.h
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

if(WIN32)
target_link_libraries(${PROJECT_NAME} "ws2_32")
endif(WIN32)

if (CMAKE_SYSTEM MATCHES QNX)
target_link_libraries(${PROJECT_NAME} socket)
endif(CMAKE_SYSTEM MATCHES QNX)

if (CMAKE_SYSTEM_NAME MATCHES Linux)
target_link_libraries(${PROJECT_NAME} rt)
endif(CMAKE_SYSTEM_NAME MATCHES Linux)

