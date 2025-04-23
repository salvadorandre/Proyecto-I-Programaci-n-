//
// Created by Daniel on 10/04/2025.
//

#ifndef ESTUDIANTE_SERVICE_H
#define ESTUDIANTE_SERVICE_H

#include "../repository/EstudianteRepository.h"

class EstudianteService {
    EstudianteRepository repository;

public:
    EstudianteService(const EstudianteRepository &estudianteRepository);
    string crearEstudiante(Estudiante estudiante);
    Estudiante obtenerEstudiante(int idEstudiante);
    vector<Estudiante> obtenerEstudiantesPorNombre(string nombre);
    vector<Estudiante> listaEstudiantesOrdenados();
    string eliminarEstudiante(int idEstudiante);
};

#endif //ESTUDIANTE_SERVICE_H
