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
  try {
    int idProfesor = 0;
    int idEstudiante = 0;

    cout<<"Ingrese el Id del profesor a asignar: "<<endl;
    cin>>idProfesor;
    cout<<"Ingrese el Id del Estudiante"<<endl;
    cin>>idEstudiante;

    string mesagge = service.AsignarProfesor(idProfesor, idEstudiante);
    cout<<mesagge<<endl;
  }catch(exception& e) {
    cout<<e.what()<<endl;
  }
}
void AsignarController::listarAsignaciones(){
  cout<<"Lista de asignaciones"<<endl;
  for(auto asignacion: service.listaDeAsignaciones()){
    cout<<asignacion<<endl;
    }
}