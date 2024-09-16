#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Crie uma função parar inserir em uma lista encadeada com base em uma posição/índice.
bool inserePosicao(No** lista, int pos, int valor);
L1: 2 5 3 9 9 8 7 6 2 1
inserePosicao(L1, 0, 100); //returna true
L1: 100 2 5 3 9 9 8 7 6 2 1
*/

bool inserePosicao(No<int>** L, int pos, int valor);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro nó
    inicializaL(&L);

    inserePosicao(&L, 0, 9);
    inserePosicao(&L, 0, 99);
    inserePosicao(&L, 0, 999);
    inserePosicao(&L, 2, 300);
    inserePosicao(&L, 13, 3000);

    mostraL(&L);

    return EXIT_SUCCESS;
}

bool inserePosicao(No<int>** L, int pos, int valor)
{
    No<int> *n = *L;
    No<int> *novo = new No<int>();

    No<int> *aux = new No<int>();

    novo->dado = valor;

    if(pos < 0 || pos > totalL(L))
        return false;

    if(n == NULL)
    {
        novo->prox = *L;
        *L = novo;
        return true;
    }

    for (int i = 0; i < totalL(L); i++)
    {
        if (pos == 0)
        {
            novo->prox = *L;
            *L = novo;
            return true;
        }
        if (i == pos-1)
        {
            *aux = *n;
            n->prox = novo;
            novo->prox = aux->prox;
            return true;
        }
        n = n->prox;
    }
}
