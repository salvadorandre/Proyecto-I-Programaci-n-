

#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/controller/EstudianteController.h"
#include <iostream>

using namespace std;

EstudianteController::EstudianteController(EstudianteService estudianteService):estudianteService(estudianteService) {};



    void EstudianteController::buscarEstudiante() {
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

    void EstudianteController::listaEstudiantesOrdenados() {
        cout << "Listando estudiantes..." << endl;
        vector<Estudiante> lista = estudianteService.listaEstudiantesOrdenados();
        for (int i = 0; i < lista.size(); i++) {
            cout << "Nombre: " << lista[i].nombre << endl;
            cout << "Edad: " << lista[i].edad << endl;
            cout << "Género: " << lista[i].genero << endl;
            cout << "Grado: " << lista[i].grado << endl;
            cout << "Promedio: " << lista[i].promedio << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void EstudianteController::crearEstudiantes() {
        Estudiante estudiante;

        cout << "Ingrese un ID para el estudiante" << endl;
        cin >> estudiante.idEstudiante;
        estudiante.active = true;
        cout << "Ingrese la edad" << endl;
        cin >> estudiante.edad;
        cout << "Ingrese el promedio" << endl;
        cin >> estudiante.promedio;
        cin.ignore();
        cout << "Ingrese su nombre" << endl;
        cin.getline(estudiante.nombre, sizeof(estudiante.nombre));
        cout << "Ingrese el género" << endl;
        cin.getline(estudiante.genero, sizeof(estudiante.genero));
        cout << "Ingrese el grado" << endl;
        cin.getline(estudiante.grado, sizeof(estudiante.grado));
       estudiante.active = true;
        cout << "Creando estudiante..." << endl;
        estudianteService.crearEstudiante(estudiante);
    }

    void EstudianteController::buscarPorNombre() {
        string nombre;

        cout << "Ingrese el nombre para buscar coincidencias" << endl;
        cin >> nombre;

        vector<Estudiante> lista = estudianteService.obtenerEstudiantesPorNombre(nombre);

        for (int i = 0; i < lista.size(); i++) {
            cout << "ID: " << lista[i].idEstudiante << endl;
            cout << "Nombre: " << lista[i].nombre << endl;
            cout << "Apellido: " << lista[i].grado << endl;
        }

    }







