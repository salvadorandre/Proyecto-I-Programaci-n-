//
// Created by Admin on 21/04/2025.
//

#include "../../interfaces/repository/AsignacionesRepository.h"
#include "../../interfaces/models/Estudiante.h"
#include "../../interfaces/models/Profesor.h"
#include "../../interfaces/DTOs/Asignacion.h"

AsignacionesRepository::AsignacionesRepository(FILE *file,string fileName){
  this->fileName = fileName+".txt";
  this->file = file;

  file = fopen(this->fileName.c_str(), "a");
  if (file == nullptr) {
    cout<<"Error en la creacion del archivo"<<endl;
    return;
  }
  long isNew = ftell(file);
  if(isNew == 0) {
    cout<<"Archivo creado"<<endl;

  }
  else {
    cout<<"El archivo ya existe"<<endl;
  }

  fclose(file);
}

vector<Asignacion> AsignacionesRepository::getAllAsignaciones(){
  file = fopen(fileName.c_str(),"r");
  if(file == nullptr){
    throw runtime_error("Error a la hora de abrir el archivo file");
    fclose(file);
  }
  vector<Asignacion> todasLasAsignaciones;
  Asignacion asignacionActual;


  while(fread(&asignacionActual, sizeof(Asignacion), 1, file)) {
    todasLasAsignaciones.push_back(asignacionActual);
  }

  fclose(file);
  return todasLasAsignaciones;
}

int AsignacionesRepository::autoIncrement(){
  file = fopen(fileName.c_str(),"r");
  if(file == nullptr){
    throw runtime_error("Error a la hora de abrir el archivo file");
    fclose(file);
  }
  vector<Asignacion> todasLasAsignaciones;
  Asignacion asignacionActual;
  int idAsignacion = 0;

  while(fread(&asignacionActual, sizeof(Asignacion), 1, file)) {
    idAsignacion=asignacionActual.idAsignacion;
  }

  fclose(file);
  return idAsignacion;
}
bool AsignacionesRepository::coincidencia (int idProfesor,int idEstudiante){
  file = fopen(fileName.c_str(),"r");
  if(file == nullptr){
    throw runtime_error("Error a la hora de abrir el archivo file");
    fclose(file);
  }
  vector<Asignacion> todasLasAsignaciones;
  Asignacion asignacionActual;
  bool coincidencia = false;

  while(fread(&asignacionActual, sizeof(Asignacion), 1, file)) {
    if(asignacionActual.idProfesor == idProfesor || asignacionActual.idEstudiante == idEstudiante){
      coincidencia= true;
      break;
    }
  }

  fclose(file);
  return coincidencia;
}


bool AsignacionesRepository::postAsignacion(Profesor profesor, Estudiante estudiante){
  file = fopen(fileName.c_str(),"ab");
  if(file == nullptr){
    //fclose(file);
    return false;
  }
  int idEstudiante = estudiante.idEstudiante;
  int idProfesor = profesor.idProfesor;
  int idAsignacion = autoIncrement()+1;

  Asignacion asignacion;
  asignacion.idProfesor = idProfesor;
  asignacion.idEstudiante = idEstudiante;
  asignacion.idAsignacion = idAsignacion;

  fwrite(&asignacion, sizeof(Asignacion), 1, file);
  fclose(file);
  return true;

}


