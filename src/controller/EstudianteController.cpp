//
// Created by Marco Lacán on 14/04/2025.
//

#include "../../interfaces/controller/EstudianteController.h"

EstudianteController::EstudianteController() : repo("estudiantes.dat") {}

bool EstudianteController::agregarEstudiante(const Estudiante& estudiante) {
    // Verificar si ya existe antes de agregar
    Estudiante existente = repo.getEstudianteByNombre(estudiante.nombre);
    if (existente.nombre != "") {
        return false; // Ya existe
    }
    return repo.putEstudiante(estudiante);
}

vector<Estudiante> EstudianteController::obtenerTodos() {
    return repo.getAllEstudiantes();
}

Estudiante EstudianteController::buscarPorNombre(const string& nombre) {
    return repo.getEstudianteByNombre(nombre);
}

bool EstudianteController::eliminarPorNombre(const string& nombre) {
    return repo.deleteEstudiante(nombre);
}
