//Creadooo

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

using namespace std;

struct  Estudiante{
        int idEstudiante;
        string nombre;
        int edad;
        string genero;
        string grado;
        bool active;
        float promedio;
        string getDetails(){
                return nombre;
        }
};

#endif