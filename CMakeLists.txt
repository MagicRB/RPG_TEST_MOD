cmake_minimum_required(VERSION 2.8.9)
project(RPG_TEST_MOD)

set(CMAKE_CXX_STANDARD 11)

include_directories(include external-include)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_library(RPG_TEST_MOD SHARED ${SOURCES})

set_target_properties(RPG_TEST_MOD PROPERTIES PREFIX "")

#target_link_libraries(RPG_TEST_MOD sfml-window sfml-graphics sfml-system dl)