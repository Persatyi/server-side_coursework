cmake_minimum_required(VERSION 3.15)
project(server-side_coursework)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS OFF)

# Основна програма
add_executable(server 
    src/main.cpp
    src/winsock/winsock_utils.cpp
    src/sockets/socket_utils.cpp
)

# Шляхи до хедерів для main.cpp
target_include_directories(server PRIVATE 
    ${PROJECT_SOURCE_DIR}/src/winsock
    ${PROJECT_SOURCE_DIR}/src/sockets
)

# Тест
add_executable(test 
    test/basic_test.cpp 
    src/winsock/winsock_utils.cpp
    src/sockets/socket_utils.cpp
)

# Шляхи до хедерів для тестів
target_include_directories(test PRIVATE 
    ${PROJECT_SOURCE_DIR}/src/winsock
    ${PROJECT_SOURCE_DIR}/src/sockets
)