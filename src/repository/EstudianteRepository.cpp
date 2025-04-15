#include "../../interfaces/repository/EstudianteRepository.h"
#include "../../interfaces/models/estudiante.h"
#include <iostream>

EstudianteRepository::EstudianteRepository(const string& nombreArchivo) {
    fileName = nombreArchivo;
}

bool EstudianteRepository::putEstudiante(const Estudiante& estudiante) {
    FILE* file = fopen(fileName.c_str(), "ab");  // append binario
    if (!file) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return false;
    }

    fwrite(&estudiante, sizeof(Estudiante), 1, file);
    fclose(file);
    return true;
}

Estudiante EstudianteRepository::getEstudianteByNombre(const string& nombre) {
    FILE* file = fopen(fileName.c_str(), "rb");
    Estudiante estudiante{};

    if (!file) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return estudiante;
    }

    while (fread(&estudiante, sizeof(Estudiante), 1, file)) {
        if (estudiante.nombre == nombre) {
            fclose(file);
            return estudiante;
        }
    }

    fclose(file);
    estudiante.nombre = ""; // Devuelve un estudiante "vacío" si no se encontró
    return estudiante;
}

vector<Estudiante> EstudianteRepository::getAllEstudiantes() {
    FILE* file = fopen(fileName.c_str(), "rb");
    vector<Estudiante> estudiantes;
    Estudiante temp;

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return estudiantes;
    }

    while (fread(&temp, sizeof(Estudiante), 1, file)) {
        estudiantes.push_back(temp);
    }

    fclose(file);
    return estudiantes;
}

bool EstudianteRepository::deleteEstudiante(const string& nombre) {
    FILE* file = fopen(fileName.c_str(), "rb");
    FILE* tempFile = fopen("temp.dat", "wb");
    bool eliminado = false;

    if (!file || !tempFile) {
        cerr << "No se pudo abrir uno de los archivos." << endl;
        return false;
    }

    Estudiante temp;
    while (fread(&temp, sizeof(Estudiante), 1, file)) {
        if (temp.nombre != nombre) {
            fwrite(&temp, sizeof(Estudiante), 1, tempFile);
        } else {
            eliminado = true;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(fileName.c_str());
    rename("temp.dat", fileName.c_str());

    return eliminado;
}
