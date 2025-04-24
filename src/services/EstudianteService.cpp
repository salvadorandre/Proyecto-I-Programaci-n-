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

        repository.putEstudiante(estudiante);
        return "Se ha creado un neuvo estudiante"+estudiante.getDetails();

}

Estudiante EstudianteService::obtenerEstudiante(int idEstudiante) {


        Estudiante estudiante = repository.getEstudianteById(idEstudiante);
        if (estudiante.idEstudiante == -1) {
            throw invalid_argument("No se ha encontrado al estudiante deseado");
        }
        return estudiante;

}

vector<Estudiante> EstudianteService::obtenerEstudiantesPorNombre(string nombre) {

        vector<Estudiante> estudiantes = repository.getEstudiantesByNombre(nombre);

        if (estudiantes.empty()) {
            throw invalid_argument("No se encontraron estudiantes con ese nombre.");
        }

        return estudiantes;

}


vector<Estudiante> EstudianteService::listaEstudiantesOrdenados() {

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

}


string EstudianteService::eliminarEstudiante(int idEstudiante) {

        repository.deleteEstudiante(idEstudiante);
        return "Estudiante eliminado exitosamente.";

}
