#include "../../interfaces/UI/ui.h"
#include <iostream>
#define byte win_byte_override
#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <chrono>

#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/services/ProfesorService.h"
#include "../../interfaces/repository/ProfesorRepository.h"

#include "../../interfaces/controller/EstudianteController.h"
#include "../../interfaces/services/EstudianteService.h"
#include "../../interfaces/repository/EstudianteRepository.h"
using namespace std;


UI::UI(EstudianteController estuController, ProfesorController profeController): estuController(estuController), profesorController(profeController)



{
    // Ya se construyó correctamente todo lo necesario.


}

void escribirLento(const string& texto, int delay = 50) {
    for (char c : texto) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void UI::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UI::menuPrincipal() {
    system("cls");
    int opc;
    setColor(11);
    do{
        cout << "|----------------------------|\n";
        cout << "|     MENU PRINCIPAL         |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Nuevo Estudiante        |\n";
        cout << "| 2. Reportes                |\n";
        cout << "| 3. Asignar Profesor        |\n";
        cout << "| 4. Salir                   |\n";
        cout << "|----------------------------|\n";

        cout << "\n";
        setColor(14); // amarillo
        escribirLento("Ingrese una opcion: ");
        cin>>opc;

        switch(opc) {
            case 1:
                setColor(11);
                menuEstudiante();
                break;
            case 2:

                break;
            case 3:
                setColor(11);
                menuProfesor();
                break;
            case 4:
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                setColor(11);

                system("cls");

        }
    }while(opc != 4);
}

void UI::menuEstudiante() {
    int opc;
    do{
        system("cls");
        cout << "|----------------------------|\n";
        cout << "|     MENU ESTUDIANTES       |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Crear Estudiante        |\n";
        cout << "| 2. Buscar Estudiante       |\n";
        cout << "| 3. Salir                   |\n";
        cout << "|----------------------------|\n";
        cout << "\n";

        setColor(14);

        escribirLento("Ingrese una opcion: ");
        cin>>opc;

        switch(opc) {
            case 1:
                //Crear el estudiante.
                system("cls");
                setColor(11);
                estuController.crearEstudiantes();
                break;
            case 2:
                system("cls");
                setColor(11);
                //Busqueda del estudiante.
                estuController.buscarEstudiante();
                break;
            case 3:
                menuPrincipal();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                setColor(11);

                system("cls");
        }
    }while(opc != 3);
}


void UI::menuProfesor() {
    system("cls");

    int opc;
    do{

        cout << "|----------------------------|\n";
        cout << "|     MENU PROFESORES        |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Crear Profesor          |\n";
        cout << "| 2. Buscar Profesor         |\n";
        cout << "| 3. Asignar Profesor        |\n";
        cout << "| 4. Salir                   |\n";
        cout << "|----------------------------|\n";
        cout << "\n";
        setColor(14);

        escribirLento("Ingrese una opcion: ");
        cin>>opc;

        switch(opc) {
            case 1:
                //Metodo para crear el profe.
                system("cls");
                setColor(11);
                profesorController.crearProfesores();
                break;
            case 2:
                //Metodo para buscar al profe
                system("cls");
                setColor(11);
                profesorController.buscarProfesor();
                break;
            case 3:
                //Pendiente XD
                break;
            case 4:
                system("cls");
                menuPrincipal();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                setColor(11);

                system("cls");
        }
    }while(opc!=4);
}

void UI::reporteGeneral() {
    int opc;
    do {
        cout<<"----------\tReporte General----------"<<endl;
        cout<<"1. Reporte Estudiantes"<<endl;
        cout<<"2. Reporte Profesores"<<endl;
        cout<<"3. Reporte de Asignaciones"<<endl;
        cout<<"4. Salir"<<endl;


        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;

        switch(opc) {
            case 1:

                break;
            case 2:

                break;
            case 3:
                //Pendiente XD
                break;
            case 4:
                cout<<"gracias por utilizar el programa"<<endl;
                break;
            default:
                cout<<"Opcion incorrecta ojete"<<endl;
        }
    }while(opc !=4);
}

void UI::reporteEstudiantes() {

}

void UI::reporteProfesores() {

}