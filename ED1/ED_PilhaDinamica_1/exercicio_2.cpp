#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, implemente um programa para inverter a ordem das letras nas palavras em uma frase. Por
exemplo, na frase “teste de pilha”, o programa deverá exibir “etset ed ahlip”.
*/

#include "Pilhas/pilha-dinamica-ex02.hpp"

void inverte(string frase, Pilha *P);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha P;

    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    inverte(frase, &P);
}

void inverte(string frase, Pilha *P)
{
    frase += ' ';
    for(int i = 0; i < frase.length(); i++)
    {
        if (frase[i] != ' ')
        {
            empilhaP(P, frase[i]);
        }
        else
        {
            while (!vaziaP(P))
            {
                char c = desempilhaP(P);
                cout << c;
            }
            cout << ' ';
        }
    }
}
