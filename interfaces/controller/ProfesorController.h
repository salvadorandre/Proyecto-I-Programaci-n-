//
// Created by Admin on 14/04/2025.
//

#ifndef PROFESORCONTROLLER_H
#define PROFESORCONTROLLER_H
#include "../../interfaces/services/ProfesorService.h"


class ProfesorController {
  ProfesorService IprofesorService;
    public:
      ProfesorController(IprofesorService profesorService);

      void buscarProfesor();
      void listaProfesores();
      void crearProfesores();
};



#endif //PROFESORCONTROLLER_H
