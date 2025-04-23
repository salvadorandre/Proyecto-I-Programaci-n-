//
// Created by Admin on 21/04/2025.
//

#ifndef ASIGNACIONESREPOSITORY_H
#define ASIGNACIONESREPOSITORY_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "../../interfaces/models/Profesor.h"
#include "../../interfaces/models/Estudiante.h"
#include "../../interfaces/DTOs/Asignacion.h"
using namespace std;

class AsignacionesRepository {
    FILE *file;
    string fileName;

public:
    AsignacionesRepository(FILE *file,string fileName);

    FILE *getFile(string mode);

    int autoIncrement();
    bool coincidencia(int idProfesor,int idEstudiante);
    bool postAsignacion(Profesor profesor, Estudiante estudiante);
    vector<Asignacion> getAllAsignaciones();
};



#endif //ASIGNACIONESREPOSITORY_H
