cmake_minimum_required(VERSION 3.27)
project(ProyectoProgramacion)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProyectoProgramacion main.cpp
        src/models/Profesor.cpp
        src/repository/ProfesorRepository.cpp
        src/services/ProfesorService.cpp)
