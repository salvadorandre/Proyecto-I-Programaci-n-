//
// Created by Admin on 10/04/2025.
//

#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>

using namespace std;

struct Profesor {
      int idProfesor;
      int fkCurso;
      char nombre[50];
      int alumnMax;
      bool active;
      string getDetails() {
            return "ID: "+to_string(idProfesor)+", Nombre: "+ nombre +" con capacidad de: "+ to_string(alumnMax) + " estudiantes" ;
      }
};

#endif //PROFESOR_H
