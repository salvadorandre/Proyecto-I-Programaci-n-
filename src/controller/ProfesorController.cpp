#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"
#include <iostream>

using namespace std;

ProfesorController::ProfesorController(ProfesorService profesorService)
  : profesorService(profesorService) {}

void ProfesorController::buscarProfesor() {
    int id =0;
    cout << "ingrese el id del profesor a buscar" << endl;
    cin >> id;
    cout << "Buscando profesor..." << endl;
    Profesor profesorObtenido =profesorService.obtenerProfesor(id);
    cout << profesorObtenido.getDetails() << endl;

}

void ProfesorController::listaProfesores() {
    cout << "Listando profesores..." << endl;
    vector<Profesor> lista = profesorService.listaProfesores();
    for ( auto& profesor : lista) {
        cout << profesor.getDetails() << endl;
    }

}

void ProfesorController::crearProfesores() {
    Profesor profesor;

    cout << "coloque un Id para el profesor: "<< endl;
    cin>>profesor.idProfesor;
    profesor.active=true;
    cin.ignore();
    cout << "ingrese su nombre: " << endl;
    cin.getline(profesor.nombre,sizeof(profesor.nombre));
    cout << "Creando profesor..." << endl;
    profesorService.crearProfesor(profesor);
}
