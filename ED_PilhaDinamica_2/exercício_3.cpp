#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Crie uma função para remover todos os elementos ímpares de uma pilha P, mantendo a mesma ordem relativa
dos elementos remanescentes. Exemplo
*/

#include "Pilhas/pilha-dinamica.hpp"

void removeImpares(Pilha *p);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int escolha = -1;

    Pilha p;

    for(int i = 0; i < 10; i++)
        empilhaP(&p, i);

    mostraP(&p);
    removeImpares(&p);
    mostraP(&p);
}

void removeImpares(Pilha *p)
{
    Pilha pAux;
    int num;

    while(!vaziaP(p))
    {
        num = desempilhaP(p);
        if (num % 2 == 0)
        {
            empilhaP(&pAux, num);
        }
    }

    while(!vaziaP(&pAux))
    {
        num = desempilhaP(&pAux);
        empilhaP(p, num);
    }
}

