#include <iostream>

class Numero
{
private:
    long Num;

public:
    long getNum() const { return Num; }
    bool operator<(const Numero &otroNum) const { return Num < otroNum.Num; }
    bool operator>(const Numero &otroNum) const { return Num > otroNum.Num; }
    bool operator<=(const Numero &otroNum) const { return Num <= otroNum.Num; }
    bool operator>=(const Numero &otroNum) const { return Num >= otroNum.Num; }
    bool operator!=(const Numero &otroNum) const { return Num != otroNum.Num; }
    bool operator==(const Numero &otroNum) const { return Num == otroNum.Num; }

    friend std::ostream &operator<<(std::ostream &os, const Numero &x)
    {
        os << "|Numero: " << x.Num << "|";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Numero &x)
    {
        std::cout << "\n|Ingrese Numero: ";
        is >> x.Num;
        return is;
    }
};

template <class T>
class LSLCE;

template <class T>
class Node
{
private:
    T Elem;
    Node<T> *Sig;

public:
    Node() : Sig(nullptr){};
    friend class LSLCE<T>;
};

template <class T>
class LSLCE
{
private:
    Node<T> *Ancla;
    Node<T> *Ultimo;
    long Cantidad;
    std::string Descripción;

public:
    LSLCE() : Cantidad(0)
    {
        Ancla = new Node<T>;
        Ancla->Sig = nullptr;
        Ultimo = Ancla;
    }

    ~LSLCE()
    {
        Anula();
        delete Ancla;
    }

    bool Vacía() const { return Cantidad == 0; }

    void Inserta(Node<T> *Pos, T Elem)
    {
        Node<T> *NuevoNodo = new Node<T>;
        NuevoNodo->Elem = Elem;

        if (Pos == nullptr)
        {
            NuevoNodo->Sig = Ancla->Sig;
            Ancla->Sig = NuevoNodo;

            if (Ultimo == Ancla)
                Ultimo = NuevoNodo;
        }
        else
        {
            NuevoNodo->Sig = Pos->Sig;
            Pos->Sig = NuevoNodo;

            if (Pos == Ultimo)
                Ultimo = NuevoNodo;
        }

        Cantidad++;
    }

    void elimina(Node<T> *Pos)
    {
        if (Vacía() || Pos == nullptr)
            return;

        Node<T> *Aux = Ancla;

        while (Aux->Sig != Pos)
            Aux = Aux->Sig;

        Aux->Sig = Pos->Sig;

        if (Pos == Ultimo)
            Ultimo = Aux;

        delete Pos;
        Cantidad--;
    }

    Node<T> *Primero() const
    {
        if (Vacía())
            return nullptr;

        return Ancla->Sig;
    }

    Node<T> *ULtimo() const
    {
        if (Vacía())
            return nullptr;

        return Ultimo;
    }

    Node<T> *Anterior(Node<T> *Pos) const
    {
        if (Vacía() || Pos == nullptr || Pos == Ancla->Sig)
            return nullptr;

        Node<T> *Aux = Ancla;

        while (Aux->Sig != Pos)
            Aux = Aux->Sig;

        return Aux;
    }

    Node<T> *Siguiente(Node<T> *Pos) const
    {
        if (Vacía() || Pos == nullptr)
            return nullptr;
        return Pos->Sig;
    }

    Node<T> *Localiza(T Elem)
    {
        Node<T> *Aux = Ancla->Sig;

        while (Aux != nullptr && Aux->Elem != Elem)
        {
            Aux = Aux->Sig;
        }

        return Aux;
    }

    T Recupera(Node<T> *Pos)
    {
        if (Vacía() || Pos == nullptr)
        {
            std::cout << "|¡Error! Insuficiencia de datos|" << std::endl;
            return T();
        }
        else
        {
            return Pos->Elem;
        }
    }

    void Imprime()
    {
        long i = 0;
        Node<T> *Aux = Ancla->Sig;

        while (Aux != nullptr)
        {
            std::cout << "|" << i++ << " " << Aux->Elem << std::endl;
            Aux = Aux->Sig;
        }
    }

    void Anula()
    {
        Node<T> *Aux = Ancla->Sig;

        while (Aux != nullptr)
        {
            Node<T> *Temp = Aux;
            Aux = Aux->Sig;
            delete Temp;
        }

        Ancla->Sig = nullptr;
        Ultimo = Ancla;
        Cantidad = 0;
    }
};

int main()
{
    LSLCE<Numero> Lista;
    Numero N;
    long opc, O;

    do
    {
        system("pause");
        system("cls");
        std::cout << "|        Menu         |" << std::endl
                  << "|1.Vacia   |2.Insertar|" << std::endl
                  << "|3.Elimina |4.Anula   |" << std::endl
                  << "|5.Primero |6.Ultimo  |" << std::endl
                  << "|7.Localiza|8.Recupera|" << std::endl
                  << "|9.Imprimir|10.Salir  |" << std::endl
                  << "|:";
        std::cin >> opc;

        switch (opc)
        {
        case 1: // Vacía
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                std::cout << "|La lista no esta vacia|" << std::endl;
            }
            break;

        case 2: // Insertar
            O = 0;
            while (O != 2)
            {
                std::cin >> N;
                Lista.Inserta(Lista.ULtimo(), N);
                std::cout << "|Quiere Agregar otro Numero 1.si/2.no : ";
                std::cin >> O;
            }
            break;

        case 3: // Elimina
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                Numero Pos;
                std::cout << "|Ingrese la posicion del nodo a eliminar: ";
                std::cin >> Pos;
                Lista.elimina(Lista.Localiza(Pos));
            }
            break;

        case 4: // Anula
            std::cout << "|Lista anulada|" << std::endl;
            Lista.Anula();
            break;

        case 5: // Primero
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                std::cout << "|Primero: " << Lista.Recupera(Lista.Primero()) << "|";
            }
            break;

        case 6: // Ultimo
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                std::cout << "|Ultimo: " << Lista.Recupera(Lista.ULtimo()) << "|";
            }
            break;

        case 7: // Localiza
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                std::cout << "|Ingrese el numero a localizar: ";
                std::cin >> N;
                if (Lista.Localiza(N) != nullptr)
                {
                    std::cout << "|Numero encontrado en la posicion: " << Lista.Localiza(N) << "|";
                }
                else
                {
                    std::cout << "|Numero no encontrado en la lista|";
                }
            }
            break;

        case 8: // Recupera
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                Numero PosRecupera;
                std::cout << "|Ingrese la posición del elemento a recuperar: ";
                std::cin >> PosRecupera;
                std::cout << "|Elemento en la posición " << PosRecupera << ": " << Lista.Recupera(Lista.Localiza(PosRecupera)) << "|";
            }
            break;

        case 9: // Imprimir
            if (Lista.Vacía())
            {
                std::cout << "|La lista esta vacia|" << std::endl;
            }
            else
            {
                Lista.Imprime();
            }
            break;

        case 10:
            std::cout << "|Salio del sistema|" << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (opc != 10);
}
