//
// Created by Marco Lacán on 14/04/2025.
//

#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H
#include "../../interfaces/repository/EstudianteRepository.h"

class EstudianteController {
private:
    EstudianteRepository repo;

public:
    EstudianteController();

    bool agregarEstudiante(const Estudiante& estudiante);
    vector<Estudiante> obtenerTodos();
    Estudiante buscarPorNombre(const string& nombre);
    bool eliminarPorNombre(const string& nombre);
};

#endif //ESTUDIANTECONTROLLER_H
