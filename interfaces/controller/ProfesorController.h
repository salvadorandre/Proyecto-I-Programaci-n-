#ifndef PROFESORCONTROLLER_H
#define PROFESORCONTROLLER_H

#include "../../interfaces/services/ProfesorService.h"

class ProfesorController {
    ProfesorService profesorService;

public:
    ProfesorController(ProfesorService profesorService);

    void buscarProfesor();
    void listaProfesores();
    void listaProfesores(int curso);
    void crearProfesores();
};

#endif //PROFESORCONTROLLER_H