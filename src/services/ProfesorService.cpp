//
// Created by Admin on 10/04/2025.
//

#include "../../interfaces/services/ProfesorService.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

#include "../../interfaces/repository/ProfesorRepository.h"


ProfesorService::ProfesorService(const ProfesorRepository &repository): repository(repository){};

string ProfesorService::crearProfesor(Profesor profesor) {
    try {
        repository.postProfesor(profesor);
        return "Se ah creado un nuevo profesor: "+profesor.getDetails(); ;
    }catch (invalid_argument e) {
        cout << e.what() << endl;
        return "No se ha creado un nuevo profesor";
    }
}
Profesor ProfesorService::obtenerProfesor(int idProfesor) {
    try {
        Profesor profesor = repository.getProfesorById(idProfesor);
        if (profesor.idProfesor == -1) {
            throw invalid_argument("No se ah encontrado el profesor solicitado");
        }
        return profesor;
    }catch (invalid_argument e) {
        cout << e.what() << endl;

    }
}

vector<Profesor> ProfesorService::listaProfesores() {
   try {
       vector<Profesor> list = repository.getAllProfesor();
       return list;
   }catch (invalid_argument e) {
       cout << e.what() << endl;
   }
}


string ProfesorService::eliminarProfesor(int idProfesor) {
    //validaciones
    //repo
}



