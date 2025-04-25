#include "Biblioteca.h"

/* ====================== Clase Libros ====================== */

bool Libros::Vacio() { return ID == 0; } // Metodo que valida si el objeto esta vacio

void Libros::Agregar(Libros libros[], int &totalLibros) // Funcion que registra los Libros
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

void Libros::Eliminar(Libros libros[], int &totalLibros) // Funcion que elimina los Libros
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

int Libros::Buscar(Libros libros[], int totalLibros, int id) // Funcion que Busca los libros
{
    for (int i = 0; i < totalLibros; i++)
    {
        if (libros[i].getID() == id)
            return i;
    }
    return -1;
}

void Libros::Mostrar(Libros libros[], int totalLibros) // Funcion que mestra todos los libros
{
    for (int i = 0; i < totalLibros; i++)
    {
        cout << "|ID|" << libros[i].getID() << "| Título: " << libros[i].Titulo
             << " | Autor: " << libros[i].Autor << " | Año: " << libros[i].AnoP
             << " | Disponible: " << (libros[i].Disponible ? "Sí" : "No") << " |" << endl;
    }
}

/* ====================== Clase Usuario ====================== */

bool Usuario::Vacio() { return ID == 0; } // Metodo que valida si el objeto esta vacio

void Usuario::Registrar(Usuario usuarios[], int &totalUsuarios) // Funcion que registra los Usuarios
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

void Usuario::Eliminar(Usuario usuarios[], int &totalUsuarios) // Funcion que elimina los Usuarios
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

int Usuario::Buscar(Usuario usuarios[], int totalUsuarios, int id) // Funcion que Busca los Usuarios
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (usuarios[i].getID() == id)
            return i;
    }
    return -1;
}

void Usuario::Mostrar(Usuario usuarios[], int totalUsuarios) // Funcion que mestra todos los Usuarios
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        cout << "|ID|" << usuarios[i].getID() << "| Nombre: " << usuarios[i].Nombre
             << " | Correo: " << usuarios[i].Correo << " | Dirección: " << usuarios[i].Direccion
             << " | Estatus: " << usuarios[i].Estatus << " |" << endl;
    }
}

/* ====================== Clase Biblioteca ====================== */

bool Biblioteca::Vacio() { return ID == 0; } // Metodo que valida si el objeto esta vacio

void Biblioteca::Registrar(Biblioteca bibliotecas[], Libros libros[], Usuario usuarios[], int &totalBibliotecas, int totalLibros, int totalUsuarios) // Funcion que registra los Datos
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
        bibliotecas[totalBibliotecas].ID = totalBibliotecas + 1;
        bibliotecas[totalBibliotecas].ID_L = id_L;
        bibliotecas[totalBibliotecas].ID_U = id_U;
        bibliotecas[totalBibliotecas].fecha_inicio = fecha_inicio;
        bibliotecas[totalBibliotecas].fecha_final = fecha_final;

        totalBibliotecas++;
        cout << "|Préstamo Registrado|" << endl;
    }
    else
    {
        cout << "|Libro o Usuario no encontrado!|" << endl;
    }
}

void Biblioteca::Eliminar(Biblioteca bibliotecas[], int &totalBibliotecas) // Funcion que elimina los Datos
{
    int id;
    cout << "Ingrese el ID del préstamo que desea eliminar: ";
    cin >> id;

    int index = Buscar(bibliotecas, totalBibliotecas, id);
    if (index != -1)
    {
        for (int i = index; i < totalBibliotecas - 1; i++)
        {
            bibliotecas[i] = bibliotecas[i + 1];
        }
        totalBibliotecas--;
        cout << "|Préstamo Eliminado|" << endl;
    }
    else
    {
        cout << "|Préstamo no encontrado!|" << endl;
    }
}

int Biblioteca::Buscar(Biblioteca bibliotecas[], int totalBibliotecas, int id) // Funcion que Busca los Datos
{
    for (int i = 0; i < totalBibliotecas; i++)
    {
        if (bibliotecas[i].ID == id)
            return i;
    }
    return -1;
}

void Biblioteca::Mostrar(Biblioteca bibliotecas[], int totalBibliotecas) // Funcion que mestra todos los Datos
{
    for (int i = 0; i < totalBibliotecas; i++)
    {
        cout << "|ID|" << bibliotecas[i].ID << "| ID Libro: " << bibliotecas[i].ID_L
             << " | ID Usuario: " << bibliotecas[i].ID_U << " | Fecha Inicio: " << bibliotecas[i].fecha_inicio
             << " | Fecha Final: " << bibliotecas[i].fecha_final << " |" << endl;
    }
}