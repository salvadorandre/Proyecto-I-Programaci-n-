//
// Created by Admin on 10/04/2025.
//

#include "../../interfaces/services/ProfesorService.h"
#include "../../interfaces/repository/ProfesorRepository.h"


ProfesorService::ProfesorService(const ProfesorRepository &repository): repository(repository){};

string ProfesorService::crearProfesor(Profesor profesor) {
    //validaciones
    //manejo de repo
}
Profesor ProfesorService::obtenerProfesor(int idProfesor) {
    //validaciones
    //manejo de repo
}

vector<Profesor> ProfesorService() {
    //validaciones
    //repo
}

string ProfesorService::eliminarProfesor(int idProfesor) {
    //validaciones
    //repo
}



