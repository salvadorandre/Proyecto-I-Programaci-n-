//
// Created by Admin on 21/04/2025.
//

#include "../../interfaces/services/AsignarService.h"
#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/services/ProfesorService.h"
#include "../../interfaces/models/profesor.h"
#include "../../interfaces/models/estudiante.h"
#include <stdexcept>

#include "../utils/Cursos.h"


AsignarService::AsignarService(EstudianteService EstudianteService, ProfesorService profesorService,AsignacionesRepository AsignacionesRepository)
    :IEstudianteService(EstudianteService),IprofesorService(profesorService),repo(AsignacionesRepository) {}

string AsignarService::AsignarProfesor(int idProfesor,int idEstudiante, int idCurso){
  try{

      bool existen = repo.coincidencia(idProfesor,idEstudiante);
      if(existen){
        throw invalid_argument("Ya estan asignados");
      }

      Profesor profesor = IprofesorService.obtenerProfesor(idProfesor);
      Estudiante estudiante = IEstudianteService.obtenerEstudiante(idEstudiante);

      cout<<estudiante.nombre<<endl;
      if(profesor.idProfesor == -1 || estudiante.idEstudiante == -1){
          throw invalid_argument("No existe un profesor/estudiante con ese Id");
      }


      if(estudiante.promedio < 61){
          throw invalid_argument("El promedio del estudiante no es suficiente para asignarle un profesor");
      }
      bool respnse = repo.postAsignacion(profesor,estudiante,idCurso);
      if (!respnse) {
          return "error al asignar";
      }
      return "se han asignado correctamente";



    }catch(exception& e){
        return e.what();
    }
}

vector<string> AsignarService::listaDeAsignaciones(){
   try{
       vector<string> listaDeAsignaciones;
       vector<Estudiante> listaDeEstudiantes;
       vector<Profesor> listaDeProfesores;

       vector<Asignacion> asignaciones = repo.getAllAsignaciones();

       for(Asignacion asignacion : asignaciones){
           Profesor profesor = IprofesorService.obtenerProfesor(asignacion.idProfesor);
           Estudiante estudiante = IEstudianteService.obtenerEstudiante(asignacion.idEstudiante);

           string nombreProfesor = profesor.nombre;
           string nombreEstudiante = estudiante.nombre;
           listaDeAsignaciones.push_back("ID: "+nombreProfesor + " asignado a-> "+nombreEstudiante+" con el Id: "+to_string(estudiante.idEstudiante ));
       }

       return listaDeAsignaciones;
     }catch(exception& e){
       cout<<e.what()<<endl;
     }


}
vector<string> AsignarService::listaDeAsignaciones(int curso){
    try{
        Cursos cursos;
        int materia = cursos.getCursosId(curso);
        vector<string> listaDeAsignaciones;
        vector<Estudiante> listaDeEstudiantes;
        vector<Profesor> listaDeProfesores;

        vector<Asignacion> asignaciones = repo.getAllAsignaciones();

        for(Asignacion asignacion : asignaciones){
            Profesor profesor = IprofesorService.obtenerProfesor(asignacion.idProfesor);
            Estudiante estudiante = IEstudianteService.obtenerEstudiante(asignacion.idEstudiante);

            string nombreProfesor = profesor.nombre;
            string nombreEstudiante = estudiante.nombre;
            if (asignacion.idCurso == materia) {
                listaDeAsignaciones.push_back("ID: "+nombreProfesor + " asignado a-> "+nombreEstudiante+" con el Id: "+to_string(estudiante.idEstudiante ));
            }

        }

        return listaDeAsignaciones;
    }catch(exception& e){
        cout<<e.what()<<endl;
    }


}
