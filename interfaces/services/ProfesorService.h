//
// Created by Admin on 10/04/2025.
//

#ifndef PROFESORSERVICE_H
#define PROFESORSERVICE_H
#include "../repository/ProfesorRepository.h"


class ProfesorService {
  ProfesorRepository IprofesorRepo;
  public:
    ProfesorService(const ProfesorRepository &profesorRepository);
    void crearProfesor();


};



#endif //PROFESORSERVICE_H
