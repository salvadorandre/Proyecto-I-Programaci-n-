#include <iostream>
#include "./interfaces/controller/ProfesorController.h"
#include "./interfaces/services/ProfesorService.h"
#include "./interfaces/repository/ProfesorRepository.h"

#include "./interfaces/controller/EstudianteController.h"
#include "./interfaces/services/EstudianteService.h"
#include "./interfaces/repository/EstudianteRepository.h"

#include "./interfaces/controller/AsignarController.h"
#include "./interfaces/services/AsignarService.h"
#include "./interfaces/repository/AsignacionesRepository.h"
#include "./interfaces/UI/ui.h"
using namespace std;
int main() {
    FILE *archivo, *archivo2, *archivo3;
//Variables para los profesores.
    ProfesorRepository profeRepo(archivo, "bdProfesor");
    ProfesorService profeService(profeRepo);
    ProfesorController profesorController(profeService);

//Variables para los estudiantes
    EstudianteRepository estuRepo(archivo2,"bdEstudiante");
    EstudianteService estuService(estuRepo);
    EstudianteController estuController(estuService);

    AsignacionesRepository asigRepo(archivo3, "bdAsignaciones");
    AsignarService asignarService(estuService,profeService,asigRepo);
    AsignarController asignaController(asignarService);

    UI interfazGrafica(estuController, profesorController,asignarService);
    interfazGrafica.menuPrincipal();


    return 0;
}
