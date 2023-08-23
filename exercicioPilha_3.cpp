#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Desenvolva as seguintes funções:

• Função para testar se duas pilhas P1 e P2 são iguais.
Observação: Duas pilhas são iguais se elas possuem os mesmos elementos e na mesma ordem.
• Função para retornar o número de elementos da pilha que possuem valor par.
Observação: Use uma pilha auxiliar e as operações de empilha/desempilha para implementar as funções, ou
seja, não é permitido acessar o vetor da pilha diretamente (pilha->dados[i]).
*/

#include "pilhas/pilha.hpp"

bool iguais (Pilha *p1, Pilha *p2);
int pares (Pilha *p);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p1, p2;
    int n;

    inicializaP(&p1, 5);
    for(int i = 0; i < 5; i++)
    {
        n = rand() % 15;
        empilhaP(&p1, n);
    }
    mostraP(&p1);

    inicializaP(&p2, 5);
    cout << "Digite os números da p2: ";
    for(int i = 0; i < 5; i++)
    {
        cin >> n;
        empilhaP(&p2, n);
    }
    mostraP(&p2);

    if (iguais(&p1, &p2))
    {
        cout << "As pilhas são iguais";
    }
    else
        cout << "As pilhas não são iguais";

    cout << "\nQuantidade de pares da pilha 1: " << pares(&p1) << endl;
    cout << "Quantidade de pares da pilha 2: " << pares(&p2) << endl;

}

bool iguais (Pilha *p1, Pilha *p2)
{
    Pilha pAux, pAux2;
    int v1, v2;
    inicializaP(&pAux, 5);
    inicializaP(&pAux2, 5);

    bool iguais = true;

    while(!vaziaP(p1) && !vaziaP(p2))
    {
        v1 = desempilhaP(p1);
        v2 = desempilhaP(p2);

        empilhaP(&pAux, v1);
        empilhaP(&pAux2, v2);

        if (v1 != v2)
        {
            iguais = false;
            break;
        }
    }

    while(!cheiaP(p1) && !cheiaP(p2))
    {
        v1 = desempilhaP(&pAux);
        v2 = desempilhaP(&pAux2);

        empilhaP(p1, v1);
        empilhaP(p2, v2);
    }

    return iguais;
}

int pares (Pilha *p)
{
    Pilha pAux;
    inicializaP(&pAux, 5);
    int contPar = 0;
    int v;

    while(!vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&pAux, v);

        if (v % 2 == 0)
            contPar++;
    }

    while(!cheiaP(p))
    {
        v = desempilhaP(&pAux);
        empilhaP(p, v);
    }

    return contPar;

}



