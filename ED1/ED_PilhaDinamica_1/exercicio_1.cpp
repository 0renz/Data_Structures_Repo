#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Desenvolva uma fun��o para retornar a m�dia aritm�tica dos valores armazenados na pilha.
Observa��o: Percorrer os elementos da pilha usando um la�o de repeti��o, acessando o primeiro elemento pelo
ponteiro �topo� e os demais elementos com o ponteiro �prox�, semelhante a l�gica usada para implementar a
fun��o mostraP.
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
        cout << "Digite n�meros: ";
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
    cout << "M�dia aritm�tica: " << mediaArit;
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
