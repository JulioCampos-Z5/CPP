#include <iostream>
#define TAM 3

class Lista
{
private:
    long Datos[TAM];
    long Ultimo;

public:
    Lista() : Ultimo(-1) {} // inicializa
    void Inicializa() { Ultimo = -1; }
    bool Vacía() { return (Ultimo == -1) ? true : false; }      // Este es un if() simplificado: return () ? si : no;
    bool LLena() { return (Ultimo == TAM - 1) ? true : false; } // Este es un if() simplificado: return () ? si : no;
    void Insertar(long Pos, long Elem)
    {

        if (LLena() || Pos < 0 || Pos > Ultimo + 1)
            std::cout << "|Error:Lista llena|" << std::endl;

        for (long i = Ultimo; i >= Pos; i--)
            Datos[i + 1] = Datos[i]; // Este recorre el dato a +1 para dar espacio al elemento

        Datos[Pos] = Elem; // Este Ingresa el elemento en el espacio vació
        Ultimo++;
    }
    void Elimina(long Pos)
    {
        if (Vacía() || Pos < 0 || Pos > Ultimo)
            std::cout << "|Error:Lista vacia|" << std::endl;

        for (long i = Pos; i < Ultimo; i++)
            Datos[i] = Datos[i + 1];
        Ultimo--;
    }
    long Primero() { return (Vacía()) ? -1 : 0; } // Este es un if() simplificado: return () ? si : no;
    long ULtimo() { return Ultimo; }
    long Recupera()
    {
        long Pos;
        if (Vacía() || Pos < 0 || Pos > Ultimo)
            std::cout << "|Error:Lista vacia|" << std::endl;
        return Datos[Pos];
    }
    void Imprime()
    {
        if (Vacía())
            std::cout << "|La lista esta vacia|" << std::endl;

        for (long i = 0; i <= Ultimo; i++)
            std::cout << "|" << i << "|" << Datos[i] << "|" << std::endl;
    }
    void Anula() { Ultimo = -1; } // Esta función vacía la lista, la pone en -1
    void Agregar()
    {
        long Agr;
        if (LLena())
            std::cout << "|Lista llena|" << std::endl;

        else
        {
            std::cout << "|Cuantos Datos Desea Agregar:";
            std::cin >> Agr;
            for (long i = 0; i < Agr; i++)
            {
                std::cout << "|" << i << "|:";
                std::cin >> Datos[i];
                Ultimo++;
            }
        }
    }
    long BúsquedaBinaria(long Elem)
    {
        Quicksort(0, Ultimo); // Ordenar los datos antes de realizar la búsqueda
        long i = 0, j = Ultimo, Med, Pos = -1;
        while (i <= j)
        {
            Med = (i + j) / 2;
            if (Datos[Med] == Elem)
            {
                Pos = Med; // Guardar la posición del elemento encontrado
                break;
            }
            if (Elem < Datos[Med])
            {
                j = Med - 1;
            }
            else
            {
                i = Med + 1;
            }
        }
        return Pos;
    }
    void Quicksort(long Izq, long Der)
    {
        if (Izq < Der)
        {
            long pivote = Datos[(Izq + Der) / 2];
            long i = Izq, j = Der;

            while (i <= j)
            {
                while (Datos[i] < pivote)
                    i++;
                while (Datos[j] > pivote)
                    j--;
                if (i <= j)
                {
                    long temp = Datos[i];
                    Datos[i] = Datos[j];
                    Datos[j] = temp;
                    i++;
                    j--;
                }
            }
            Quicksort(Izq, j);
            Quicksort(i, Der);
        }
    }
};

int main()
{
    Lista Lista;

    long opc = 0;
    do
    {
        system("pause");
        system("cls");
        std::cout << "|              Menu               |" << std::endl
                  << "|1.Vacía         |7.Imprime       |" << std::endl
                  << "|2.LLena         |8.Anula         |" << std::endl
                  << "|3.Inserta       |9.Agregar       |" << std::endl
                  << "|4.Elimina       |10.Busqueda     |" << std::endl
                  << "|5.Primero       |11.Ordenamiento |" << std::endl
                  << "|6.Ultimo        |12.Salir        |" << std::endl
                  << "|: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            if (Lista.Vacía() == true)
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                std::cout << "|La lista no esta vacia|" << std::endl;
            }
            break;
        case 2:
            if (Lista.LLena())
            {
                std::cout << "|La lista esta llena|" << std::endl;
            }
            else
            {
                std::cout << "|La lista no esta llena|" << std::endl;
            }
            break;
        case 3:
            long P1, E;
            std::cout << "|Ingrese la Posicion: ";
            std::cin >> P1;
            std::cout << "|Ingrese el Elemento: ";
            std::cin >> E;
            Lista.Insertar(P1, E);
            break;
        case 4:
            long P2;
            std::cout << "|Ingrese la Posicion: ";
            std::cin >> P2;
            Lista.Elimina(P2);
            break;
        case 5:
            std::cout << "|Primero:" << Lista.Primero() << "|" << std::endl;
            break;
        case 6:
            std::cout << "|Ultimo:" << Lista.ULtimo() << "|" << std::endl;
            break;
        case 7:
            Lista.Imprime();
            break;
        case 8:
            Lista.Anula();
            break;
        case 9:
            Lista.Agregar();
            break;
        case 10: // Búsqueda
            if (Lista.Vacía() == true)
                std::cout << "|La lista esta vacia|" << std::endl;
            else
            {
                long P3;
                std::cout << "|Ingrese Elemento:";
                std::cin >> P3;
                std::cout << "|" << Lista.BúsquedaBinaria(P3) << "|" << P3 << "|";
            }
            break;
        case 11: // Ordenamiento
            Lista.Imprime();
            Lista.Quicksort(0, Lista.ULtimo());
            std::cout << std::endl;
            Lista.Imprime();
            break;
        case 12:
            std::cout << "|Salio del sistema|";
            break;
        default:
            break;
        }
    } while (opc != 12);
}