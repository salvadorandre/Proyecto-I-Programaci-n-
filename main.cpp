#include <iostream>
#include "./interfaces/controller/ProfesorController.h"
#include "./interfaces/services/ProfesorService.h"
#include "./interfaces/repository/ProfesorRepository.h"
using namespace std;
int main() {
    //esto tiene que ir en la ui, en la parte de profesor
    FILE *file;
    //creen un archivo de texto en cmake-build-debug/bdProfes.txt
    ProfesorRepository repository(file,"bdProfes");
    ProfesorService profesorService(repository);
    ProfesorController profesor_controller(profesorService);

    //menu que tiene que ir en el objeto ui y llamarlo aqui
    //esto solo es un ejemplo
    profesor_controller.buscarProfesor();
    profesor_controller.crearProfesores();
    profesor_controller.listaProfesores();

    return 0;
}
