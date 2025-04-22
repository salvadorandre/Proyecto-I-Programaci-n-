//
// Created by Admin on 10/04/2025.
//

#include "../../interfaces/repository/ProfesorRepository.h"
#include "../../interfaces/models/profesor.h"
#include "vector"
#include <stdexcept>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

ProfesorRepository::ProfesorRepository(FILE *file,string fileName) {
    this->fileName = fileName+".txt";
    this->file = file;

   file = fopen(this->fileName.c_str(), "a");
  if (file == nullptr) {
    cout<<"Error en la creacion del archivo"<<endl;
  }
  long isNew = ftell(file);
  if(isNew == 0) {
    cout<<"Archivo creado"<<endl;

  }
  else {
    cout<<"El archivo ya existe"<<endl;
  }

  fclose(file);
};

FILE* ProfesorRepository::getFile(string mode) {
    FILE* fileNew = fopen(fileName.c_str(), "r");
    if (!fileNew) {
        throw invalid_argument("No se pudo abrir el archivo");
    }
    fclose(fileNew);
    fileNew = fopen(fileName.c_str(), mode.c_str());
    return fileNew;
}

Profesor ProfesorRepository::getProfesorById(int idProfesor) {
  file =getFile("r");
  Profesor profesorFind;
  Profesor profesorNotFound;
  while(fread(&profesorFind, sizeof(Profesor), 1, file)) {
    if (profesorFind.idProfesor == idProfesor) {
		if(profesorFind.active == true) {
           fclose(file);
           return profesorFind;
		}
           break;
    }
  }
  fclose(file);
  profesorNotFound.idProfesor = -1;
  return profesorNotFound;

}
  //metodos solo para manipular archivos
bool ProfesorRepository::putProfesor(Profesor profesor) {
  int foundProfesor = getProfesorById(profesor.idProfesor).idProfesor;
  if (foundProfesor != -1)return false;

  file = getFile("ab");//para abrirlo xd
  fwrite(&profesor, sizeof(Profesor), 1, file);
  fclose(file);
  return true;
}

vector<Profesor> ProfesorRepository::getAllProfesor() {
  vector<Profesor> profesors;
  Profesor profesor;
  file = getFile("r");

  while(fread(&profesor, sizeof(Profesor), 1, file)) {
    profesors.push_back(profesor);
  }

  fclose(file);
  return profesors;

}

bool ProfesorRepository::deleteProfesor(int idProfesor) {

  Profesor foundProfesor = getProfesorById(idProfesor);
  if ((foundProfesor.idProfesor = -1)) return false;
  file = getFile("r+b");




  fclose(file);
}

