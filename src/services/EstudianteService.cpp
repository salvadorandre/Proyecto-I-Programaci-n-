
#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/repository/EstudianteRepository.h"


EstudianteService::EstudianteService(const EstudianteRepository &estudianteService) {
    Iestudiante = estudianteService;
}
void EstudianteService::crearEstudiante() {

}
