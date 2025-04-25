/*
Julio Cesar Campos Aguilar
221802379
Porgramación orientada a objetos
MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/
#include <iostream>
#include <windows.h>
#include "Biblioteca.h"   // Corrección del nombre del archivo
#include "Biblioteca.c++" // Corrección del nombre del archivo
using namespace std;

Libros libros[MAX_LIBROS];         // Arreglo de libros
Usuario usuarios[MAX_USUARIOS];    // Arreglo de usuarios
Prestamo prestamos[MAX_PRESTAMOS]; // Arreglo de préstamos

int totalLibros = 0;
int totalUsuarios = 0;
int totalPrestamos = 0;

void Menu();

void LIBROS()
{
    int opc;
    while (opc != 4)
    {
        cout << "|      Libros      |" << endl
             << "|1.Agregar         |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            libros[totalLibros].Agregar(libros, totalLibros);
            break;
        case 2:
            libros[totalLibros].MostrarL(libros, totalLibros);
            break;
        case 3:
            libros[totalLibros].EliminarL(libros, totalLibros);
            break;
        case 4:
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}

void USUARIOS()
{
    int opc;
    while (opc != 4)
    {
        cout << "|      Usuarios    |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            usuarios[totalUsuarios].RegistrarU(usuarios, totalUsuarios);
            break;
        case 2:
            usuarios[totalUsuarios].MostrarU(usuarios, totalUsuarios);
            break;
        case 3:
            usuarios[totalUsuarios].EliminarU(usuarios, totalUsuarios);
            break;
        case 4:
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}

void PRESTAMOS()
{
    int opc;
    while (opc != 4)
    {
        cout << "|     Prestamos    |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            prestamos[totalPrestamos].RegistrarP(prestamos, libros, usuarios, totalPrestamos, totalLibros, totalUsuarios);
            break;
        case 2:
            prestamos[totalPrestamos].MostrarP(prestamos, totalPrestamos);
            break;
        case 3:
            prestamos[totalPrestamos].EliminarP(prestamos, totalPrestamos);
            break;
        case 4:
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}

void HERENCIA()
{
    int opc, AoB = 0;
    while (opc != 4)
    {
        cout << "|     Herencia     |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "|Registrar 1.Usuario / 2.Libro|" << endl
                 << "|:";
            cin >> AoB;
            if (AoB == 1)
                prestamos[totalPrestamos].RegistrarU(usuarios, totalUsuarios);
            else
                prestamos[totalPrestamos].Agregar(libros, totalLibros);
            break;
        case 2:
            cout << "|Mostrar 1.Usuario / 2.Libro / 3.Mostrar Todo|" << endl
                 << "|:";
            cin >> AoB;
            if (AoB == 1)
                prestamos[totalPrestamos].MostrarU(usuarios, totalUsuarios);
            else if (AoB == 2)
                prestamos[totalPrestamos].MostrarL(libros, totalLibros);
            else
            {
                prestamos[totalPrestamos].MostrarU(usuarios, totalUsuarios);
                prestamos[totalPrestamos].MostrarL(libros, totalLibros);
            }
            break;
        case 3:
            cout << "|Eliminar 1.Usuario / 2.Libro|" << endl
                 << "|:";
            cin >> AoB;
            if (AoB == 1)
                prestamos[totalPrestamos].EliminarU(usuarios, totalUsuarios);
            else
                prestamos[totalPrestamos].EliminarL(libros, totalLibros);
            break;
        case 4:
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}

void Menu()
{
    int opc;
    do
    {
        cout << "|        Menu       |" << endl
             << "|1.Libros           |" << endl
             << "|2.Usuarios         |" << endl
             << "|3.Prestamos        |" << endl
             << "|4.Herencia         |" << endl
             << "|5.Salir del sistema|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            LIBROS();
            break;
        case 2:
            USUARIOS();
            break;
        case 3:
            PRESTAMOS();
            break;
        case 4:
            HERENCIA();
            break;
        case 5:
            cout << "|Salió del sistema|" << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    } while (opc != 5);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Menu();
    return 0;
}