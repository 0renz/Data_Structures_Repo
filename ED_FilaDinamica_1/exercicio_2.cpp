#include <iostream>
using namespace std;

/*
Considerando duas filas dinâmicas, implemente uma função para concatenar duas filas, as quais devem ser
recebidas por parâmetro.
*/

#include "filas/fila-dinamica.hpp"

void concatenaF(Fila *f, Fila *g, Fila *fgConcatenada);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila f, g, fgConcatenada;

    enfileiraF(&f, 1);
    enfileiraF(&f, 2);
    enfileiraF(&f, 3);

    enfileiraF(&g, 4);
    enfileiraF(&g, 5);
    enfileiraF(&g, 6);

    cout << "Fila f: ";
    mostraF(&f);
    cout << "Fila g: ";
    mostraF(&g);

    concatenaF(&f, &g, &fgConcatenada);
    cout << "Fila concatenada: ";
    mostraF(&fgConcatenada);
}

void concatenaF(Fila *f, Fila *g, Fila *fgConcatenada)
{
    while (!vaziaF(f))
        enfileiraF(fgConcatenada, desenfileiraF(f));
    while (!vaziaF(g))
        enfileiraF(fgConcatenada, desenfileiraF(g));
}

