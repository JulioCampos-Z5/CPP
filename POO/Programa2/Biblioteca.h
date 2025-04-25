#ifndef libros_H
#define libros_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_LIBROS = 100;      // Tamaño máximo del arreglo de libros
const int MAX_USUARIOS = 100;    // Tamaño máximo del arreglo de usuarios
const int MAX_BIBLiOTECAS = 100; // Tamaño máximo del arreglo de préstamos

class Libros
{
private:
    int ID;
    string Titulo;
    string Autor;
    string AnoP;
    bool Disponible;
    int Cantidad;

public:
    Libros() : ID(0), Titulo(""), Autor(""), AnoP(""), Disponible(false), Cantidad(0) {}

    int getID() const { return ID; }
    void setID(int id) { ID = id; }

    bool Vacio();
    void Agregar(Libros libros[], int &totalLibros);
    void Eliminar(Libros libros[], int &totalLibros);
    int Buscar(Libros libros[], int totalLibros, int id);
    void Mostrar(Libros libros[], int totalLibros);
};

class Usuario
{
private:
    int ID;
    string Nombre;
    string Correo;
    string Direccion;
    string Estatus;

public:
    Usuario() : ID(0), Nombre(""), Correo(""), Direccion(""), Estatus("") {}

    int getID() const { return ID; }
    void setID(int id) { ID = id; }

    bool Vacio();
    void Registrar(Usuario usuarios[], int &totalUsuarios);
    void Eliminar(Usuario usuarios[], int &totalUsuarios);
    int Buscar(Usuario usuarios[], int totalUsuarios, int id);
    void Mostrar(Usuario usuarios[], int totalUsuarios);
};

class Biblioteca
{
private:
    int ID;
    int ID_L;
    int ID_U;
    string fecha_inicio;
    string fecha_final;

public:
    Biblioteca() : ID(0), ID_L(0), ID_U(0), fecha_inicio(""), fecha_final("") {}

    bool Vacio();
    void Registrar(Biblioteca biblotecas[], Libros libros[], Usuario usuarios[], int &totalBiblotecas, int totalLibros, int totalUsuarios);
    void Eliminar(Biblioteca biblotecas[], int &totalBiblotecas);
    int Buscar(Biblioteca biblotecas[], int totalBiblotecas, int id);
    void Mostrar(Biblioteca biblotecas[], int totalBiblotecas);
};

#endif // libros_H