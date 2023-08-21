#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "pilha/pilhaChar.hpp"

/*
Faça um programa que leia uma string e verifica se o texto é um palíndromo, ou seja, se a string é escrita da 
mesma maneira de frente para trás e de trás para frente. Ignore espaços e pontos.

Observações:
- Modificar a estrutura da Pilha para armazenas dados do tipo char.
- Use uma pilha para realizar a verificação do palíndromo, não é permitido o uso de vetores auxiliares.
*/

bool palindromo(Pilha *p, Pilha *pAux, int n);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    Pilha pAux;
    string palavra;

    cout << "Digite uma palavra: ";
    getline(cin, palavra);

    int n = palavra.length();

    char palavraChar[n + 1];

    strcpy(palavraChar, palavra.c_str());

    inicializaP(&p, n);
    for (int i = 0; i < n; i++)
    {
        empilhaP(&p, palavraChar[i]);
    }
    mostraP(&p);

    inicializaP(&pAux, n);
    for (int i = n-1; i >= 0; i--)
    {
        empilhaP(&pAux, palavraChar[i]);
    }
    mostraP(&pAux);


    if (palindromo(&p, &pAux, n))
    {
        cout << "\nEssa palavra é um palíndromo.";
    }
    else
        cout << "\nEssa palavra não é um palíndromo.";
}

bool palindromo(Pilha *p, Pilha *pAux, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (desempilhaP(p) != desempilhaP(pAux))
        {
            return false;
        }
        return true;
    }
}
