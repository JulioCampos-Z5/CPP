/*
Julio Cesar Campos Aguilar
221802379
Porgramacion orientda a objetos
MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/
#include <iostream>
#include "Biblioteca.h"   // Corrección del nombre del archivo
#include "Biblioteca.c++" // Corrección del nombre del archivo
using namespace std;

Libros libros[MAX_LIBROS];               // Arreglo de libros
Usuario usuarios[MAX_USUARIOS];          // Arreglo de usuarios
Biblioteca bibliotecas[MAX_BIBLiOTECAS]; // Arreglo de préstamos

int totalLibros = 0;
int totalUsuarios = 0;
int totalBiblioteca = 0;

void Menu(); // Funcion Menu inicializada

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
            libros[totalLibros].Mostrar(libros, totalLibros);
            break;
        case 3:
            libros[totalLibros].Eliminar(libros, totalLibros);
            break;
        case 4:
            Menu();
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
            usuarios[totalUsuarios].Registrar(usuarios, totalUsuarios);
            break;
        case 2:
            usuarios[totalUsuarios].Mostrar(usuarios, totalUsuarios);
            break;
        case 3:
            usuarios[totalUsuarios].Eliminar(usuarios, totalUsuarios);
            break;
        case 4:
            Menu();
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}

void BIBLiOTECA()
{
    int opc;
    while (opc != 4)
    {
        cout << "|     Biblioteca    |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            bibliotecas[totalBiblioteca].Registrar(bibliotecas, libros, usuarios, totalBiblioteca, totalLibros, totalUsuarios);
            break;
        case 2:
            bibliotecas[totalBiblioteca].Mostrar(bibliotecas, totalBiblioteca);
            break;
        case 3:
            bibliotecas[totalBiblioteca].Eliminar(bibliotecas, totalBiblioteca);
            break;
        case 4:
            Menu();
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
             << "|3.Biblioteca       |" << endl
             << "|4.Salir del sistema|" << endl
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
            BIBLiOTECA();
            break;
        case 4:
            cout << "|Salió del sistema|" << endl;
            opc = 4;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    } while (opc != 4);
}

int main()
{
    Menu();
    return 0;
}
