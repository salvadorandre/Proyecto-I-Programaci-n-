#include "../../interfaces/UI/ui.h"
#include <iostream>
#define byte win_byte_override
#include <windows.h>
#include <MMsystem.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include "dos.h"

#include "../../interfaces/controller/ProfesorController.h"
#include "../../interfaces/controller/EstudianteController.h"
#include "../../interfaces/controller/AsignarController.h"
#include "../utils/Cursos.h"


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
    printf(
       "\n\nCarga completa del programa ->\n"
       "Realizado y distribuido por QX-code --La clave del exito--\n"
       "UI/UX: Andre Salvador\n"
       "Software Engineer: Daniel Vasquez\n"
       "Software Architect: Edwin Baquiax\n"
       "V.1.1\n"
   );

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
    static int totalCargas = 0;//un poco de singleton

    if (totalCargas <= 0) {
        pantallaCarga();
        totalCargas++;
    }
    system("pause");
    system("cls");
    int opc;
    setColor(11);
    do{
        cout << "|----------------------------|\n";
        cout << "|     MENU PRINCIPAL         |\n";
        cout << "|----------------------------|\n";
        cout << "| 1. Menu Estudiante         |\n";
        cout << "| 2. Menu Reportes           |\n";
        cout << "| 3. Menu Profesor           |\n";
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
                system("cls");
                exit(0);
                setColor(11);
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
                system("pause");
                system("cls");
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
                system("cls");
                setColor(11);
                menuPrincipal();
                break;
            default:
                system("cls");
                setColor(11);
                cout<<"Opcion incorrecta"<<endl;

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
        cout << "| 3. Asignacion              |\n";
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
                 system("pause");
            system("cls");
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
                system("pause");
            system("cls");
                break;
            case 4:
                system("cls");
                setColor(11);
                menuPrincipal();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;

                system("cls");
                setColor(11);

        }
    }while(opc!=4);
}

void UI::reporteGeneral() {
    int opc;
    setColor(11);
    Cursos cursos;
    int curso =0;

    system("cls");

    do {
        cout << "|--------------------------------------|\n";
        cout << "|     REPORTE GENERAL                  |\n";
        cout << "|--------------------------------------|\n";
        cout << "| 1. Reporte Estudiantes               |\n";
        cout << "| 2. Reporte Profesores                |\n";
        cout << "| 3. Reporte de todas las Asignaciones |\n";
        cout << "| 4. Reporte de Asignaciones por curso |\n";
        cout << "| 5. Salir                             |\n";
        cout << "|--------------------------------------|\n";
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
                system("pause");
                system("cls");
                break;
            case 4:
                curso= cursos.getCursos();
                asigController.listarAsignaciones(curso);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                setColor(11);
                menuPrincipal();

            break;
            default:
                system("cls");
                setColor(11);
        }
    }while(opc !=5);
}

void UI::reporteEstudiantes() {
    int opc;
    system("cls");
    setColor(11);
    do {
        cout << "|--------------------------------|\n";
        cout << "|     REPORTE ESTUDIANTES        |\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Buscar Estudiante por nombre|\n";
        cout << "| 2. Todos los Estudiantes       |\n";
        cout << "| 3. Salir                       |\n";
        cout << "|--------------------------------|\n";
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
                setColor(11);
                reporteGeneral();
                system("cls");
                break;
            default:
                cout<<"Opcion incorrecta..."<<endl;
                system("cls");
                setColor(11);

        }
    }while(opc !=3);

}

void UI::reporteProfesores() {
    int opc;
    Cursos cursos;
    int curso=0;
    system("cls");
    setColor(11);
    do {
        cout << "|---------------------------------------|\n";
        cout << "|     REPORTE PROFESORES                |\n";
        cout << "|---------------------------------------|\n";
        cout << "| 1. Buscar Profesor                    |\n";
        cout << "| 2. Todos los Profesores               |\n";
        cout << "| 3. Todos los Profesores segun curso   |\n";
        cout << "| 4. Salir                              |\n";
        cout << "|---------------------------------------|\n";
        cout << "\n";

        setColor(14);
        escribirLento("Ingrese una opcion: ");

        cin>>opc;

        switch(opc) {
            case 1:
                setColor(11);
                system("cls");
                profesorController.buscarProfesor();
                system("pause");
                system("cls");
                break;
            case 2:
                setColor(11);
                system("cls");
                profesorController.listaProfesores();
                system("pause");
                system("cls");
                break;
            case 3:

                setColor(11);
                system("cls");
                curso = cursos.getCursos();
                profesorController.listaProfesores(curso);
                system("pause");
                system("cls");
            break;
            case 4:
                cout<<"gracias por utilizar el programa"<<endl;
            setColor(11);
            reporteGeneral();
            system("cls");
            break;
            default:
                cout<<"Opcion incorrecta..."<<endl;
                system("cls");
                setColor(11);
                break;
        }
    }while(opc !=4);
}

