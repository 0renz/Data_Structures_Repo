#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, construa um programa para ordenar uma sequ�ncia de valores inteiros fornecidos pelo
usu�rio. Fa�a uso de duas pilhas: ORD e AUX. O objetivo � organizar a pilha ORD de modo que nenhum item seja
empilhado sobre outro menor, fazendo uso da pilha auxiliar AUX.
a) O usu�rio pode informar quantos valores inteiros ele desejar.
b) Ao final, o programa deve mostrar a pilha ORD.
*/

#include "Pilhas/pilha-dinamica.hpp"

void ordenar(Pilha *ORD);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int tam, valor;

    Pilha P;

    cout << "Tamanho da pilha: ";
    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        system("cls");
        cout << "Digite os valores da pilha: ";
        cin >> valor;
        empilhaP(&P, valor);
    }

    ordenar(&P);
}

void ordenar(Pilha *ORD)
{
    Pilha AUX;
    int valorORD, valorAUX;

    //la�o, inser��o, outro la�o

    while(!vaziaP(ORD))
    {
        valorORD = desempilhaP(ORD);

        while (!vaziaP(&AUX) && espiaP(&AUX) > valorORD)
        {
            valorAUX = desempilhaP(&AUX);
            empilhaP(ORD, valorAUX);
        }
        empilhaP(&AUX, valorORD);

    }

    while(!vaziaP(&AUX))
    {
        valorAUX = desempilhaP(&AUX);
        empilhaP(ORD, valorAUX);
    }

    mostraP(ORD);
}

