#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Crie uma função para copiar os dados pilha P1 para P2. Esta função deve preservar os dados armazenados em P1,
ou seja, após a execução da função, P1 e P2 devem possuir os mesmos elementos e na mesma ordem
*/

#include "Pilhas/pilha-dinamica.hpp"

void copiaPilha(Pilha *p, int tam);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;


    int tam, valor;
    cout << "Tamanho da pilha: ";
    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        system("cls");
        cout << "Digite os dados da pilha [" << i+1 << "]";
        cout << endl;
        cin >> valor;
        empilhaP(&p, valor);
    }
    copiaPilha(&p, tam);
}

void copiaPilha(Pilha *p, int tam)
{
    Pilha p2;
    Pilha pAux;
    int valor;
    int i = 0;



    while(!vaziaP(p))
    {
        valor = desempilhaP(p);
        empilhaP(&pAux, valor);
    }

    while(i != tam)
    {
        valor = desempilhaP(&pAux);
        empilhaP(p, valor);
        empilhaP(&p2, valor);
        i++;
    }

    cout << "PILHA 1" << endl;
    mostraP(p);
    cout << "PILHA 2" << endl;
    mostraP(&p2);
}


