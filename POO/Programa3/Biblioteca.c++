#include "Biblioteca.h"

/* ====================== Clase Libros ====================== */

bool Libros::Vacio() { return ID == 0; }

void Libros::Agregar(Libros libros[], int &totalLibros)
{
    int id, cantidad;
    string titulo, autor, anoP;

    cout << "|Ingrese ID del libro: ";
    cin >> id;
    cout << "|Ingrese Título: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "|Ingrese Autor: ";
    getline(cin, autor);
    cout << "|Ingrese Año de Publicación: ";
    getline(cin, anoP);
    cout << "|Ingrese Cantidad: ";
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

void Libros::EliminarL(Libros libros[], int &totalLibros)
{
    int id;
    cout << "|Ingrese el ID del libro que desea eliminar: ";
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

void Libros::MostrarL(Libros libros[], int totalLibros)
{
    for (int i = 0; i < totalLibros; i++)
    {
        cout << "| ID: " << libros[i].getID() << " | Título: " << libros[i].Titulo
             << " | Autor: " << libros[i].Autor << " | Año: " << libros[i].AnoP
             << " | Disponible: " << (libros[i].Disponible ? "Sí" : "No") << " |" << endl;
    }
}

void Libros::BuscarLibro(Libros libros[], int totalLibros)
{
    int id;
    cout << "Ingrese el ID del libro que desea buscar: ";
    cin >> id;

    int index = Buscar(libros, totalLibros, id);
    if (index != -1)
    {
        cout << "|Libro encontrado|" << endl;
        cout << "| ID: " << libros[index].getID() << " | Título: " << libros[index].Titulo
             << " | Autor: " << libros[index].Autor << " | Año: " << libros[index].AnoP
             << " | Disponible: " << (libros[index].Disponible ? "Sí" : "No") << " |" << endl;
    }
    else
    {
        cout << "|Libro no encontrado!|" << endl;
    }
}

/* ====================== Clase Usuario ====================== */

bool Usuario::Vacio() { return ID == 0; }

void Usuario::RegistrarU(Usuario usuarios[], int &totalUsuarios)
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

void Usuario::EliminarU(Usuario usuarios[], int &totalUsuarios)
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

void Usuario::MostrarU(Usuario usuarios[], int totalUsuarios)
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        cout << "| ID: " << usuarios[i].getID() << " | Nombre: " << usuarios[i].Nombre
             << " | Correo: " << usuarios[i].Correo << " | Dirección: " << usuarios[i].Direccion
             << " | Estatus: " << usuarios[i].Estatus << " |" << endl;
    }
}

void Usuario::BuscarUsuario(Usuario usuarios[], int totalUsuarios)
{
    int id;
    cout << "Ingrese el ID del usuario que desea buscar: ";
    cin >> id;

    int index = Buscar(usuarios, totalUsuarios, id);
    if (index != -1)
    {
        cout << "|Usuario encontrado|" << endl;
        cout << "| ID: " << usuarios[index].getID() << " | Nombre: " << usuarios[index].Nombre
             << " | Correo: " << usuarios[index].Correo << " | Dirección: " << usuarios[index].Direccion
             << " | Estatus: " << usuarios[index].Estatus << " |" << endl;
    }
    else
    {
        cout << "|Usuario no encontrado!|" << endl;
    }
}

/* ====================== Clase Prestamo ====================== */

bool Prestamo::Vacio() { return ID == 0; }

void Prestamo::RegistrarP(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int &totalPrestamos, int totalLibros, int totalUsuarios)
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

void Prestamo::EliminarP(Prestamo prestamos[], int &totalPrestamos)
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

void Prestamo::MostrarP(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int totalPrestamos, int totalLibros, int totalUsuarios)
{
    for (int i = 0; i < totalPrestamos; i++)
    {
        // Buscar el título del libro
        int libroIndex = Libros().Buscar(libros, totalLibros, prestamos[i].ID_L);
        string tituloLibro = (libroIndex != -1) ? libros[libroIndex].getTitulo() : "Desconocido";

        // Buscar el nombre del usuario
        int usuarioIndex = Usuario().Buscar(usuarios, totalUsuarios, prestamos[i].ID_U);
        string nombreUsuario = (usuarioIndex != -1) ? usuarios[usuarioIndex].getNombre() : "Desconocido";

        // Mostrar la información del préstamo
        cout << "| ID: " << prestamos[i].ID
             << " | Título: " << tituloLibro
             << " | Usuario: " << nombreUsuario
             << " | Fecha Inicio: " << prestamos[i].fecha_inicio
             << " | Fecha Final: " << prestamos[i].fecha_final << " |" << endl;
    }
}

void Prestamo::BuscarPrestamos(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int totalPrestamos, int totalLibros, int totalUsuarios)
{
    int id;
    cout << "Ingrese el ID del préstamo que desea buscar: ";
    cin >> id;

    int index = Buscar(prestamos, totalPrestamos, id);
    if (index != -1)
    {
        // Buscar el título del libro
        int libroIndex = Libros().Buscar(libros, totalLibros, prestamos[index].ID_L);
        string tituloLibro = (libroIndex != -1) ? libros[libroIndex].getTitulo() : "Desconocido";

        // Buscar el nombre del usuario
        int usuarioIndex = Usuario().Buscar(usuarios, totalUsuarios, prestamos[index].ID_U);
        string nombreUsuario = (usuarioIndex != -1) ? usuarios[usuarioIndex].getNombre() : "Desconocido";

        // Mostrar la información del préstamo
        cout << "|Préstamo encontrado|" << endl;
        cout << "| ID: " << prestamos[index].ID
             << " | Título: " << tituloLibro
             << " | Usuario: " << nombreUsuario
             << " | Fecha Inicio: " << prestamos[index].fecha_inicio
             << " | Fecha Final: " << prestamos[index].fecha_final << " |" << endl;
    }
    else
    {
        cout << "|Préstamo no encontrado!|" << endl;
    }
}

/* ====================== Clase Biblioteca ====================== */

Biblioteca::Biblioteca() {}

void Biblioteca::GestionarLibros(Libros libros[], int &totalLibros)
{
    int opc;
    while (opc != 5)
    {
        cout << "|      Libros      |" << endl
             << "|1.Agregar         |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Buscar          |" << endl
             << "|5.Regresar al menu|" << endl
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
            libros[totalLibros].BuscarLibro(libros, totalLibros);
            break;
        case 5:
            break;
        default:
            cout << "|Opción no válida.|" << endl;
            break;
        }
    }
}

void Biblioteca::GestionarUsuarios(Usuario usuarios[], int &totalUsuarios)
{
    int opc;
    while (opc != 5)
    {
        cout << "|      Usuarios    |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Buscar          |" << endl
             << "|5.Regresar al menu|" << endl
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
            usuarios[totalUsuarios].BuscarUsuario(usuarios, totalUsuarios);
            break;
        case 5:
            break;
        default:
            cout << "|Opción no válida.|" << endl;
            break;
        }
    }
}

void Biblioteca::GestionarPrestamos(Prestamo prestamos[], Libros libros[], Usuario usuarios[], int &totalPrestamos, int &totalLibros, int &totalUsuarios)
{
    int opc;
    while (opc != 5)
    {
        cout << "|     Prestamos    |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Eliminar        |" << endl
             << "|4.Buscar          |" << endl
             << "|5.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            prestamos[totalPrestamos].RegistrarP(prestamos, libros, usuarios, totalPrestamos, totalLibros, totalUsuarios);
            break;
        case 2:
            prestamos[totalPrestamos].MostrarP(prestamos, libros, usuarios, totalPrestamos, totalLibros, totalUsuarios);
            break;
        case 3:
            prestamos[totalPrestamos].EliminarP(prestamos, totalPrestamos);
            break;
        case 4:
            prestamos[totalPrestamos].BuscarPrestamos(prestamos, libros, usuarios, totalPrestamos, totalLibros, totalUsuarios);
            break;
        case 5:
            break;
        default:
            cout << "|Opción no válida.|" << endl;
            break;
        }
    }
}