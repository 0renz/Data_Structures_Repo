#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Desenvolva uma função para retornar a média aritmética dos valores armazenados na pilha.
Observação: Percorrer os elementos da pilha usando um laço de repetição, acessando o primeiro elemento pelo
ponteiro “topo” e os demais elementos com o ponteiro “prox”, semelhante a lógica usada para implementar a
função mostraP.
*/

#include "Pilhas/pilha-dinamica.hpp"

float mediaAritmetica(Pilha *P);

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

    mostraP(&P);
    float mediaArit = mediaAritmetica(&P);
    cout << "Média aritmética: " << mediaArit;
    destroiP(&P);
}

float mediaAritmetica(Pilha *P)
{
    float mediaArit;
    int cont = 0;
    NoPilha *no = P->topo;

    while (no != NULL)
    {
        mediaArit += no->dado;
        no = no->prox;
        cont++;
    }

    mediaArit /= cont;

    return mediaArit;
}
