#include <iostream>
#include <conio.h>
#include <string>

class Empleado
{
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;

public:
    Empleado() {}

    int getClaveEmpleado(int) { return ClaveEmpleado; }

    std::string getNombre(std::string) { return Nombre; }

    std::string getDomicilio(std::string) { return Domicilio; }

    float getSueldo(float) { return Sueldo; }

    std::string getReportaA(std::string) { return ReportaA; }

    void Imprime() { std::cout << "|Calve: " << ClaveEmpleado << " |Empleado: " << Nombre << " |Domicilio: " << Domicilio << " |Sueldo: " << Sueldo << " |ReportaA: " << ReportaA << std::endl; }

    void Agregar()
    {
        std::cout << "Calve: ";
        std::cin >> ClaveEmpleado;
        std::cout << "Nombre: ";
        std::cin >> Nombre;
        std::cout << "Domicilio: ";
        std::cin >> Domicilio;
        std::cout << "Sueldo: ";
        std::cin >> Sueldo;
        std::cout << "ReportaA: ";
        std::cin >> ReportaA;
    }

    void CambioDomic()
    {
        std::cout << "Domicilio: " << Domicilio << std::endl;
        std::cout << "Ingrese nuevo Domicilio: ";
        std::cin >> Domicilio;
    }

    void CambioReportA()
    {
        std::cout << "ReportaA: " << Sueldo << std::endl;
        std::cout << "Ingrese nuevo ReportaA: ";
        std::cin >> ReportaA;
    }

    void ActualSueldo()
    {
        std::cout << "Sueldo: " << Sueldo << std::endl;
        std::cout << "Ingrese nuevo Sueldo: ";
        std::cin >> Sueldo;
    }
};

int main()
{
    Empleado JefePlanta;
    Empleado JefePersonal;
    Empleado Empleados[2];

    int opc = 0, i, a, c = 0;

    do
    {
        system("cls");
        std::cout << "Cantidad: " << c << std::endl;
        std::cout << "|Menu|" << std::endl
                  << "|1.Mostrar datos" << std::endl
                  << "|2.Agregar Empleado" << std::endl
                  << "|3.Buscar" << std::endl
                  << "|4.Editar Datos" << std::endl
                  << "|5.Salir:" << std::endl
                  << ": ";
        std::cin >> opc;

        switch (opc)
        {
        case 1: // Mostrar Datos
            for (int i = 1; i <= c; i++)
            {
                Empleados[i].Imprime();
            }
            system("pause");
            break;

        case 2: // Agregar empleado
            std::cout << "Cuantos empleados de sea registrar: ";
            std::cin >> a;
            for (int i = 1; i <= a; i++)
            {
                Empleados[i].Agregar();
                c++;
            }
            break;

        case 3: // Buscar Empleado
            std::cout << "Ingrese el numero del empleado: ";
            std::cin >> i;
            Empleados[i].Imprime();
            system("pause");
            break;

        case 4: // Editar Datos
            int Editar;
            std::cout << "|Editor de Datos" << std::endl
                      << "|1.Domicilio" << std::endl
                      << "|2.Sueldo" << std::endl
                      << "|3.ReportaA" << std::endl
                      << ": ";
            std::cin >> Editar;
            switch (Editar)
            {
            case 1:
                std::cout << "Ingrese el numero del empleado: ";
                std::cin >> i;
                Empleados[i].CambioDomic();
                break;
            case 2:
                std::cout << "Ingrese el numero del empleado: ";
                std::cin >> i;
                Empleados[i].ActualSueldo();
                break;
            case 3:
                std::cout << "Ingrese el numero del empleado: ";
                std::cin >> i;
                Empleados[i].CambioReportA();
                break;
            case 4:
                break;
            }
            break;

        case 5: // Salir
            std::cout << "Salio del sistema.";
            return 0;
            break;

        default:
            break;
        }

        opc++;
    } while (opc);

    return 0;
}