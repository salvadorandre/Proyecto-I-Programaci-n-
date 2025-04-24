#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"
#include <iostream>
#include "../utils/Cursos.h"
using namespace std;

ProfesorController::ProfesorController(ProfesorService profesorService)
  : profesorService(profesorService) {}

void ProfesorController::buscarProfesor() {
    try{
    int id =0;
    cout << "ingrese el id del profesor a buscar" << endl;
    cin >> id;
    cout << "Buscando profesor..." << endl;
    Profesor profesorObtenido =profesorService.obtenerProfesor(id);
    cout << profesorObtenido.getDetails() << endl;
    }catch (exception &e) {
        cout << e.what() << endl;
    }

}

void ProfesorController::listaProfesores() {

    try {
        cout << "Listando todos los  profesores..." << endl;
        vector<Profesor> lista = profesorService.listaProfesores();
        for ( auto& profesor : lista) {
            cout << profesor.getDetails() << endl;
        }

    }catch (exception &e) {
        cout << e.what() << endl;
    }

}

void ProfesorController::listaProfesores(int curso) {
    try {
        Cursos cursos;
        string materia = cursos.getCursos(curso);
        cout << "Listando todos los profesores del curso: " <<materia<< endl;
        vector<Profesor> lista = profesorService.listaProfesores();
        if (lista.size() == 0) {
            cout << "Profesores lista vacia" << endl;
            return;
        }
        int materiaId = cursos.getCursosId(curso);
        int total =0;
        for ( auto& profesor : lista) {
            if (profesor.fkCurso == materiaId) {
                cout << profesor.getDetails() << endl;
                total++;
            }
        }
        if (total == 0) {
            cout << "Profesores lista vacia" << endl;
            return;
        }

    }catch (exception &e) {
        cout << e.what() << endl;
    }

}

void ProfesorController::crearProfesores() {
   try {
       Profesor profesor;
       Cursos curso;
       cout << "coloque un Id para el profesor: "<< endl;
       cin>>profesor.idProfesor;
       profesor.active=true;
       profesor.fkCurso= curso.getCursos();
       cout << "ingrese la capacidad maxima de alumnos de este profesor " << endl;
       cin>>profesor.alumnMax;
       if (profesor.alumnMax > 100 || profesor.alumnMax < 1) {
           cout<<"capacidad no soportada"<< endl;
           profesor.alumnMax = 10;
       }
       cin.ignore();
       cout << "ingrese su nombre: " << endl;
       cin.getline(profesor.nombre,sizeof(profesor.nombre));
       cout << "Creando profesor..." << endl;
       profesorService.crearProfesor(profesor);
   }catch (exception &e) {
       cout << e.what() << endl;
   }
}
