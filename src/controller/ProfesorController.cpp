#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"
#include <iostream>

using namespace std;

ProfesorController::ProfesorController(ProfesorService profesorService)
  : profesorService(profesorService) {}

void ProfesorController::buscarProfesor() {
    cout << "Buscando profesor..." << endl;
    //recibir parametros por cin y getline
    //usar service

}

void ProfesorController::listaProfesores() {
    cout << "Listando profesores..." << endl;
    //recibir parametros por cin y getline
    //usar service
}

void ProfesorController::crearProfesores() {
    cout << "Creando profesor..." << endl;
    profesorService.crearProfesor();//ejemplo
    //recibir parametros por cin y getline
    //usar service
}
