cmake_minimum_required(VERSION 3.30)
project(Sistema_rede_simples_teste)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(server server.cpp connection.cpp)
target_link_libraries(server ${Boost_LIBRARIES})

add_executable(client client.cpp)
target_link_libraries(client ${Boost_LIBRARIES})

add_executable(main main.cpp)
