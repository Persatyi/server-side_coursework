cmake_minimum_required(VERSION 3.15)
project(server-side_coursework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS OFF)

# Виводити всю відладкову інформацію
set(CMAKE_BUILD_TYPE Debug)

# Шляхи до хедерів
include_directories(
    ${PROJECT_SOURCE_DIR}/src/winsock
    ${PROJECT_SOURCE_DIR}/src/sockets
    ${PROJECT_SOURCE_DIR}/src/connection
)

# Основна програма
add_executable(server 
    src/main.cpp
    src/winsock/winsock_utils.cpp
    src/sockets/socket_utils.cpp
    src/connection/connection_utils.cpp
)

# Шляхи до хедерів для main.cpp
# target_include_directories(server PRIVATE 
#     ${PROJECT_SOURCE_DIR}/src/winsock
#     ${PROJECT_SOURCE_DIR}/src/sockets
#     ${PROJECT_SOURCE_DIR}/src/connection
# )

# Тест
add_executable(test 
    test/basic_test.cpp 
    src/winsock/winsock_utils.cpp
    src/sockets/socket_utils.cpp
    src/connection/connection_utils.cpp
)

# Шляхи до хедерів для тестів
# target_include_directories(test PRIVATE 
#     ${PROJECT_SOURCE_DIR}/src/winsock
#     ${PROJECT_SOURCE_DIR}/src/sockets
#     ${PROJECT_SOURCE_DIR}/src/connection
# )