//
// Created by Daniel on 10/04/2025.
//

#ifndef REPOSITORYESTUDIANTE_H
#define REPOSITORYESTUDIANTE_H

#include <vector>
#include <cstdio>

#include "../../interfaces/models/Estudiante.h"

class EstudianteRepository {
    FILE *file;
    string fileName;

public:
    EstudianteRepository(FILE *file, string fileName);
    bool putEstudiante(Estudiante estudiante);
    Estudiante getEstudianteById(int idEstudiante);
    vector<Estudiante> getAllEstudiante();
    bool deleteEstudiante(int idEstudiante);
    vector<Estudiante> getEstudiantesByNombre(string nombre);
    FILE* getFile(string metod);
};

#endif //REPOSITORYESTUDIANTE_H
