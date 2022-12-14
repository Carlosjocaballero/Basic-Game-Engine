cmake_minimum_required(VERSION 3.20)

project(final_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DCCGE_WINDOWS)
elseif(APPLE)
	add_definitions(-DCCGE_MAC)
else()
	add_definitions(-DCCGE_LINUX)
endif()

add_definitions(-DCCGE_DEBUG)
add_definitions(-DCCGE_OPENGL)

add_subdirectory(Game)
add_subdirectory(ccGE)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT Game)

file(COPY Game/Assets DESTINATION ${PROJECT_BINARY_DIR}/Game)
file(COPY Game/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Game/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)
