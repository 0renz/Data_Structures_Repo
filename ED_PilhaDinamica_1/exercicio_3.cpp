#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, construa um programa para ordenar uma sequência de valores inteiros fornecidos pelo
usuário. Faça uso de duas pilhas: ORD e AUX. O objetivo é organizar a pilha ORD de modo que nenhum item seja
empilhado sobre outro menor, fazendo uso da pilha auxiliar AUX.
a) O usuário pode informar quantos valores inteiros ele desejar.
b) Ao final, o programa deve mostrar a pilha ORD.
*/

#include "Pilhas/pilha-dinamica.hpp"

void ordenar(Pilha *ORD);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    bool escolha = false;
    float num;
    char continuar;

    Pilha P;

    do
    {
        system("cls");
        cout << "Digite números: ";
        cin >> num;

        empilhaP(&P, num);
        cout << "Continuar? (S/N): ";
        cin >> continuar;

        if(continuar == 'n')
            escolha = true;

    }
    while(!escolha);

    ordenar(&P);
}

void ordenar(Pilha *ORD)
{
    Pilha AUX;
    int numAux, numAux2, numAux3;
    mostraP(ORD);

    //laço, inserção, outro laço

    while(!vaziaP(ORD))
    {

    }

    mostraP(ORD);
    mostraP(&AUX);
}

