//
// Created by Admin on 21/04/2025.
//

#include "../../interfaces/controller/AsignarController.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "../../interfaces/services/AsignarService.h"
#include "../../interfaces/models/Profesor.h"
#include "../../interfaces/models/Estudiante.h"
#include "../../interfaces/DTOs/Asignacion.h"
#include "../utils/Cursos.h"

AsignarController::AsignarController(AsignarService asignarServic):service(asignarServic){}


void AsignarController::asignar(){
  try {
    Cursos cursos;
    int idProfesor = 0;
    int idEstudiante = 0;
    int idCurso = 0;
    cout<<"Ingrese el Id del profesor a asignar: "<<endl;
    cin>>idProfesor;
    cout<<"Ingrese el Id del Estudiante"<<endl;
    cin>>idEstudiante;
    idCurso = cursos.getCursos();

    string mesagge = service.AsignarProfesor(idProfesor, idEstudiante,idCurso);
    cout<<mesagge<<endl;
  }catch(exception& e) {
    cout<<e.what()<<endl;
  }
}
void AsignarController::listarAsignaciones(){
 try {
   cout<<"Lista de asignaciones"<<endl;
   for(auto asignacion: service.listaDeAsignaciones()){
     cout<<asignacion<<endl;
   }
 }catch(exception& e) {
   cout<<e.what()<<endl;
 }
}
void AsignarController::listarAsignaciones(int curso){
 try {
   Cursos cursos;
   string materia = cursos.getCursos(curso);
   cout<<"Lista de asignaciones del curso: "<<materia<<endl;
   int idCurso = cursos.getCursosId(curso);
   for(auto asignacion: service.listaDeAsignaciones(idCurso)){
     cout<<asignacion<<endl;
   }
 }catch(exception& e) {
   cout<<e.what()<<endl;
 }
}