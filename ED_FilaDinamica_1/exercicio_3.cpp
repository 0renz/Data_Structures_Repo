#include <iostream>
using namespace std;

/*
Implemente uma fun��o para dividir uma fila din�mica de valoresinteiros. A fun��o deve receber como par�metro
uma fila F1 com os valores inteiros, uma fila vazia F2 e um valor inteiro N. A fun��o deve dividir a fila F1 em duas,
de tal forma que F2 comece no primeiro n� (elemento) logo ap�s a primeira ocorr�ncia de N na fila original.
*/

#include "filas/fila-dinamica.hpp"

void separaF(int separador, Fila *f, Fila *g);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Fila f, g;
    int separador;

    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    enfileiraF(&f, 3);
    enfileiraF(&f, 4);
    enfileiraF(&f, 5);
    enfileiraF(&f, 6);

    cout << "Fila f: ";
    mostraF(&f);
    cout << "Fila g: ";
    mostraF(&g);

    cout << "\nDigite o n�mero separador: ";
    cin >> separador;

    separaF(separador, &f, &g);

    cout << "\nFila f: ";
    mostraF(&f);
    cout << "Fila g: ";
    mostraF(&g);

}

void separaF(int separador, Fila *f, Fila *g)
{
    Fila fAux;
    int valor;

    while (!vaziaF(f))
    {
        valor = desenfileiraF(f);
        if (valor == separador)
        {
            enfileiraF(&fAux, valor);
            while (!vaziaF(f))
            {
                enfileiraF(g, desenfileiraF(f));
            }
            break;
        }
        enfileiraF(&fAux, valor);
    }

    while (!vaziaF(&fAux))
        enfileiraF(f, desenfileiraF(&fAux));
}


