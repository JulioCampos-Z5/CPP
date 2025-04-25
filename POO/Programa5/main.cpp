/*
Julio Cesar Campos Aguilar
221802379
Porgramación orientada a objetos
MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/
#include <iostream>
#include <windows.h>
#include "Biblioteca.h"   
#include "Biblioteca.c++" 
using namespace std;

Libros libros[MAX_LIBROS];         // Arreglo de libros
Usuario usuarios[MAX_USUARIOS];    // Arreglo de usuarios
Prestamo prestamos[MAX_PRESTAMOS]; // Arreglo de préstamos
Biblioteca biblioteca;

int totalLibros = 0;
int totalUsuarios = 0;
int totalPrestamos = 0;

void Menu()
{
    int opc;
    do
    {
        cout << "|        Menu       |" << endl
             << "|1.Libros           |" << endl
             << "|2.Usuarios         |" << endl
             << "|3.Prestamos        |" << endl
             << "|4.Salir del sistema|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            biblioteca.GestionarLibros(libros, totalLibros);
            break;
        case 2:
            biblioteca.GestionarUsuarios(usuarios, totalUsuarios);
            break;
        case 3:
            biblioteca.GestionarPrestamos(prestamos, libros, usuarios, totalPrestamos, totalLibros, totalUsuarios);
            break;
        case 4:
            cout << "|Salió del sistema|" << endl;
            break;
        default:
            cout << "|Opción no válida, Ingrese solo números.|" << endl;
            break;
        }
    } while (opc != 4);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Menu();
    return 0;
}