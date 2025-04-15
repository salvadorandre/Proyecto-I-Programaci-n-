#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"
#include <iostream>

using namespace std;

ProfesorController::ProfesorController(ProfesorService profesorService)
  : profesorService(profesorService) {}

void ProfesorController::buscarProfesor() {
    cout << "Buscando profesor..." << endl;

}

void ProfesorController::listaProfesores() {
    cout << "Listando profesores..." << endl;

}

void ProfesorController::crearProfesores() {
    cout << "Creando profesor..." << endl;
    profesorService.crearProfesor();
}
