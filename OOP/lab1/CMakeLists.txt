cmake_minimum_required(VERSION 3.20)
project(flatmap_project)

set(SOURCES
  flatmap.cpp
  flat_map_test.cpp
)
set(HEADERS
  flatmap.h
  Vector.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})