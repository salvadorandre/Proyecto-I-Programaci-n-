

#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/controller/EstudianteController.h"
#include <iostream>
#include <string.h>

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
        int genero, grado;
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


        do {
            cout << "Ingrese el genero:" << endl;
            cout << "1. Masculino, 2. Femenino" << endl;
            cin >> genero;

            if (genero == 1) {
                strcpy(estudiante.genero, "Masculino");
            }else if (genero == 2) {
                strcpy(estudiante.genero, "Femenino");
            }else {
                cout << "Genero no valido" << endl;
            }

        }while (genero!=1 && genero!=2);


        do {
            cout << "Ingrese el grado" << endl;
            cout << "1. 1ro Basico, 2. 2do Basico, 3. 3ro Basico" << endl;
            cout << "4. 4to Bach, 5. 5to Bach" << endl;

            cin >> grado;

            switch (grado) {
                case 1:
                    strcpy(estudiante.grado, "1ro Basico");
                    break;
                case 2:
                    strcpy(estudiante.grado, "2do Basico");
                    break;
                case 3:
                    strcpy(estudiante.grado, "3ro Basico");
                    break;
                case 4:
                    strcpy(estudiante.grado, "4to Bach");
                    break;
                case 5:
                    strcpy(estudiante.grado, "5to Bach");
                    break;
                default:
                    cout << "Grado no valido" << endl;
                    break;
            }
        }while (grado >= 0 || grado >=6);

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







