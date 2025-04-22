//
// Created by Admin on 21/04/2025.
//

#ifndef ASIGNARSERVICE_H
#define ASIGNARSERVICE_H
#include "../services/EstudianteService.h"
#include "../services/ProfesorService.h"

class AsignarService {
  private:
    EstudianteService IEstudianteService;
    ProfesorService IprofesorService;
  public:
    AsignarService(EstudianteService service, ProfesorService profesorService);
    string AsignarProfesor(int idProfesor,int idEstudiante);
    vector<string> listaDeAsignaciones();



};



#endif //ASIGNARSERVICE_H
