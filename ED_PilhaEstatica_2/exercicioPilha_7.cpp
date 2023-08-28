#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Crie um programa para intercalar duas pilhas P1 e P2
*/

#include "pilhas/pilha.hpp"

void montaPilha(Pilha *p, int tam, int *cont);
void intercala (Pilha *p1, int tam1, Pilha *p2, int tam2);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p1, p2;
    int tam1, tam2;
    int cont = 1;

    cout << "Digite o tamanho da pilha 1: ";
    cin >> tam1;
    inicializaP(&p1, tam1);
    montaPilha(&p1, tam1, &cont);

    cout << "Digite o tamanho da pilha 2: ";
    cin >> tam2;
    inicializaP(&p2, tam2);
    montaPilha(&p2, tam2, &cont);

    cout << "PILHA 1" << endl;
    mostraP(&p1);
    cout << "PILHA 2" << endl;
    mostraP(&p2);

    intercala(&p1, tam1, &p2, tam2);

}

void montaPilha(Pilha *p, int tam, int *cont)
{
    int i = 0, valor;
    bool continuar = true;
    char escolha;

    do
    {
        system("cls");
        cout << "Informe os numeros da pilha " << *cont << ": ";

        cin >> valor;
        empilhaP(p, valor);
        i++;

        cout << "Deseja continuar? (S/N)" << endl;
        cin >> escolha;
        if (escolha == 'N' || (i == tam))
        {
            continuar = false;
            break;
        }
    }
    while (continuar);
    cont++;
}

void intercala (Pilha *p1, int tam1, Pilha *p2, int tam2)
{
    int tam3 = tam1 + tam2;
    Pilha p3;
    inicializaP(&p3, tam3);

    for (int i = 0; i < tam3; i++)
    {
        int valor = desempilhaP(p1);
        if (valor == 0)
            continue;
        empilhaP(&p3, valor);
        i++;

        if (valor == 0)
            continue;
        valor = desempilhaP(p2);
        empilhaP(&p3, valor);
    }
    mostraP(&p3);
}
