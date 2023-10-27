#include <iostream>
using namespace std;

#include "listas/lista.hpp"

//Crie uma função recursiva para imprimir uma lista encadeada na ordem inversa.

void imprimeInverso(No<char> *L);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<char> *L;
    inicializaL(&L);

    insereFinalL(&L, 'A');
    insereFinalL(&L, 'E');
    insereFinalL(&L, 'I');
    insereFinalL(&L, 'O');
    insereFinalL(&L, 'U');

    mostraL(&L);
    imprimeInverso(L);

    return EXIT_SUCCESS;
}

void imprimeInverso(No<char> *L)
{
    if((L) == NULL)
        return;

    imprimeInverso(L->prox);
    cout << L->dado << " ";
}
