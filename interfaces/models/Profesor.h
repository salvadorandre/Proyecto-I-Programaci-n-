//
// Created by Admin on 10/04/2025.
//

#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>

using namespace std;

struct Profesor {
      int idProfesor;
      char nombre[50];
      bool active;
      string getDetails() {
            return "ID: "+to_string(idProfesor)+" nombre:"+ nombre ;
      }
};

#endif //PROFESOR_H
