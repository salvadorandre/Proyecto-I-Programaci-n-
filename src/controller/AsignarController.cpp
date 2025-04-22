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

AsignarController::AsignarController(AsignarService asignarServic):service(asignarServic){}


void AsignarController::asignar(){
  int idProfesor = 0;
  int idEstudiante = 0;

  cout<<"profesor"<<endl;
  cin>>idProfesor;
  cout<<"estudiante"<<endl;
  cin>>idEstudiante;
  service.AsignarProfesor(idProfesor, idEstudiante);
}
void AsignarController::listarAsignaciones(){
  for(auto asignacion: service.listaDeAsignaciones()){
    cout<<asignacion<<endl;
    }
}