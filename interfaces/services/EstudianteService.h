//
// Created by Admin on 10/04/2025.
//

#ifndef ESTUDIANTESERVICE_H
#define ESTUDIANTESERVICE_H
#include "../repository/EstudianteRepository.h"


class EstudianteService {
    EstudianteRepository Iestudiante;
public:
    EstudianteService(const EstudianteRepository &estudianteRepository);
    void crearEstudiante();


};

#endif //ESTUDIANTESERVICE_H
