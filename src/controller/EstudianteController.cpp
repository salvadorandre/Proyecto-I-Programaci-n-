#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H

#include "../../interfaces/services/EstudianteService.h"
#include <iostream>

using namespace std;

class EstudianteController {
    EstudianteService estudianteService;

public:
    EstudianteController(EstudianteService estudianteService)
        : estudianteService(estudianteService) {}

    void buscarEstudiante() {
        int id = 0;
        cout << "Ingrese el ID del estudiante a buscar" << endl;
        cin >> id;
        cout << "Buscando estudiante..." << endl;
        Estudiante estudianteObtenido = estudianteService.obtenerEstudiante(id);
        cout << "Nombre: " << estudianteObtenido.nombre << endl;
        cout << "Edad: " << estudianteObtenido.edad << endl;
        cout << "Género: " << estudianteObtenido.genero << endl;
        cout << "Grado: " << estudianteObtenido.grado << endl;
        cout << "Promedio: " << estudianteObtenido.promedio << endl;
    }

    void listaEstudiantes() {
        cout << "Listando estudiantes..." << endl;
        vector<Estudiante> lista = estudianteService.listaEstudiantes();
        for (int i = 0; i < lista.size(); i++) {
            cout << "Nombre: " << lista[i].nombre << endl;
            cout << "Edad: " << lista[i].edad << endl;
            cout << "Género: " << lista[i].genero << endl;
            cout << "Grado: " << lista[i].grado << endl;
            cout << "Promedio: " << lista[i].promedio << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void crearEstudiantes() {
        Estudiante estudiante;

        cout << "Ingrese un ID para el estudiante" << endl;
        cin >> estudiante.idEstudiante;
        estudiante.active = true;
        cin.ignore();
        cout << "Ingrese su nombre" << endl;
        cin.getline(estudiante.nombre, sizeof(estudiante.nombre));
        cout << "Ingrese la edad" << endl;
        cin >> estudiante.edad;
        cin.ignore();
        cout << "Ingrese el género" << endl;
        cin.getline(estudiante.genero, sizeof(estudiante.genero));
        cout << "Ingrese el grado" << endl;
        cin.getline(estudiante.grado, sizeof(estudiante.grado));
        cout << "Ingrese el promedio" << endl;
        cin >> estudiante.promedio;

        cout << "Creando estudiante..." << endl;
        estudianteService.crearEstudiante(estudiante);
    }
};

#endif // ESTUDIANTECONTROLLER_H
