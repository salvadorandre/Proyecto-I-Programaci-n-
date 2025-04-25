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

        repository.postProfesor(profesor);
        return "Se ah creado un nuevo profesor: "+profesor.getDetails(); ;

}
Profesor ProfesorService::obtenerProfesor(int idProfesor) {

        Profesor profesor = repository.getProfesorById(idProfesor);
        if (profesor.idProfesor == -1) {
            throw invalid_argument("No se ah encontrado el profesor solicitado");
        }
        return profesor;

}

vector<Profesor> ProfesorService::listaProfesores() {

       vector<Profesor> list = repository.getAllProfesor();
       return list;

}


string ProfesorService::eliminarProfesor(int idProfesor) {
    //validaciones
    //repo
}



