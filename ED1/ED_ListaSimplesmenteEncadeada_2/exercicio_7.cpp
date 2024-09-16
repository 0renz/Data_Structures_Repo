#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Dados duas listas L1 e L2, crie uma função para computar a lista L3 que é a intersecção de L1 e L2.
Exemplo:
L1: 2 5 3 9 9 8 7 6 2 1
L2: 20 30 100 6 1 5 9
L3: 5 9 6 1
*/

void intersec(No<int>** L1, No<int>** L2);
bool encontraL2(No<int>*** L2, int dado);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L1; // cria o primeiro nó
    inicializaL(&L1);

    No<int> *L2; // cria o primeiro nó
    inicializaL(&L2);


    insereInicioL(&L1, 4);
    insereInicioL(&L1, 7);
    insereInicioL(&L1, 3);
    insereInicioL(&L1, 2);
    insereInicioL(&L1, 1);
    insereInicioL(&L1, 6);
    insereInicioL(&L1, 13);

    insereInicioL(&L2, 5);
    insereInicioL(&L2, 13);
    insereInicioL(&L2, 4);
    insereInicioL(&L2, 8);
    insereInicioL(&L2, 1);
    insereInicioL(&L2, 7);
    insereInicioL(&L2, 2);

    mostraL(&L1);
    mostraL(&L2);
    intersec(&L1, &L2);

    return EXIT_SUCCESS;
}

void intersec(No<int>** L1, No<int>** L2)
{
    No<int> *n1 = *L1;
    No<int> *L3;
    inicializaL(&L3);

    for (int i = 0; i < totalL(L1); i++)
    {
        if (encontraL2(&L2, n1->dado))
        {
            insereInicioL(&L3, n1->dado);
        }
        n1 = n1->prox;
    }
    mostraL(&L3);
}

bool encontraL2(No<int>*** L2, int dado)
{
    No<int> *n2 = **L2;

    for (int i = 0; i < totalL(*L2); i++)
    {
        if(n2->dado == dado)
            return true;

        n2 = n2->prox;
    }
    return false;
}
