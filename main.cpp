#include <iostream>
#include "./interfaces/controller/ProfesorController.h"
#include "./interfaces/services/ProfesorService.h"
#include "./interfaces/repository/ProfesorRepository.h"

#include "./interfaces/controller/EstudianteController.h"
#include "./interfaces/services/EstudianteService.h"
#include "./interfaces/repository/EstudianteRepository.h"

using namespace std;
int main() {
   //---    TODO ESTO METER EN UI ANDRE, AQUI SOLO LLAMAR LA UI PARA QUE CHAMBEE

    //esto tiene que ir en la ui, en la parte de profesor
    FILE *file;
    FILE *file2;

    //creen un archivo de texto en cmake-build-debug/bdProfes.txt
    ProfesorRepository repository(file,"bdProfes");
    ProfesorService profesorService(repository);
    ProfesorController profesor_controller(profesorService);

    EstudianteRepository repositoryE(file2,"bdEstudiante");
    EstudianteService estudianteService(repositoryE);
    EstudianteController estudianteController(estudianteService);


    estudianteController.crearEstudiantes();
    estudianteController.buscarEstudiante();
    estudianteController.listaEstudiantes();

    //menu que tiene que ir en el objeto ui y llamarlo aqui
    //esto solo es un ejemplo
    profesor_controller.buscarProfesor();
    profesor_controller.crearProfesores();
    profesor_controller.listaProfesores();

    return 0;
}
