//
// Created by Daniel on 10/04/2025.
//

#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/repository/EstudianteRepository.h"
#include "../../interfaces/models/Estudiante.h"
#include <stdexcept>
#include <cstdio>

using namespace std;

EstudianteService::EstudianteService(const EstudianteRepository &estudianteRepository) {
    this->repository = estudianteRepository;
}

string EstudianteService::crearEstudiante(Estudiante estudiante) {
    bool resultado = repository.putEstudiante(estudiante);
    if (resultado) {
        return "Estudiante creado exitosamente.";
    } else {
        return "Error: El estudiante ya existe.";
    }
}

Estudiante EstudianteService::obtenerEstudiante(int idEstudiante) {
    Estudiante estudiante = repository.getEstudianteById(idEstudiante);
    if (estudiante.idEstudiante == -1) {
        throw invalid_argument("Estudiante no encontrado.");
    }
    return estudiante;
}

vector<Estudiante> EstudianteService::listaEstudiantes() {
    return repository.getAllEstudiante();
}

string EstudianteService::eliminarEstudiante(int idEstudiante) {
    bool resultado = repository.deleteEstudiante(idEstudiante);
    if (resultado) {
        return "Estudiante eliminado exitosamente.";
    } else {
        return "Error: No se pudo eliminar el estudiante.";
    }
}
