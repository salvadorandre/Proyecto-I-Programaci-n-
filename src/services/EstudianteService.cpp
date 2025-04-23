//
// Created by Daniel on 10/04/2025.
//

#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/repository/EstudianteRepository.h"
#include "../../interfaces/models/Estudiante.h"
#include <stdexcept>
#include <iostream>
#include <cstdio>

using namespace std;

EstudianteService::EstudianteService(const EstudianteRepository &estudianteRepository):repository(estudianteRepository) {}

string EstudianteService::crearEstudiante(Estudiante estudiante) {
    try {
        repository.putEstudiante(estudiante);
        return "Se ha creado un neuvo estudiante"+estudiante.getDetails();
    }catch (invalid_argument e) {
        cout << e.what() << endl;
        return "No se creo el estudiante";
    }
}

Estudiante EstudianteService::obtenerEstudiante(int idEstudiante) {

    try{
        Estudiante estudiante = repository.getEstudianteById(idEstudiante);
        if (estudiante.idEstudiante == -1) {
            throw invalid_argument("No se ha encontrado al estudiante deseado");
        }
        return estudiante;
    }catch (invalid_argument e) {
        cout << e.what() << endl;
    }
}

vector<Estudiante> EstudianteService::listaEstudiantes() {
    try {
        vector<Estudiante>list = repository.getAllEstudiante();
        return  list;
    }catch (invalid_argument e) {
        cout << e.what() << endl;
    }
}

string EstudianteService::eliminarEstudiante(int idEstudiante) {
    try {
        repository.deleteEstudiante(idEstudiante);
        return "Estudiante eliminado exitosamente.";
    }catch (invalid_argument e) {
        cout << e.what() << endl;
        return "Error, no se puedo eliminar al estudiante" << endl;
    }
}
