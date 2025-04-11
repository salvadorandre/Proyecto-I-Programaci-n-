//
// Created by Admin on 10/04/2025.
//

#include "../../interfaces/services/ProfesorService.h"
#include "../../interfaces/repository/ProfesorRepository.h"


ProfesorService::ProfesorService(const ProfesorRepository &profesorService) {
  Iprofesor = profesorService;
}
void ProfesorService::crearProfesor() {

}



