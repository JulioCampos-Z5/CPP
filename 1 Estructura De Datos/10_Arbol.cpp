

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
class ArbolB;

template <class T>
class Nodo
{
public:
    T Datos;
    Nodo<T> *Izq;
    Nodo<T> *Der;

public:
    Nodo() : Izq(nullptr), Der(nullptr) {}
    friend class ArbolB<T>;
};

template <class T>
class ArbolB
{
private:
    Nodo<T> *Arbol;

public:
    ArbolB() : Arbol(nullptr) {}

    bool vacia() { return (Arbol == nullptr); }

    T recupera(Nodo<T> *Pos)
    {
        if (Arbol == nullptr || Pos == nullptr)
        {
            cout << "|Insuficiencia de datos|" << endl;
        }
        else
        {
            return Pos->Datos;
        }
    }

    void inserta(Nodo<T> *&nodo, T Elem)
    {
        if (nodo == nullptr)
        {
            Nodo<T> *Aux = new Nodo<T>;
            Aux->Datos = Elem;
            nodo = Aux;
        }
        else
        {
            if (Elem < nodo->Datos)
            {
                inserta(nodo->Izq, Elem);
            }
            else
            {
                inserta(nodo->Der, Elem);
            }
        }
    }

    void inserta(T Elem)
    {
        inserta(Arbol, Elem);
    }

    Nodo<T> *localiza(T Elem, Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return nullptr;
        }
        else
        {
            if (Elem == nodo->Datos)
            {
                return nodo;
            }
            else
            {
                if (Elem < nodo->Datos)
                {
                    return localiza(Elem, nodo->Izq);
                }
                else
                {
                    return localiza(Elem, nodo->Der);
                }
            }
        }
    }

    Nodo<T> *localiza(T Elem)
    {
        return localiza(Elem, Arbol);
    }

    Nodo<T> *menor(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return nullptr;
        }
        else
        {
            if (nodo->Izq == nullptr)
            {
                return nodo;
            }
            else
            {
                return menor(nodo->Izq);
            }
        }
    }

    Nodo<T> *menor()
    {
        return menor(Arbol);
    }

    Nodo<T> *mayor(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return nullptr;
        }
        else
        {
            if (nodo->Der == nullptr)
            {
                return nodo;
            }
            else
            {
                return mayor(nodo->Der);
            }
        }
    }

    Nodo<T> *mayor()
    {
        return mayor(Arbol);
    }

    bool es_hoja(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return false;
        }
        return (nodo->Izq == nullptr && nodo->Der == nullptr);
    }

    bool es_hoja()
    {
        return es_hoja(Arbol);
    }

    void recorrido_preorder(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }

        cout << nodo->Datos << " ";
        recorrido_preorder(nodo->Izq);
        recorrido_preorder(nodo->Der);
    }

    void recorrido_preorder()
    {
        recorrido_preorder(Arbol);
    }

    void recorrido_inorden(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }
        recorrido_inorden(nodo->Izq);
        cout << nodo->Datos << " ";
        recorrido_inorden(nodo->Der);
    }

    void recorrido_inorden()
    {
        recorrido_inorden(Arbol);
    }

    void recorrido_postorden(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }
        recorrido_postorden(nodo->Izq);
        recorrido_postorden(nodo->Der);
        cout << nodo->Datos << " ";
    }

    void recorrido_postorden()
    {
        recorrido_postorden(Arbol);
    }

    void elimina(Nodo<T> *&nodo, Nodo<T> *Pos)
    {
        if (nodo == nullptr || Pos == nullptr)
        {
            cout << "|Datos no encontrados|" << endl;
        }
        if (es_hoja(nodo))
        {
            nodo = nullptr;
        }
        else
        {
            if (nodo->Izq != nullptr)
            {
                Pos = mayor(nodo->Izq);
            }
            else
            {
                Pos = menor(nodo->Der);
            }
            nodo->Datos = Pos->Datos;
            elimina(nodo, Pos);
        }
    }

    void elimina(Nodo<T> *Pos)
    {
        elimina(Arbol, Pos);
    }

    long altura(Nodo<T> *nodo)
    {
        long alt_izq, alt_der;
        if (nodo == nullptr)
        {
            return 0;
        }
        else
        {
            alt_izq = altura(nodo->Izq);
            alt_der = altura(nodo->Der);
            if (alt_izq > alt_der)
            {
                return alt_izq + 1;
            }
            else
            {
                return alt_der + 1;
            }
        }
    }

    long altura()
    {
        return altura(Arbol);
    }

    long fact_eq(Nodo<T> *nodo)
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        else
        {
            return altura(nodo->Der) - altura(nodo->Izq);
        }
    }

    long fact_eq()
    {
        return fact_eq(Arbol);
    }
};

int main()
{
    ArbolB<Socio> arbol;
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
                  << "|2.Mostrar    |" << std::endl
                  << "|3.Elimina   |" << std::endl
                  << "|: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            while (O != 2)
            {
                std::cin >> S;
                arbol.inserta(S);
                std::cout << "|Quiere Agregar otro Socio 1.si/2.no : ";
                std::cin >> O;
            };
            break;
        case 2:
            if (arbol.vacia())
            {
                std::cout << "|La Arbol esta vacia|";
            }
            else
            {
                arbol.recorrido_preorder()
            }
            break;
        case 3:
            if (arbol.vacia())
            {
                std::cout << "|La Arbol esta vacia|";
            }
            else
            {
                arbol.elimina(arbol.localiza());
            }
            break;
        case 6:
            std::cout << "|Salio del sistema|";
            break;
        }
    } while (opc != 6);
    return 0;
}