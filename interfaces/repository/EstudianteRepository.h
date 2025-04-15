#ifndef ESTUDIANTEREPOSITORY_H
#define ESTUDIANTEREPOSITORY_H

#include <vector>
#include <string>
#include <cstdio>
#include "../../interfaces/models/Estudiante.h"

using namespace std;

class EstudianteRepository {
private:
    string fileName;

public:
    explicit EstudianteRepository(const string& nombreArchivo = "estudiantes.dat");

    bool putEstudiante(const Estudiante& estudiante);
    Estudiante getEstudianteByNombre(const string& nombre);
    vector<Estudiante> getAllEstudiantes();
    bool deleteEstudiante(const string& nombre);
};

#endif // ESTUDIANTEREPOSITORY_H
