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

vector<Estudiante> EstudianteService::obtenerEstudiantesPorNombre(string nombre) {
    try {
        vector<Estudiante> estudiantes = repository.getEstudiantesByNombre(nombre);

        if (estudiantes.empty()) {
            throw invalid_argument("No se encontraron estudiantes con ese nombre.");
        }

        return estudiantes;
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
        return {};
    }
}


vector<Estudiante> EstudianteService::listaEstudiantesOrdenados() {
    try {
        vector<Estudiante> list = repository.getAllEstudiante();

        for (int i = 1; i < list.size(); ++i) {
            Estudiante key = list[i];
            int j = i - 1;

            while (j >= 0 && list[j].idEstudiante > key.idEstudiante) {
                list[j + 1] = list[j];
                j--;
            }

            list[j + 1] = key;
        }

        return list;
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
        return {};
    }
}


string EstudianteService::eliminarEstudiante(int idEstudiante) {
    try {
        repository.deleteEstudiante(idEstudiante);
        return "Estudiante eliminado exitosamente.";
    }catch (invalid_argument e) {
        cout << e.what() << endl;
        return "Error, no se puedo eliminar al estudiante";
    }
}
