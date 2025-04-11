//
// Created by Admin on 10/04/2025.
//

#include "../../interfaces/controllers/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"

ProfesorController::ProfesorController(const ProfesorService& profesorService): IprofesorService(profesorService)
{

}