cmake_minimum_required(VERSION 3.22.1)
project(patd_lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_INCLUDES
        ${PROJECT_SOURCE_DIR}/include
)

include_directories(${PROJECT_INCLUDES})

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${PROJECT_INCLUDES})

add_executable(test src/test.cpp)
target_include_directories(test PRIVATE ${PROJECT_INCLUDES})