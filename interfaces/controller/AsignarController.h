//
// Created by Admin on 21/04/2025.
//

#ifndef ASIGNARCONTROLLER_H
#define ASIGNARCONTROLLER_H


#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "../../interfaces/services/AsignarService.h"
#include "../../interfaces/models/Profesor.h"
#include "../../interfaces/models/Estudiante.h"
#include "../../interfaces/DTOs/Asignacion.h"
using namespace std;

class AsignarController {
        AsignarService service;

        public:
          AsignarController(AsignarService Asignarservice);
          void asignar();
          void listarAsignaciones();
          void listarAsignaciones(int curso);
};



#endif //ASIGNARCONTROLLER_H
