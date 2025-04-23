#include "../../interfaces/repository/AsignacionesRepository.h"
#include "../../interfaces/models/Estudiante.h"
#include "../../interfaces/models/Profesor.h"
#include "../../interfaces/DTOs/Asignacion.h"
#include <cstdio>

AsignacionesRepository::AsignacionesRepository(FILE *file, string fileName) {
    this->fileName = fileName + ".txt";
    this->file = file;


    this->file = fopen(this->fileName.c_str(), "ab");
    if (this->file == nullptr) {
        cout << "Error en la creacion del archivo" << endl;
        return;
    }
    long isNew = ftell(this->file);
    if (isNew == 0) {
        cout << "Archivo creado" << endl;
    } else {
        cout << "El archivo ya existe" << endl;
    }
    fclose(this->file);
}



vector<Asignacion> AsignacionesRepository::getAllAsignaciones() {
    FILE* fileNew = fopen(fileName.c_str(), "rb");

    if (fileNew == nullptr) {
        throw runtime_error("Error a la hora de abrir el archivo file");
    }

    vector<Asignacion> todasLasAsignaciones;
    Asignacion asignacionActual;

    while (fread(&asignacionActual, sizeof(Asignacion), 1, fileNew)) {
        todasLasAsignaciones.push_back(asignacionActual);
    }

    fclose(fileNew);
    return todasLasAsignaciones;
}

int AsignacionesRepository::autoIncrement() {
    FILE* fileNew = fopen(fileName.c_str(), "rb");

    if (fileNew == nullptr) {
        throw runtime_error("Error a la hora de abrir el archivo file");
    }
    Asignacion asignacionActual;
    int idAsignacion = 0;

    while (fread(&asignacionActual, sizeof(Asignacion), 1, fileNew)) {
        idAsignacion = asignacionActual.idAsignacion;
    }

    fclose(fileNew);
    return idAsignacion + 1;
}

bool AsignacionesRepository::coincidencia(int idProfesor, int idEstudiante) {
    FILE* fileNew = fopen(fileName.c_str(), "rb");

    if (fileNew == nullptr) {
        throw runtime_error("Error a la hora de abrir el archivo file");
    }
    Asignacion asignacionActual;
    bool coincidencia = false;

    while (fread(&asignacionActual, sizeof(Asignacion), 1, fileNew)) {
        if (asignacionActual.idProfesor == idProfesor && asignacionActual.idEstudiante == idEstudiante) {
            coincidencia = true;
            fclose(fileNew);
            break;
        }
    }

    fclose(fileNew);
    return coincidencia;
}

bool AsignacionesRepository::postAsignacion(Profesor profesor, Estudiante estudiante) {

    if (coincidencia(profesor.idProfesor, estudiante.idEstudiante)) {

        return false;
    }
    FILE* fileNew = fopen(fileName.c_str(), "ab");
    if (fileNew == nullptr) {
        return false;
    }
    Asignacion asignacion;
    asignacion.idProfesor = profesor.idProfesor;
    asignacion.idEstudiante = estudiante.idEstudiante;
    asignacion.idAsignacion = autoIncrement();

    if (fwrite(&asignacion, sizeof(Asignacion), 1, fileNew) != 1) {
        fclose(fileNew);
        return false;
    }

    fclose(fileNew);
    return true;
}