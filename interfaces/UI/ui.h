#ifndef PROYECTOPROGRAMACION_UI_H
#define PROYECTOPROGRAMACION_UI_H

//Profesores
#include "../../interfaces/controller/ProfesorController.h"

//Estudiantes
#include "../../interfaces/controller/EstudianteController.h"
#include "../../interfaces/controller/AsignarController.h"

class UI {
private:
    //Variables para los profesores.

    ProfesorController profesorController;

    //Variables para los estudiantes
    EstudianteController estuController;
    AsignarController asigController;

public:
    UI(EstudianteController estuController, ProfesorController profeController,AsignarController asignarController);
    void setColor(int color);
    void menuPrincipal();
    void menuEstudiante();
    void menuProfesor();
    void reporteGeneral();
    void reporteEstudiantes();
    void reporteProfesores();
};

#endif //PROYECTOPROGRAMACION_UI_H
