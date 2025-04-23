#include "../../interfaces/UI/ui.h"
#include <iostream>
#define byte win_byte_override
#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include "dos.h"
#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/controller/EstudianteController.h"
#include "../../interfaces/controller/AsignarController.h"


using namespace std;


UI::UI(EstudianteController estuController, ProfesorController profeController,AsignarController asignarController): estuController(estuController), profesorController(profeController),asigController(asignarController)



{
    // Ya se construyó correctamente todo lo necesario.


}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pantallaCarga(){
    system("cls");
    int x, y, i, z, a;
    gotoxy(35, 10);
    printf("Cargando...");


    for(i = 1; i < 90; i++) {
        gotoxy(i, 13);
        printf("%c", 177);

        for(x = 50; x < 70; x++) {
            for(y = 1; y < 70; y++) {
                gotoxy(y, 24);
            }
        }

    }
    printf("\n\n carga completa del programa");
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
    pantallaCarga();
    system("pause");
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
                reporteGeneral();
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
    system("cls");
    do{
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
                setColor(11);
                //Busqueda del estudiante.
                system("cls");

                estuController.buscarEstudiante();
                system("pause");
                system("cls");

                break;
            case 3:
                menuPrincipal();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                setColor(11);
                break;


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
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                setColor(11);
                asigController.asignar();
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
    setColor(11);

    system("cls");

    do {
        cout << "|----------------------------|\n";
        cout << "|     REPORTE GENERAL        |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Reporte Estudiantes     |\n";
        cout << "| 2. Reporte Profesores      |\n";
        cout << "| 3. Reporte de Asignaciones |\n";
        cout << "| 4. Salir                   |\n";
        cout << "|----------------------------|\n";
        cout << "\n";


        setColor(14);

        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                reporteEstudiantes();
                break;
            case 2:
                reporteProfesores();
                break;
            case 3:
                asigController.listarAsignaciones();
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
    int opc;
    system("cls");
    setColor(11);
    do {
        cout << "|----------------------------|\n";
        cout << "|     REPORTE ESTUDIANTES    |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Buscar Estudiante       |\n";
        cout << "| 2. Todos los Estudiantes   |\n";
        cout << "| 3. Salir                   |\n";
        cout << "|----------------------------|\n";
        cout << "\n";

        setColor(14);

        escribirLento("Ingrese una opcion: ");
        cin>>opc;

        switch(opc) {
            case 1:
                setColor(11);
                system("cls");
                estuController.buscarPorNombre();
                system("pause");
                system("cls");
                break;
            case 2:
                setColor(11);
                system("cls");
                estuController.listaEstudiantesOrdenados();
                system("pause");
                system("cls");
                break;
            case 3:
                cout<<"gracias por utilizar el programa"<<endl;
                break;
            default:
                cout<<"Opcion incorrecta..."<<endl;
        }
    }while(opc !=3);

}

void UI::reporteProfesores() {
    int opc;
    do {
        cout << "|----------------------------|\n";
        cout << "|     REPORTE PROFESORES     |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Reporte Estudiantes     |\n";
        cout << "| 2. Reporte Profesores      |\n";
        cout << "| 3. Reporte de Asignaciones |\n";
        cout << "| 4. Salir                   |\n";
        cout << "|----------------------------|\n";
        cout << "\n";



        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;

        switch(opc) {
            case 1:

                break;
            case 2:

                break;
            case 3:
                asigController.listarAsignaciones();
                break;
            case 4:
                cout<<"gracias por utilizar el programa"<<endl;
                break;
            default:
                cout<<"Opcion incorrecta ojete"<<endl;
        }
    }while(opc !=4);
}