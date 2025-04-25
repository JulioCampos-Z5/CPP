#include "Biblioteca.h"

/* ====================== Clase Libros ====================== */

bool Libros::Vacio() { return ID == 0; }

void Libros::Agregar(Libros libros[], int &totalLibros)
{
    int id, cantidad;
    string titulo, autor, anoP;

    // Validar ID (entero)
    cout << "|Ingrese ID del libro (entero): ";
    while (!(cin >> id))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    // Validar Título (no vacío)
    cout << "|Ingrese Título: ";
    while (true)
    {
        getline(cin, titulo);
        if (!titulo.empty())
            break;
        cout << "|El título no puede estar vacío. Intenta de nuevo: ";
    }

    // Validar Autor (no vacío)
    cout << "|Ingrese Autor: ";
    while (true)
    {
        getline(cin, autor);
        if (!autor.empty())
            break;
        cout << "|El autor no puede estar vacío. Intenta de nuevo: ";
    }

    // Validar Año de Publicación (solo números, opcional: rango de años)
    cout << "|Ingrese Año de Publicación (número): ";
    while (true)
    {
        getline(cin, anoP);
        if (!anoP.empty()) // Rango opcional
            break;
        cout << "|Año inválido.: ";
    }

    // Validar Cantidad (entero no negativo)
    cout << "|Ingrese Cantidad (entero no negativo): ";
    while (!(cin >> cantidad) || cantidad < 0)
    {
        cout << "|Entrada inválida. Ingrese un número entero no negativo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    // Asignar valores al arreglo
    libros[totalLibros].setID(id);
    libros[totalLibros].Titulo = titulo;
    libros[totalLibros].Autor = autor;
    libros[totalLibros].AnoP = anoP;
    libros[totalLibros].Cantidad = cantidad;
    libros[totalLibros].Disponible = cantidad > 0;

    totalLibros++;
    cout << "| Libro Registrado Exitosamente |" << endl;
}

void Libros::EliminarL(Libros libros[], int &totalLibros)
{
    int id;
    cout << "|Ingrese el ID del libro que desea eliminar: ";
    while (!(cin >> id))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

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
        cout << "|ID: " << libros[i].getID()
             << " | Título: " << libros[i].Titulo
             << " | Autor: " << libros[i].Autor
             << " | Año: " << libros[i].AnoP
             << " | Cantidad: " << libros[i].Cantidad
             << " | Disponible: " << (libros[i].Disponible ? "Si" : "No") << " |" << endl;
    }
    if (totalLibros == NULL)
    {
        cout << "|Libros:0|" << endl;
    }
}

void Libros::BuscarLibro(Libros libros[], int totalLibros)
{
    int id;
    cout << "|Ingrese el ID del libro que desea buscar: ";
    cin >> id;

    int index = Buscar(libros, totalLibros, id);
    if (index != -1)
    {
        cout << "|Libro encontrado|" << endl;
        cout << "| ID: " << libros[index].getID()
             << " | Título: " << libros[index].Titulo
             << " | Autor: " << libros[index].Autor
             << " | Año: " << libros[index].AnoP
             << " | Cantidad: " << libros[index].Cantidad
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

    // Validar ID (entero)
    cout << "|Ingrese ID del usuario (entero): ";
    while (!(cin >> id))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    // Validar Nombre (no vacío, solo letras y espacios)
    cout << "|Ingrese Nombre: ";
    while (true)
    {
        getline(cin, nombre);
        bool esValido = !nombre.empty() && all_of(nombre.begin(), nombre.end(), [](char c)
                                                  { return isalpha(c) || isspace(c); });
        if (esValido)
            break;
        cout << "|El nombre no puede estar vacío y solo debe contener letras. Intenta de nuevo: ";
    }

    // Validar Correo (formato básico)
    cout << "|Ingrese Correo: ";
    while (true)
    {
        getline(cin, correo);
        regex formatoCorreo(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        if (regex_match(correo, formatoCorreo))
            break;
        cout << "|El correo no tiene un formato válido. Intenta de nuevo: ";
    }

    // Validar Dirección (no vacía)
    cout << "|Ingrese Dirección: ";
    while (true)
    {
        getline(cin, direccion);
        if (!direccion.empty())
            break;
        cout << "|La dirección no puede estar vacía. Intenta de nuevo: ";
    }

    // Validar Estatus (no vacío, opcional: valores predefinidos)
    cout << "|Ingrese Estatus: ";
    while (true)
    {
        getline(cin, estatus);
        if (!estatus.empty())
            break;
        cout << "|El estatus no puede estar vacío. Intenta de nuevo: ";
    }

    // Asignar valores al arreglo
    usuarios[totalUsuarios].setID(id);
    usuarios[totalUsuarios].Nombre = nombre;
    usuarios[totalUsuarios].Correo = correo;
    usuarios[totalUsuarios].Direccion = direccion;
    usuarios[totalUsuarios].Estatus = estatus;

    totalUsuarios++;
    cout << "| Usuario Registrado Exitosamente |" << endl;
}

void Usuario::EliminarU(Usuario usuarios[], int &totalUsuarios)
{
    int id;
    cout << "|Ingrese el ID del usuario que desea eliminar: ";
    while (!(cin >> id))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

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
        cout << "|ID: " << usuarios[i].getID()
             << " | Nombre: " << usuarios[i].Nombre
             << " | Correo: " << usuarios[i].Correo
             << " | Dirección: " << usuarios[i].Direccion
             << " | Estatus: " << usuarios[i].Estatus << " |" << endl;
    }
    if (totalUsuarios == NULL)
    {
        cout << "|Usuarios:0|" << endl;
    }
}

void Usuario::BuscarUsuario(Usuario usuarios[], int totalUsuarios)
{
    int id;
    cout << "|Ingrese el ID del usuario que desea buscar: ";
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
    bool estado;
    int id_L, id_U;
    string fecha_inicio, fecha_final;

    // Validar ID del libro
    cout << "|Ingrese ID del libro: ";
    while (!(cin >> id_L))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID del libro: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    // Validar ID del usuario
    cout << "|Ingrese ID del usuario: ";
    while (!(cin >> id_U))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID del usuario: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    // Verificar si existen el libro y el usuario
    int libroIndex = Libros().Buscar(libros, totalLibros, id_L);
    int usuarioIndex = Usuario().Buscar(usuarios, totalUsuarios, id_U);

    if (libroIndex == -1)
    {
        cout << "| Libro no encontrado! |" << endl;
        return;
    }
    if (usuarioIndex == -1)
    {
        cout << "| Usuario no encontrado! |" << endl;
        return;
    }

    // Verificar disponibilidad del libro
    if (libros[libroIndex].getCantidad() <= 0)
    {
        cout << "| No hay ejemplares disponibles para este libro. |" << endl;
        return;
    }

    // Validar formato de la fecha de inicio
    cout << "|Ingrese fecha de inicio (DD-MM-YYYY): ";
    while (true)
    {
        getline(cin, fecha_inicio);
        regex formatoFecha(R"(^\d{2}-\d{2}-\d{4}$)");
        if (regex_match(fecha_inicio, formatoFecha))
            break;
        cout << "|Formato inválido. Intente de nuevo (DD-MM-YYYY): ";
    }

    // Validar formato de la fecha de entrega
    cout << "|Ingrese fecha de entrega (DD-MM-YYYY): ";
    while (true)
    {
        getline(cin, fecha_final);
        regex formatoFecha(R"(^\d{2}-\d{2}-\d{4}$)");
        if (regex_match(fecha_final, formatoFecha) && fecha_final >= fecha_inicio)
            break;
        cout << "|Formato inválido o fecha de entrega anterior a la de inicio. Intente de nuevo (DD-MM-YYYY): ";
    }

    estado = true;

    // Registrar el préstamo
    prestamos[totalPrestamos].ID = totalPrestamos + 1;
    prestamos[totalPrestamos].ID_L = id_L;
    prestamos[totalPrestamos].ID_U = id_U;
    prestamos[totalPrestamos].fecha_inicio = fecha_inicio;
    prestamos[totalPrestamos].fecha_final = fecha_final;
    prestamos[totalPrestamos].Estado = estado;

    // Reducir la cantidad del libro prestado
    libros[libroIndex].setCantidad(libros[libroIndex].getCantidad() - 1);

    totalPrestamos++;
    cout << "| Préstamo Registrado Exitosamente |" << endl;
}

void Prestamo::EliminarP(Prestamo prestamos[], int &totalPrestamos)
{
    int id;
    cout << "|Ingrese el ID del préstamo que desea eliminar: ";
    while (!(cin >> id))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

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

void Prestamo::Devolucion(Prestamo prestamos[], Libros libros[], int &totalPrestamos, int totalLibros)
{
    int id;
    cout << "|Ingrese el ID del préstamo que desea devolver: ";
    while (!(cin >> id))
    {
        cout << "|Entrada inválida. Ingrese un número entero para el ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    // Buscar el préstamo
    int indexPrestamo = Buscar(prestamos, totalPrestamos, id);
    if (indexPrestamo == -1)
    {
        cout << "| Préstamo no encontrado! |" << endl;
        return;
    }

    // Verificar si el préstamo ya fue devuelto
    if (!prestamos[indexPrestamo].Estado)
    {
        cout << "| El préstamo ya fue devuelto anteriormente! |" << endl;
        return;
    }

    // Buscar el libro asociado al préstamo
    int libroIndex = Libros().Buscar(libros, totalLibros, prestamos[indexPrestamo].ID_L);
    if (libroIndex == -1)
    {
        cout << "| Libro asociado al préstamo no encontrado! |" << endl;
        return;
    }

    // Incrementar la cantidad de libros
    libros[libroIndex].setCantidad(libros[libroIndex].getCantidad() + 1);

    // Marcar el préstamo como devuelto
    prestamos[indexPrestamo].Estado = false;

    cout << "| Devolución registrada exitosamente. Cantidad de libros actualizada. |" << endl;
}

void Prestamo::MostrarP(Prestamo prestamos[], int totalPrestamos, Libros libros[], int totalLibros, Usuario usuarios[], int totalUsuarios)
{
    for (int i = 0; i < totalPrestamos; i++)
    {
        // Buscar el libro por su ID
        int libroIndex = Libros().Buscar(libros, totalLibros, prestamos[i].ID_L);
        string tituloLibro = (libroIndex != -1) ? libros[libroIndex].getTitulo() : "Libro no encontrado";

        // Buscar el usuario por su ID
        int usuarioIndex = Usuario().Buscar(usuarios, totalUsuarios, prestamos[i].ID_U);
        string nombreUsuario = (usuarioIndex != -1) ? usuarios[usuarioIndex].getNombre() : "Usuario no encontrado";

        // Mostrar los detalles del préstamo
        cout << "|ID Préstamo: " << prestamos[i].ID
             << " | Libro: " << tituloLibro
             << " | Usuario: " << nombreUsuario
             << " | Fecha Inicio: " << prestamos[i].fecha_inicio
             << " | Fecha Final: " << prestamos[i].fecha_final
             << " | Estado: " << (prestamos[i].Estado ? "Activo" : "No Activo")
             << " |" << endl;
    }
    if (totalPrestamos == NULL)
    {
        cout << "|Prestamos: 0 |" << endl;
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
             << " | Estado: " << (prestamos[index].Estado ? "Activo" : "No Activo")
             << " |" << endl;
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
        cout << "|     Usuarios     |" << endl
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
    while (opc != 6)
    {
        cout << "|     Prestamos    |" << endl
             << "|1.Registrar       |" << endl
             << "|2.Mostrar         |" << endl
             << "|3.Devolver        |" << endl
             << "|4.Eliminar        |" << endl
             << "|5.Buscar          |" << endl
             << "|6.Regresar al menu|" << endl
             << "|:";
        cin >> opc;
        switch (opc)
        {
        case 1:
            prestamos[totalPrestamos].RegistrarP(prestamos, libros, usuarios, totalPrestamos, totalLibros, totalUsuarios);
            break;
        case 2:
            prestamos[totalPrestamos].MostrarP(prestamos, totalPrestamos, libros, totalLibros, usuarios, totalUsuarios);
            break;
        case 3:
            prestamos[totalPrestamos].Devolucion(prestamos, libros, totalPrestamos, totalLibros);
            break;
        case 4:
            prestamos[totalPrestamos].EliminarP(prestamos, totalPrestamos);
            break;
        case 5:
            usuarios[totalUsuarios].BuscarUsuario(usuarios, totalUsuarios);
            break;
        case 6:
            break;
        default:
            cout << "|Opción no válida.|" << endl;
            break;
        }
    }
}
