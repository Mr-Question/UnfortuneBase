cmake_minimum_required(VERSION 3.1.0)
project(UnfortuneBase VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED True)

set (PROJECT_ROOT_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURCE_FILES
  "${PROJECT_ROOT_DIR}/*.cpp"
  "${PROJECT_ROOT_DIR}/*.h")

include_directories(${PROJECT_ROOT_DIR})

add_library               (${PROJECT_NAME} INTERFACE)
target_sources            (${PROJECT_NAME} INTERFACE ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_ROOT_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})

# Workaround for header-only libraries to display source files in IDEs
add_custom_target(${PROJECT_NAME}_IDE SOURCES ${SOURCE_FILES})
