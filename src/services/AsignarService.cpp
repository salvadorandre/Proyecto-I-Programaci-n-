//
// Created by Admin on 21/04/2025.
//

#include "../../interfaces/services/AsignarService.h"
#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/services/ProfesorService.h"
#include "../../interfaces/models/profesor.h"
#include "../../interfaces/models/estudiante.h"
#include <stdexcept>


AsignarService::AsignarService(EstudianteService EstudianteService, ProfesorService profesorService)
    :IEstudianteService(EstudianteService),IprofesorService(profesorService) {}

string AsignarService::AsignarProfesor(int idProfesor,int idEstudiante){
  try{
      Profesor profesor = IprofesorService.obtenerProfesor(idProfesor);
      Estudiante estudiante = IEstudianteService.obtenerEstudiante(idEstudiante);
      if(profesor.idProfesor == -1 || estudiante.idEstudiante == -1){
          throw invalid_argument("No existe un profesor/estudiante con ese Id");
      }
      //TODO: implementar guradado
      //logica: guardar si no existe un profesor y estudiante, como? usando los fk como llave primaria
      //y auto crear los ids


    }catch(exception& e){
        return e.what();
    }
}

vector<string> AsignarService::listaDeAsignaciones(){

}
