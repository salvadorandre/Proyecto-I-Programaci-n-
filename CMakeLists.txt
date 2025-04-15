cmake_minimum_required(VERSION 3.27)
project(ProyectoProgramacion)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProyectoProgramacion main.cpp ./src/services/ProfesorService.cpp ./src/repository/ProfesorRepository.cpp ./src/controller/ProfesorController.cpp)
