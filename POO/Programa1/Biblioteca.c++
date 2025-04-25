#include "Biblioteca.h"

/* ====================== Clase Libros ====================== */

bool Libros::Vacio() { return ID == 0; }

void Libros::Agregar(Libros libros[], int& totalLibros)
{
    int id, cantidad;
    string titulo, autor, anoP;

    cout << "Ingrese ID del libro: ";
    cin >> id;
    cout << "Ingrese Título: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese Autor: ";
    getline(cin, autor);
    cout << "Ingrese Año de Publicación: ";
    getline(cin, anoP);
    cout << "Ingrese Cantidad: ";
    cin >> cantidad;

    libros[totalLibros].setID(id);
    libros[totalLibros].Titulo = titulo;
    libros[totalLibros].Autor = autor;
    libros[totalLibros].AnoP = anoP;
    libros[totalLibros].Cantidad = cantidad;
    libros[totalLibros].Disponible = cantidad > 0;

    totalLibros++;
    cout << "|Libro Registrado|" << endl;
}

void Libros::Eliminar(Libros libros[], int& totalLibros)
{
    int id;
    cout << "Ingrese el ID del libro que desea eliminar: ";
    cin >> id;

    int index = Buscar(libros, totalLibros, id);
    if (index != -1)
    {
        for (int i = index; i < totalLibros - 1; i++)
        {
            libros[i] = libros[i + 1];
        }
        totalLibros--;
        cout << "|Libro Eliminado|" << endl;
    }
    else
    {
        cout << "|Libro no encontrado!|" << endl;
    }
}

int Libros::Buscar(Libros libros[], int totalLibros, int id)
{
    for (int i = 0; i < totalLibros; i++)
    {
        if (libros[i].getID() == id)
            return i;
    }
    return -1;
}

void Libros::Mostrar(Libros libros[], int totalLibros)
{
    for (int i = 0; i < totalLibros; i++)
    {
        cout << "|ID|" << libros[i].getID() << "| Título: " << libros[i].Titulo
             << " | Autor: " << libros[i].Autor << " | Año: " << libros[i].AnoP
             << " | Disponible: " << (libros[i].Disponible ? "Sí" : "No") << " |" << endl;
    }
}

/* ====================== Clase Usuario ====================== */

bool Usuario::Vacio() { return ID == 0; }

void Usuario::Registrar(Usuario usuarios[], int& totalUsuarios)
{
    int id;
    string nombre, correo, direccion, estatus;

    cout << "Ingrese ID del usuario: ";
    cin >> id;
    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese Correo: ";
    getline(cin, correo);
    cout << "Ingrese Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese Estatus: ";
    getline(cin, estatus);

    usuarios[totalUsuarios].setID(id);
    usuarios[totalUsuarios].Nombre = nombre;
    usuarios[totalUsuarios].Correo = correo;
    usuarios[totalUsuarios].Direccion = direccion;
    usuarios[totalUsuarios].Estatus = estatus;

    totalUsuarios++;
    cout << "|Usuario Registrado|" << endl;
}

void Usuario::Eliminar(Usuario usuarios[], int& totalUsuarios)
{
    int id;
    cout << "Ingrese el ID del usuario que desea eliminar: ";
    cin >> id;

    int index = Buscar(usuarios, totalUsuarios, id);
    if (index != -1)
    {
        for (int i = index; i < totalUsuarios - 1; i++)
        {
            usuarios[i] = usuarios[i + 1];
        }
        totalUsuarios--;
        cout << "|Usuario Eliminado|" << endl;
    }
    else
    {
        cout << "|Usuario no encontrado!|" << endl;
    }
}

int Usuario::Buscar(Usuario usuarios[], int totalUsuarios, int id)
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (usuarios[i].getID() == id)
            return i;
    }
    return -1;
}

void Usuario::Mostrar(Usuario usuarios[], int totalUsuarios)
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        cout << "|ID|" << usuarios[i].getID() << "| Nombre: " << usuarios[i].Nombre
             << " | Correo: " << usuarios[i].Correo << " | Dirección: " << usuarios[i].Direccion
             << " | Estatus: " << usuarios[i].Estatus << " |" << endl;
    }
}

/* ====================== Clase Prestamo ====================== */

bool Prestamo::Vacio() { return ID == 0; }

void Prestamo::Registrar(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int& totalPrestamos, int totalLibros, int totalUsuarios)
{
    int id_L, id_U;
    string fecha_inicio, fecha_final;

    cout << "Ingrese ID del libro: ";
    cin >> id_L;
    cout << "Ingrese ID del usuario: ";
    cin >> id_U;
    cout << "Ingrese fecha de inicio: ";
    cin >> fecha_inicio;
    cout << "Ingrese fecha de entrega: ";
    cin >> fecha_final;

    // Verificar si existen el libro y el usuario
    int libroIndex = Libros().Buscar(libros, totalLibros, id_L);
    int usuarioIndex = Usuario().Buscar(usuarios, totalUsuarios, id_U);

    if (libroIndex != -1 && usuarioIndex != -1)
    {
        prestamos[totalPrestamos].ID = totalPrestamos + 1;
        prestamos[totalPrestamos].ID_L = id_L;
        prestamos[totalPrestamos].ID_U = id_U;
        prestamos[totalPrestamos].fecha_inicio = fecha_inicio;
        prestamos[totalPrestamos].fecha_final = fecha_final;

        totalPrestamos++;
        cout << "|Préstamo Registrado|" << endl;
    }
    else
    {
        cout << "|Libro o Usuario no encontrado!|" << endl;
    }
}

void Prestamo::Eliminar(Prestamo prestamos[], int& totalPrestamos)
{
    int id;
    cout << "Ingrese el ID del préstamo que desea eliminar: ";
    cin >> id;

    int index = Buscar(prestamos, totalPrestamos, id);
    if (index != -1)
    {
        for (int i = index; i < totalPrestamos - 1; i++)
        {
            prestamos[i] = prestamos[i + 1];
        }
        totalPrestamos--;
        cout << "|Préstamo Eliminado|" << endl;
    }
    else
    {
        cout << "|Préstamo no encontrado!|" << endl;
    }
}

int Prestamo::Buscar(Prestamo prestamos[], int totalPrestamos, int id)
{
    for (int i = 0; i < totalPrestamos; i++)
    {
        if (prestamos[i].ID == id)
            return i;
    }
    return -1;
}

void Prestamo::Mostrar(Prestamo prestamos[], int totalPrestamos)
{
    for (int i = 0; i < totalPrestamos; i++)
    {
        cout << "|ID|" << prestamos[i].ID << "| ID Libro: " << prestamos[i].ID_L
             << " | ID Usuario: " << prestamos[i].ID_U << " | Fecha Inicio: " << prestamos[i].fecha_inicio
             << " | Fecha Final: " << prestamos[i].fecha_final << " |" << endl;
    }
}

