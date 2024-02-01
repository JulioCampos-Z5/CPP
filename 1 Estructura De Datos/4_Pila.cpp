#include <iostream>
#include <string>
#define max 2

class Pila
{
private:
    std::string Datos[max];
    int tope;

public:
    void Inicializa() { tope = -1; }
    bool Vacía()
    {
        if (tope == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool LLena()
    {
        if (tope == max - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push(std::string x)
    {
        if (LLena())
        {
            std::cout << "Desbordamiento de datos en la pila" << std::endl;
            return;
        }
        Datos[++tope] = x;
    }
    void Pop()
    {
        if (Vacía())
        {
            std::cout << "La pila ya esta vacia" << std::endl;
            return;
        }
        tope--;
    }
    std::string Top()
    {
        if (Vacía())
        {
            std::cout << "La pila esta vacia" << std::endl;
            return "";
        }
        return Datos[tope];
    }
};

int Precedencia(char operador)
{
    if (operador == '+' || operador == '-')
    {
        return 1;
    }
    else if (operador == '*' || operador == '/')
    {
        return 2;
    }
    else if (operador == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

std::string InfixToPostfix(std::string expresionInfix)
{
    Pila pila;
    pila.Inicializa();
    std::string expresionPostfix = "";

    for (int i = 0; i < expresionInfix.length(); i++)
    {
        std::string caracter = expresionInfix.substr(i, 1);

        if (isalnum(caracter[0])) // Si el caracter es un número o letra
        {
            expresionPostfix += caracter;
        }
        else if (caracter == "(") // Si el caracter es un paréntesis izquierdo
        {
            pila.Push(caracter);
        }
        else if (caracter == ")") // Si el caracter es un paréntesis derecho
        {
            while (!pila.Vacía() && pila.Top() != "(")
            {
                expresionPostfix += pila.Top();
                pila.Pop();
            }
            pila.Pop(); // Quitamos el paréntesis izquierdo de la pila
        }
        else // Si el caracter es un operador
        {
            while (!pila.Vacía() && Precedencia(caracter[0]) <= Precedencia(pila.Top()[0]))
            {
                expresionPostfix += pila.Top();
                pila.Pop();
            }
            pila.Push(caracter);
        }
    }

    while (!pila.Vacía())
    {
        expresionPostfix += pila.Top();
        pila.Pop();
    }

    return expresionPostfix;
}

int main()
{
    std::string expresionInfix;
    std::cout << "Introduce una expresion infija: ";
    std::getline(std::cin, expresionInfix);

    std::string expresionPostfix = InfixToPostfix(expresionInfix);

    std::cout << "La expresion en notacion postfija es: " << expresionPostfix << std::endl;

    return 0;
}