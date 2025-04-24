//
// Created by Admin on 21/04/2025.
//

#ifndef ASIGNARSERVICE_H
#define ASIGNARSERVICE_H
#include "../services/EstudianteService.h"
#include "../services/ProfesorService.h"
#include "../repository/AsignacionesRepository.h"
#include "../models/Estudiante.h"
#include "../models/Profesor.h"
#include "../DTOs/Asignacion.h"

class AsignarService {
  private:
    EstudianteService IEstudianteService;
    ProfesorService IprofesorService;
    AsignacionesRepository repo;

  public:
    AsignarService(EstudianteService service, ProfesorService profesorService,AsignacionesRepository AsignacionesRepository);
    string AsignarProfesor(int idProfesor,int idEstudiante,int idCurso);
    vector<string> listaDeAsignaciones();
  vector<string> listaDeAsignaciones(int curso);



};



#endif //ASIGNARSERVICE_H
