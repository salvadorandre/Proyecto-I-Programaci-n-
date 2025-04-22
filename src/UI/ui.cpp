#include "../../interfaces/UI/ui.h"
#include <iostream>
#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/controller/EstudianteController.h"
#include "../../interfaces/controller/AsignarController.h"


using namespace std;


UI::UI(EstudianteController estuController, ProfesorController profeController,AsignarController asignarController): estuController(estuController), profesorController(profeController),asigController(asignarController)



{
    // Ya se construyó correctamente todo lo necesario.


}


void UI::menuPrincipal() {
    int opc;
    do{
        cout<<"----------\tMenu Principal----------"<<endl;
        cout<<"1. Nuevo Estudiante"<<endl;
        cout<<"2. Reportes"<<endl;
        cout<<"3. Asignar profesor a estudiante"<<endl;
        cout<<"4. Salir"<<endl;

        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;
        asigController.asignar();
        //asigController.listarAsignaciones();

        switch(opc) {
            case 1:
                menuEstudiante();
                break;
            case 2:

                break;
            case 3:
                menuProfesor();
                break;
            case 4:
                cout<<"TQM, gracias por utilizar el programa UWU"<<endl;
                break;
            default:
                cout<<"Opcion incorrecta ojete"<<endl;
        }
    }while(opc != 4);
}

void UI::menuEstudiante() {
    int opc;
    do{
        cout<<"----------\tMenu Estudiantes----------"<<endl;
        cout<<"1. Crear Estudiante"<<endl;
        cout<<"2. Buscar Estudiante"<<endl;
        cout<<"3. Salir"<<endl;

        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                //Crear el estudiante.
                estuController.crearEstudiantes();
                break;
            case 2:
                //Busqueda del estudiante.
                estuController.buscarEstudiante();
                break;
            case 3:
                cout<<"Gracias por utilizar el programa mi vida. DAVID X JHON POR SIEMPRE <3";
                break;
            default:
                cout<<"Opcion incorrecta ojete"<<endl;
        }
    }while(opc != 3);
}


void UI::menuProfesor() {

    int opc;
    do{
        cout<<"----------\tMenu Profesores----------"<<endl;
        cout<<"1. Crear Profesor"<<endl;
        cout<<"2. Buscar Profesor"<<endl;
        cout<<"3. Asignar Profesor a Estudiante"<<endl;
        cout<<"4. Salir"<<endl;

        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                //Metodo para crear el profe.
                profesorController.crearProfesores();
                break;
            case 2:
                //Metodo para buscar al profe
                profesorController.buscarProfesor();
                break;
            case 3:
                //Pendiente XD
                break;
            case 4:
                cout<<"TQM, gracias por utilizar el programa UWU"<<endl;
                break;
            default:
                cout<<"Opcion incorrecta ojete"<<endl;
        }
    }while(opc!=4);
}

void UI::reporteGeneral() {
    cout<<"----------\tReporte General----------"<<endl;
    cout<<"1. Reporte Estudiantes"<<endl;
    cout<<"2. Reporte Profesores"<<endl;
    cout<<"3. Reporte de Asignaciones"<<endl;
    cout<<"4. Salir"<<endl;
}
