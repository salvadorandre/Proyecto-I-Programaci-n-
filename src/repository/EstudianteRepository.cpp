//
// Created by Daniel on 10/04/2025.
//

#include "../../interfaces/repository/EstudianteRepository.h"
#include "../../interfaces/models/Estudiante.h"
#include "vector"
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

EstudianteRepository::EstudianteRepository(FILE *file, string fileName) {
    this->fileName = fileName + ".txt";
    this->file = file;

    file = fopen(this->fileName.c_str(), "a");
    if (file == nullptr) {
        cout<<"Error en la creacion del archivo"<<endl;
    }
    long isNew = ftell(file);
    if(isNew == 0) {
        cout<<"Archivo creado"<<endl;

    }
    else {
        cout<<"El archivo ya existe"<<endl;
    }

    fclose(file);
}

FILE* EstudianteRepository::getFile(string mode) {
    FILE* fileNew = fopen(fileName.c_str(), "r");
    if (!fileNew) {
        throw invalid_argument("No se pudo abrir el archivo");
    }
    fclose(fileNew);
    fileNew = fopen(fileName.c_str(), mode.c_str());
    return fileNew;
}

Estudiante EstudianteRepository::getEstudianteById(int idEstudiante) {
    file = getFile("r");
    Estudiante estudianteFind;
    Estudiante estudianteNotFound;
    while(fread(&estudianteFind, sizeof(Estudiante), 1, file)) {
        if (estudianteFind.idEstudiante == idEstudiante) {
            if (estudianteFind.active == true) {
                fclose(file);
                return estudianteFind;
            }
            break;
        }
    }
    fclose(file);
    estudianteNotFound.idEstudiante = -1;
    return estudianteNotFound;
}

// Métodos solo para manipular archivos
bool EstudianteRepository::putEstudiante(Estudiante estudiante) {
    int foundEstudiante = getEstudianteById(estudiante.idEstudiante).idEstudiante;
    if (foundEstudiante != -1) return false;

    file = getFile("ab"); // para abrir el archivo en modo append
    fwrite(&estudiante, sizeof(Estudiante), 1, file);
    fclose(file);
    return true;
}

vector<Estudiante> EstudianteRepository::getAllEstudiante() {
    vector<Estudiante> estudiantes;
    Estudiante estudiante;
    file = getFile("r");

    while(fread(&estudiante, sizeof(Estudiante), 1, file)) {
        estudiantes.push_back(estudiante);
    }

    fclose(file);
    return estudiantes;
}

bool EstudianteRepository::deleteEstudiante(int idEstudiante) {
    Estudiante foundEstudiante = getEstudianteById(idEstudiante);
    if (foundEstudiante.idEstudiante == -1) return false;

//    file = getFile("r+b"); // para abrir el archivo en modo lectura y escritura binaria
//    Estudiante estudianteDelete;
//    while(fread(&estudianteDelete, sizeof(Estudiante), 1, file)) {
//        if (estudianteDelete.idEstudiante == idEstudiante) {
//            estudianteDelete.active = false;
//            fseek(file, -sizeof(Estudiante), SEEK_CUR);  // Coloca el puntero en la posición correcta para sobrescribir
//            fwrite(&estudianteDelete, sizeof(Estudiante), 1, file);
//            fclose(file);
//            return true;
//        }
//    }

    fclose(file);
    return false;
}
