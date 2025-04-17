#ifndef PROFESORCONTROLLER_H
#define PROFESORCONTROLLER_H

#include "../../interfaces/services/ProfesorService.h"

class ProfesorController {
    ProfesorService profesorService;

public:
    ProfesorController(ProfesorService profesorService);

    void buscarProfesor();
    void listaProfesores();
    void crearProfesores();
};

#endif //PROFESORCONTROLLER_H