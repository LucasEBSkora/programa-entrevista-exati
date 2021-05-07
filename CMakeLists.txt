cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(programa-entrevista-exati VERSION 1.0.0)

add_executable(simsem.exe source/main.cpp source/semaforo.cpp source/desenhador.cpp source/sincronizador.cpp source/simulador.cpp)
target_include_directories(simsem.exe PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(simsem.exe PRIVATE Threads::Threads)