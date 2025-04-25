#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_LIBROS = 100;    // Tamaño máximo del arreglo de libros
const int MAX_USUARIOS = 100;  // Tamaño máximo del arreglo de usuarios
const int MAX_PRESTAMOS = 100; // Tamaño máximo del arreglo de préstamos

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
    string getTitulo() { return Titulo; }

    bool Vacio();
    void Agregar(Libros libros[], int &totalLibros);
    void EliminarL(Libros libros[], int &totalLibros);
    int Buscar(Libros libros[], int totalLibros, int id);
    void MostrarL(Libros libros[], int totalLibros);
    void BuscarLibro(Libros libros[], int totalLibros);
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
    string getNombre() { return Nombre; }

    bool Vacio();
    void RegistrarU(Usuario usuarios[], int &totalUsuarios);
    void EliminarU(Usuario usuarios[], int &totalUsuarios);
    int Buscar(Usuario usuarios[], int totalUsuarios, int id);
    void MostrarU(Usuario usuarios[], int totalUsuarios);
    void BuscarUsuario(Usuario usuarios[], int totalUsuarios);
};

class Prestamo : public Usuario, public Libros
{
private:
    int ID;
    int ID_L;
    int ID_U;
    string fecha_inicio;
    string fecha_final;

public:
    Prestamo() : ID(0), ID_L(0), ID_U(0), fecha_inicio(""), fecha_final("") {}

    bool Vacio();
    void RegistrarP(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int &totalPrestamos, int totalLibros, int totalUsuarios);
    void EliminarP(Prestamo prestamos[], int &totalPrestamos);
    int Buscar(Prestamo prestamos[], int totalPrestamos, int id);
    void MostrarP(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int totalPrestamos, int totalLibros, int totalUsuarios);
    void BuscarPrestamos(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int totalPrestamos, int totalLibros, int totalUsuarios);
};

class Biblioteca
{
public:
    Biblioteca();
    void GestionarLibros(Libros libros[], int &totalLibros);
    void GestionarUsuarios(Usuario usuarios[], int &totalUsuarios);
    void GestionarPrestamos(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int &totalPrestamos, int &totalLibros, int &totalUsuarios);
};

#endif // BIBLIOTECA_H