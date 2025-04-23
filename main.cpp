#include <iostream>
#include "./interfaces/controller/ProfesorController.h"
#include "./interfaces/services/ProfesorService.h"
#include "./interfaces/repository/ProfesorRepository.h"

#include "./interfaces/controller/EstudianteController.h"
#include "./interfaces/services/EstudianteService.h"
#include "./interfaces/repository/EstudianteRepository.h"
#include "./interfaces/UI/ui.h"
using namespace std;
int main() {
    FILE *archivo, *archivo2;
//Variables para los profesores.
    ProfesorRepository profeRepo(archivo, "bdProfesor");
    ProfesorService profeService(profeRepo);
    ProfesorController profesorController(profeService);

//Variables para los estudiantes
    EstudianteRepository estuRepo(archivo,"bdEstudiante");
    EstudianteService estuService(estuRepo);
    EstudianteController estuController(estuService);

    UI interfazGrafica(estuController, profesorController);
    interfazGrafica.menuPrincipal();


    return 0;
}
