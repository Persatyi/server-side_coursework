cmake_minimum_required(VERSION 3.15)
project(server-side_coursework)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS OFF)

# Основна програма
add_executable(server 
    src/main.cpp
    src/winsock/winsock_utils.cpp
)

# Тест
add_executable(winsock_test 
    test/basic_test.cpp 
    src/winsock/winsock_utils.cpp
)