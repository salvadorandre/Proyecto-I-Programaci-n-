//
// Created by Admin on 10/04/2025.
//

#ifndef PROFESORCONTROLLER_H
#define PROFESORCONTROLLER_H
#include "../services/ProfesorService.h"


class ProfesorController {
  ProfesorService IprofesorService;
    public:
      ProfesorController(const ProfesorService &profesorService);
};



#endif //PROFESORCONTROLLER_H
