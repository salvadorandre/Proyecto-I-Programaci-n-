//
// Created by Admin on 10/04/2025.
//

#ifndef REPOSITORYPROFESOR_H
#define REPOSITORYPROFESOR_H
#include <vector>
#include <cstdio>

#include "../../interfaces/models/Profesor.h"


class ProfesorRepository {
    FILE *file;
    string fileName;

    public:
      ProfesorRepository(FILE *file,string fileName);
      bool putProfesor(Profesor profesor);
      Profesor getProfesorById(int idProfesor);
      vector<Profesor> getAllProfesor();
      bool deleteProfesor(int idProfesor);
      FILE* getFile(string metod);
};



#endif //REPOSITORYPROFESOR_H
