#ifndef PROYECTOPROGRAMACION_UI_H
#define PROYECTOPROGRAMACION_UI_H

//Profesores
#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"
#include "../../interfaces/repository/ProfesorRepository.h"
//Estudiantes
#include "../../interfaces/controller/EstudianteController.h"
#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/repository/EstudianteRepository.h"

class UI {
private:
    //Variables para los profesores.

    ProfesorController profesorController;

    //Variables para los estudiantes
    EstudianteController estuController;

public:
    UI(EstudianteController estuController, ProfesorController profeController);
    void menuPrincipal();
    void menuEstudiante();
    void menuProfesor();
    void reporteGeneral();
};

#endif //PROYECTOPROGRAMACION_UI_H
