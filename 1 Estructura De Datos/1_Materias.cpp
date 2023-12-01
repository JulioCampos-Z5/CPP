#include <iostream>
#include <conio.h>
#include <string>

enum MENU
{
    M_DATOS = 1,
    A_MATERIA,
    BUSCAR,
    E_DATOS,
    SALIR
};

class Materia
{
private:
    int Clave;
    std::string Nombre;
    std::string ProfesorTit;
    std::string LibroTexto;

public:
    Materia() {}

    int getClave(int) { return Clave; }

    std::string getNombre(std::string) { return Nombre; }

    std::string getProfesorTit(std::string) { return ProfesorTit; }

    std::string getLibroTexto(std::string) { return LibroTexto; }

    void Imprime() { std::cout << "|Clave: " << Clave << " |Nombre: " << Nombre << " |Profesor: " << ProfesorTit << " |Libro:" << LibroTexto << std::endl; }
    void Agregar()
    {
        std::cout << "|Calve: ";
        std::cin >> Clave;
        std::cout << "|Nombre: ";
        std::cin >> Nombre;
        std::cout << "|Profesor: ";
        std::cin >> ProfesorTit;
        std::cout << "|Libro: ";
        std::cin >> LibroTexto;
    }
    void CambiaClave()
    {
        std::cout << "Clave: " << Clave << std::endl;
        std::cout << "Ingrese nueva clave: ";
        std::cin >> Clave;
    }
    void CambiaProfe()
    {
        std::cout << "Profesor: " << Clave << std::endl;
        std::cout << "Ingrese nuevo Profesor: ";
        std::cin >> ProfesorTit;
    }
};

int main()
{
    Materia Programación[3];
    Materia BasesDatos[3];

    int opc = 0, i = 0, c = 0, c2 = 0, a;

    do
    {
        system("cls");
        std::cout << "|Menu|" << std::endl
                  << "|1.Mostrar datos" << std::endl
                  << "|2.Agregar Materia" << std::endl
                  << "|3.Buscar" << std::endl
                  << "|4.Editar Datos" << std::endl
                  << "|5.Salir:" << std::endl
                  << ": ";
        std::cin >> opc;

        switch (opc)
        {
        case M_DATOS:
            std::cout << "|Clases de Programacion" << std::endl;
            for (int i = 0; i < c; i++)
            {
                Programación[i].Imprime();
            }
            std::cout << std::endl
                      << "|Clases de Bases de Datos" << std::endl;
            for (int i = 0; i < c2; i++)
            {
                BasesDatos[i].Imprime();
            }
            system("pause");
            break;

        case A_MATERIA:
            int agr;
            std::cout << "|Materia" << std::endl
                      << "|1.Programacion" << std::endl
                      << "|2.BasesDatos" << std::endl
                      << ": ";
            std::cin >> agr;

            if (agr == 1)
            {
                std::cout << "Cuantas clases de sea registrar: ";
                std::cin >> a;

                for (int i = 0; i < a; i++)
                {
                    Programación[i].Agregar();
                    c++;
                }
            }
            if (agr == 2)
            {
                std::cout << "Cuantas clases de sea registrar: ";
                std::cin >> a;

                for (int i = 0; i < a; i++)
                {
                    BasesDatos[i].Agregar();
                    c2++;
                }
            }
            break;

        case 3:
            int bus;
            std::cout << "|Materia" << std::endl
                      << "|1.Programacion" << std::endl
                      << "|2.BasesDatos" << std::endl
                      << ": ";
            std::cin >> bus;

            if (bus == 1)
            {
                std::cout << "Ingrese numero de la clase: ";
                std::cin >> i;
                Programación[i].Imprime();
            }
            if (bus == 2)
            {
                std::cout << "Ingrese numero de la clase: ";
                std::cin >> i;
                BasesDatos[i].Imprime();
            }
            break;

        case 4:
            int Editar;
            std::cout << "|Programcion: " << c << "Base de Datos: " << c2 << std::endl
                      << "|Editor de Datos" << std::endl
                      << "|1.Clave" << std::endl
                      << "|2.Profe" << std::endl
                      << ": ";
            std::cin >> Editar;

            switch (Editar)
            {
            case 1:
                int edit;
                std::cout << "|Materia" << std::endl
                          << "|1.Programacion" << std::endl
                          << "|2.BasesDatos" << std::endl
                          << ": ";
                std::cin >> edit;

                if (edit == 1)
                {
                    std::cout << "Ingrese numero de la clase: ";
                    std::cin >> i;
                    Programación[i].CambiaClave();
                }
                if (edit == 2)
                {
                    std::cout << "Ingrese numero de la clase: ";
                    std::cin >> i;
                    BasesDatos[i].CambiaClave();
                }
                break;
            case 2:
                int edit2;
                std::cout
                    << "|Materia" << std::endl
                    << "|1.Programacion" << std::endl
                    << "|2.BasesDatos" << std::endl
                    << ": ";
                std::cin >> edit2;

                if (edit2 == 1)
                {
                    std::cout << "Ingrese numero de la clase: ";
                    std::cin >> i;
                    Programación[i].CambiaProfe();
                }
                if (edit2 == 2)
                {
                    std::cout << "Ingrese numero de la clase: ";
                    std::cin >> i;
                    BasesDatos[i].CambiaProfe();
                }
                break;
            }
            break;

        case 5:
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