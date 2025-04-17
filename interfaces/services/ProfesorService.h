//
// Created by Admin on 10/04/2025.
//

#ifndef PROFESORSERVICE_H
#define PROFESORSERVICE_H
#include "../repository/ProfesorRepository.h"


class ProfesorService {
  ProfesorRepository repository;
  public:
    ProfesorService(const ProfesorRepository &profesorRepository);
    string crearProfesor(Profesor profesor);
    Profesor obtenerProfesor(int idProfesor);
    vector<Profesor> listaProfesores();
    string eliminarProfesor(int idProfesor);

};



#endif //PROFESORSERVICE_H
