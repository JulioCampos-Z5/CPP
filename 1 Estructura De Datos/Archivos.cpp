#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Estudiante
{
private:
    string código;
    string nombre;
    string apellidoPa;
    string apellidoMa;
    float promedio;

public:
    Estudiante(string valorCódigo = "", string valorNombre = "", string valorApellidoPa = "", string valorApellidoMa = "", float valorPromedio = 0.0)
    {
        establecerCódigo(valorCódigo);
        establecerNombre(valorNombre);
        establecerApellidoPa(valorApellidoPa);
        establecerApellidoMa(valorApellidoMa);
        establecerPromedio(valorPromedio);
    }

    string obtenerCódigo() const { return código; }
    void establecerCódigo(string cCódigo) { código = cCódigo; }
    string obtenerNombre() const { return nombre; }
    void establecerNombre(string cNombre) { nombre = cNombre; }
    string obtenerApellidoPa() const { return apellidoPa; }
    void establecerApellidoPa(string cApellidoPa) { apellidoPa = cApellidoPa; }
    string obtenerApellidoMa() const { return apellidoMa; }
    void establecerApellidoMa(string cApellidoMa) { apellidoMa = cApellidoMa; }
    float obtenerPromedio() const { return promedio; }
    void establecerPromedio(float P) { promedio = P; }

    friend ostream &operator<<(ostream &os, const Estudiante &estudiante)
    {
        os << estudiante.obtenerCódigo() << ","
           << estudiante.obtenerNombre() << ","
           << estudiante.obtenerApellidoPa() << ","
           << estudiante.obtenerApellidoMa() << ","
           << estudiante.obtenerPromedio();
        return os;
    }
    friend istream &operator>>(istream &is, Estudiante &estudiante)
    {
        string codigo, nombre, apellidoPa, apellidoMa;
        float promedio;

        // Lee los campos separados por comas desde el flujo de entrada
        getline(is, codigo, ',');
        getline(is, nombre, ',');
        getline(is, apellidoPa, ',');
        getline(is, apellidoMa, ',');
        is >> promedio;

        // Establece los valores en el objeto Estudiante
        estudiante.establecerCódigo(codigo);
        estudiante.establecerNombre(nombre);
        estudiante.establecerApellidoPa(apellidoPa);
        estudiante.establecerApellidoMa(apellidoMa);
        estudiante.establecerPromedio(promedio);

        // Descarta el carácter de salto de línea
        is.ignore();

        return is;
    }
};
Estudiante nuevoEstudiante;
int C;
string N, aP, aM;
float P;

void Agregar(string nombreArchivo)
{
    cout << "|Ingrese el codigo: ";
    cin >> C;

    // Abre el archivo en modo lectura
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada)
    {
        cerr << "|Error al abrir el archivo|" << endl;
        fstream crearArchivo(nombreArchivo, ios::out);
        return;
    }

    Estudiante nuevoEstudiante;

    // Lee el registro con el código especificado
    while (archivoEntrada >> nuevoEstudiante)
    {
        if (stoi(nuevoEstudiante.obtenerCódigo()) == C)
        {
            cerr << "|Estudiante #" << C << " ya existe|" << endl;
            archivoEntrada.close();
            return;
        }
    }

    archivoEntrada.close();

    // Abre el archivo en modo escritura (append)
    ofstream archivoSalida(nombreArchivo, ios::app);
    if (!archivoSalida)
    {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    nuevoEstudiante.establecerCódigo(to_string(C));

    cout << "|Escribe Nombre(s), Apellido paternos, Apellido maternos, Promedio: ";
    cin >> N >> aP >> aM >> P;

    nuevoEstudiante.establecerNombre(N);
    nuevoEstudiante.establecerApellidoPa(aP);
    nuevoEstudiante.establecerApellidoMa(aM);
    nuevoEstudiante.establecerPromedio(P);

    archivoSalida << nuevoEstudiante << endl;

    archivoSalida.close();
}
void Eliminar(string nombreArchivo)
{
    cout << "|Ingrese el codigo: ";
    cin >> C;

    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada)
    {
        cerr << "|Error al abrir el archivo|" << endl;
        return;
    }

    Estudiante nuevoEstudiante;
    bool encontrado = false;
    ofstream archivoNuevo("temp.csv");

    while (archivoEntrada >> nuevoEstudiante)
    {
        if (stoi(nuevoEstudiante.obtenerCódigo()) != C)
        {
            archivoNuevo << nuevoEstudiante << endl;
        }
        else
        {
            encontrado = false;
        }
    }

    archivoEntrada.close();
    archivoNuevo.close();
    if (!encontrado)
    {
        cout << "|Estudiante no encontrado|" << endl;
    }

    remove(nombreArchivo.c_str());
    rename("temp.csv", nombreArchivo.c_str());
}
void Buscar(string nombreArchivo)
{
    string nombreCompleto;
    int D;

    cout << "|1.Buscar por codigo//2.Por nombre| \n|: ";
    cin >> D;
    if (D == 1)
    {

        cout << "|Ingrese el codigo: ";
        cin >> C;
    }
    else
    {
        cout << "|Ingrese el nombre: ";
        cin >> nombreCompleto;
    }

    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada)
    {
        cerr << "|Error al abrir el archivo|" << endl;
        return;
    }

    Estudiante nuevoEstudiante;

    bool encontrado = false;

    while (archivoEntrada >> nuevoEstudiante)
    {
        if (stoi(nuevoEstudiante.obtenerCódigo()) == C || nuevoEstudiante.obtenerNombre() == nombreCompleto)
        {
            cout << "|Estudiante encontrado:" << endl;
            cout << "|Codigo: " << nuevoEstudiante.obtenerCódigo() << endl;
            cout << "|Nombre: " << nuevoEstudiante.obtenerNombre() << endl;
            cout << "|Apellido Paterno: " << nuevoEstudiante.obtenerApellidoPa() << endl;
            cout << "|Apellido Materno: " << nuevoEstudiante.obtenerApellidoMa() << endl;
            cout << "|Promedio: " << nuevoEstudiante.obtenerPromedio() << endl;
            encontrado = true;
            break;
        }
        else
        {
            encontrado = false;
        }
    }

    archivoEntrada.close();

    if (!encontrado)
    {
        cout << "|Estudiante no encontrado|" << endl;
    }
}
void Modificar(string nombreArchivo)
{
    cout << "|Ingrese el codigo: ";
    cin >> C;

    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada)
    {
        cerr << "|Error al abrir el archivo|" << endl;
        return;
    }

    Estudiante nuevoEstudiante;
    ofstream archivoNuevo("temp.csv");

    bool encontrado = false;

    while (archivoEntrada >> nuevoEstudiante)
    {
        if (stoi(nuevoEstudiante.obtenerCódigo()) == C)
        {
            string N, aP, aM;
            float P;

            cout << "|Escribe Nombre, Apellido paternos, Apellido maternos, Promedio \n|: ";
            cin >> N >> aP >> aM >> P;

            nuevoEstudiante.establecerNombre(N);
            nuevoEstudiante.establecerApellidoPa(aP);
            nuevoEstudiante.establecerApellidoMa(aM);
            nuevoEstudiante.establecerPromedio(P);

            encontrado = true;
        }

        archivoNuevo << nuevoEstudiante << endl;
    }

    archivoEntrada.close();
    archivoNuevo.close();

    if (!encontrado)
    {
        cerr << "|Estudiante #" << C << " no existe|" << endl;
    }
    else
    {
        remove(nombreArchivo.c_str());
        rename("temp.csv", nombreArchivo.c_str());
    }
}
void Imprimir(string nombreArchivo)
{
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada)
    {
        cerr << "|Error al abrir el archivo|" << endl;
        return;
    }

    Estudiante nuevoEstudiante;

    cout << left << setw(10) << "|Codigo" << setw(16) << "Nombre" << setw(11) << "Apellido Pa " << setw(11) << "Apellido Ma" << left << setw(10) << right << "Promedio"
         << "|" << endl;

    while (archivoEntrada >> nuevoEstudiante)
    {
        cout << "|" << left << setw(10) << nuevoEstudiante.obtenerCódigo() << setw(16) << nuevoEstudiante.obtenerNombre()
             << setw(11) << nuevoEstudiante.obtenerApellidoPa() << setw(11) << nuevoEstudiante.obtenerApellidoMa()
             << left << setw(10) << right << nuevoEstudiante.obtenerPromedio() << "|" << endl;
    }

    archivoEntrada.close();
}

void Menu()
{
    string nombreArchivo = "estudiantes.csv";

    int opc;
    do
    {
        cout << "|                             MENU                               |" << endl
             << "|1.ALTA ESTUDIANTE             ||2.BAJA ESTUDIANTE               |" << endl
             << "|3.CONSULTA ESTUDIANTE         ||4.MODIFICAR DATOS DEL ESTUDIANTE|" << endl
             << "|5.MOSTRAR TODOS LOS REGISTROS ||6.SALIR                         |" << endl
             << "|:";
        cin >> opc;

        switch (opc)
        {
        case 1: // Alta estudiante
            Agregar(nombreArchivo);
            break;
        case 2: // Baja estudiante
            Eliminar(nombreArchivo);
            break;
        case 3: // Consulta estudiante
            Buscar(nombreArchivo);
            break;
        case 4: // Modificar datos del estudiante
            Modificar(nombreArchivo);
            break;
        case 5: // Mostrar todos los registros
            Imprimir(nombreArchivo);
            break;
        case 6:
            cout << "|SALIO DEL PROGRAMA|";
            break;
        default:
            cout << "|Opcion no valida. Intente nuevamente|" << endl;
            break;
        }
    } while (opc != 6);
}

int main()
{
    Menu();

    return 0;
}