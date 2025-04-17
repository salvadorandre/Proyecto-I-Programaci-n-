#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H

#include "../../interfaces/services/EstudianteService.h"

class EstudianteController {
    EstudianteService estudianteService;

public:
    EstudianteController(EstudianteService estudianteService);

    void buscarEstudiante();
    void listaEstudiantes();
    void crearEstudiantes();
};

#endif //ESTUDIANTECONTROLLER_H
