#include <iostream>

using namespace std;

class Socio
{
private:
    long NumSocio;
    std::string NomSocio;
    std::string Domicilio;
    long AñoIngreso;

public:
    long GetNumSocio() { return NumSocio; }
    std::string GetNomSocio() { return NomSocio; }
    std::string GetDomicilio() { return Domicilio; }
    long GetAñoIngreso() { return AñoIngreso; }

    bool operator==(const Socio &otrosocio) const { return NomSocio == otrosocio.NomSocio && Domicilio == otrosocio.Domicilio; }
    bool operator!=(const Socio &otrosocio) const { return NomSocio != otrosocio.NomSocio && Domicilio != otrosocio.Domicilio; }
    bool operator<(const Socio &otrosocio) const { return NumSocio < otrosocio.NumSocio; }
    bool operator>(const Socio &otrosocio) const { return NumSocio > otrosocio.NumSocio; }
    bool operator<=(const Socio &otrosocio) const { return NumSocio <= otrosocio.NumSocio; }
    bool operator>=(const Socio &otrosocio) const { return NumSocio >= otrosocio.NumSocio; }
    friend std::ostream &operator<<(std::ostream &os, Socio &x)
    {
        os << std::endl;
        os << "|Numero de Socio: " << x.NumSocio;
        os << "|Nombre: " << x.NomSocio;
        os << "|Domicilio: " << x.Domicilio;
        os << "|Año: " << x.AñoIngreso << "|" << std::endl;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Socio &x)
    {
        std::cout << "\n|Numero Socio: ";
        is >> x.NumSocio;
        std::cout << "\n|Nombre: ";
        is >> x.NomSocio;
        std::cout << "\n|Domicilio: ";
        is >> x.Domicilio;
        std::cout << "\n|Año de Ingreso: ";
        is >> x.AñoIngreso;
        return is;
    }
};

template <class T>
class LDLLSE;

template <class T>
class Nodo
{
private:
    T Datos;
    Nodo<T> *Sig;
    Nodo<T> *Ant;

public:
    Nodo() : Sig(nullptr), Ant(nullptr) {}
    friend class LDLLSE<T>;
};

template <class T>
class LDLLSE
{
private:
    Nodo<T> *Ancla;

public:
    LDLLSE() : Ancla(nullptr) {}

    bool Vacía() const { return Ancla == nullptr; }

    Nodo<T> *Primero() const { return Ancla; }

    Nodo<T> *Ultimo() const
    {
        if (Vacía())
        {
            return nullptr;
        }
        else
        {
            Nodo<T> *Aux = Ancla;
            while (Aux->Sig != nullptr)
            {
                Aux = Aux->Sig;
            }
            return Aux;
        }
    }

    Nodo<T> *Anterior(Nodo<T> *Pos) const
    {
        if (Vacía() || Pos == nullptr)
        {
            return nullptr;
        }
        else
        {
            return Pos->Ant;
        }
    }

    Nodo<T> *Siguiente(Nodo<T> *Pos) const
    {
        if (Vacía())
        {
            return nullptr;
        }
        else
        {
            return Pos->Sig;
        }
    }

    Nodo<T> *Localiza(T Elem) const
    {
        if (Vacía())
        {
            return nullptr;
        }
        else
        {
            Nodo<T> *Aux = Ancla;
            while (Aux != nullptr && Aux->Datos != Elem)
            {
                Aux = Aux->Sig;
            }
            return Aux;
        }
    }

    T Recupera(Nodo<T> *Pos) const
    {
        if (Vacía() || Pos == nullptr)
        {
            std::cout << "|Dato no recuperado|";
            return T();
        }
        else
        {
            return Pos->Datos;
        }
    }

    void Imprime() const
    {
        if (!Vacía())
        {
            Nodo<T> *Aux = Ancla;
            while (Aux != nullptr)
            {
                std::cout << Aux->Datos << std::endl;
                Aux = Aux->Sig;
            }
        }
    }

    void Anula()
    {
        Nodo<T> *Aux;
        while (Ancla != nullptr)
        {
            Aux = Ancla;
            Ancla = Aux->Sig;
            delete Aux;
        }
    }

    void Insertar(Nodo<T> *Pos, T Elem)
    {
        Nodo<T> *Aux = new Nodo<T>;
        Aux->Datos = Elem;
        if (Pos == nullptr)
        {
            Aux->Ant = nullptr;
            Aux->Sig = Ancla;
            if (Ancla != nullptr)
            {
                Ancla->Ant = Aux;
            }
            Ancla = Aux;
        }
        else
        {
            Aux->Ant = Pos;
            Aux->Sig = Pos->Sig;
            if (Pos->Sig != nullptr)
            {
                Pos->Sig->Ant = Aux;
            }
            Pos->Sig = Aux;
        }
    }

    bool Elimina(Nodo<T> *Pos)
    {
        if (Vacía() || Pos == nullptr)
        {
            return false;
        }
        if (Pos == Ancla)
        {
            Ancla = Ancla->Sig;
        }
        else
        {
            Anterior(Pos)->Sig = Pos->Sig;
        }
        delete Pos;
        return true;
    }

    Nodo<Socio> *Buscar(int O, std::string bus)
    {
        std::string nomSocio, domicilio;
        if (O == 1)
        {
            nomSocio = bus;
        }
        if (O == 2)
        {
            domicilio = bus;
        }
        Nodo<Socio> *aux = Ancla;
        while (aux != nullptr)
        {
            if (aux->Datos.GetNomSocio() == nomSocio || aux->Datos.GetDomicilio() == domicilio)
            {
                return aux;
            }
            std::cout << aux->Datos;
            aux = aux->Sig;
        }
        return nullptr;
    }
    long Longitud() const
    {
        long contador = 0;
        Nodo<T> *aux = Ancla;
        while (aux != nullptr)
        {
            contador++;
            aux = aux->Sig;
        }
        return contador;
    }

    void Merge(Nodo<T> *ancla, Nodo<T> *izq, Nodo<T> *med, Nodo<T> *der)
    {
        LDLLSE<T> temp;
        Nodo<T> *i = izq;
        Nodo<T> *j = med->Sig;

        while (i != med->Sig && j != der->Sig)
        {
            if (i->Datos < j->Datos)
            {
                temp.Insertar(temp.Ultimo(), i->Datos);
                i = i->Sig;
            }
            else
            {
                temp.Insertar(temp.Ultimo(), j->Datos);
                j = j->Sig;
            }
        }

        while (i != med->Sig)
        {
            temp.Insertar(temp.Ultimo(), i->Datos);
            i = i->Sig;
        }

        while (j != der->Sig)
        {
            temp.Insertar(temp.Ultimo(), j->Datos);
            j = j->Sig;
        }

        Nodo<T> *nodoTemp = temp.Primero();
        Nodo<T> *nodoLista = izq;
        while (nodoTemp != nullptr)
        {
            nodoLista->Datos = nodoTemp->Datos;
            nodoTemp = nodoTemp->Sig;
            nodoLista = nodoLista->Sig;
        }
    }
    Nodo<T> *FindMiddle(Nodo<T> *izq, Nodo<T> *der)
    {
        Nodo<T> *nodoRapido = izq;
        Nodo<T> *nodoLento = izq;

        while (nodoRapido != der && nodoRapido->Sig != der)
        {
            nodoRapido = nodoRapido->Sig->Sig;
            nodoLento = nodoLento->Sig;
        }

        return nodoLento;
    }
    void MergeSort(Nodo<T> *ancla, Nodo<T> *izq, Nodo<T> *der)
    {
        if (izq != der)
        {
            Nodo<T> *med = FindMiddle(izq, der);
            MergeSort(ancla, izq, med);
            MergeSort(ancla, med->Sig, der);
            Merge(ancla, izq, med, der);
        }
    }
};

int main()
{
    LDLLSE<Socio> Lista;
    Socio S;

    long O = 1;
    long B;
    std::string Bus;
    long opc;
    do
    {

        std::cout << std::endl;
        system("pause");
        system("cls");

        std::cout << "|     Menu    |" << std::endl
                  << "|1.Insertar   |" << std::endl
                  << "|2.Reporte    |" << std::endl
                  << "|3.Busqueda   |" << std::endl
                  << "|4.Dar de baja|" << std::endl
                  << "|5.Ordenar    |" << std::endl
                  << "|6.Salir      |" << std::endl
                  << "|: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            while (O != 2)
            {
                std::cin >> S;
                Lista.Insertar(Lista.Ultimo(), S);
                std::cout << "|Quiere Agregar otro Socio 1.si/2.no : ";
                std::cin >> O;
            };
            break;
        case 2:
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|";
            }
            else
            {
                Lista.Imprime();
            }
            break;
        case 3:
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|";
            }
            else
            {
                std::cout << "|1.Nombre/2.domicilio:";
                std::cin >> B;
                std::cout << "|Ingrese nombre o domicilio: ";
                std::cin >> Bus;
                //std::cout << Lista.Localiza(Buscar(B, Bus));
            }
            break;
        case 4:
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|";
            }
            else
            {
                std::cout << "|1.Elimina/2.Anula : ";
                std::cin >> B;
                if (B == 1)
                {
                    std::cout << "|Ingrese nombre o domicilio: ";
                    std::cin >> Bus;
                    std::cout << "|1.Nombre/2.domicilio:";
                    std::cin >> B;
                    Lista.Elimina(Lista.Buscar(B, Bus));
                }
                if (B == 2)
                {
                    Lista.Anula();
                }
            }
            break;
        case 5:
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|";
            }
            else
            {
                // ordenamiento
                Nodo<Socio> *primerSocio = Lista.Primero();
                Nodo<Socio> *ultimoSocio = Lista.Ultimo();
                Lista.MergeSort(Lista.Primero(), primerSocio, ultimoSocio);
                std::cout << "|Lista ordenada por número de socio|" << std::endl;
                Lista.Imprime();
            }
            break;
        case 6:
            std::cout << "|Salio del sistema|";
            break;
        }
    } while (opc != 6);
    return 0;
}