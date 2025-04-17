//Creadooo

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

using namespace std;

struct  Estudiante{
        int idEstudiante;
        char nombre[50];
        int edad;
        char genero[50];
        char grado[50];
        bool active;
        float promedio;
        string getDetails(){
                return nombre;
        }
};

#endif