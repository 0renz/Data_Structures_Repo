#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "pilha/pilhaChar.hpp"

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
        cout << "\nEssa palavra � um pal�ndromo.";
    }
    else
        cout << "\nEssa palavra n�o � um pal�ndromo.";
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
