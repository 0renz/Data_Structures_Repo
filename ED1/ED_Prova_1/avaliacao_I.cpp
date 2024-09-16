#include <iostream>
using namespace std;

#include "pilha.hpp"

int encontraMaior(Pilha *p);
int encontraMenor(Pilha *p);
void removeMaiorMenor(Pilha *p, int maior, int menor);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    int valor;
    int maior, menor;

    inicializaP(&p, 10);

    /*
    for (int i = 0; i < 5; i++)
    {
        valor = rand() % 5;
        empilhaP(&p, valor);
    }
    */
    empilhaP(&p, 8);
    empilhaP(&p, 9);
    empilhaP(&p, 7);
    empilhaP(&p, 9);
    empilhaP(&p, 5);
    empilhaP(&p, 3);
    empilhaP(&p, 6);
    empilhaP(&p, 3);
    empilhaP(&p, 4);

    mostraP(&p);

    maior = encontraMaior(&p);
    cout << "Maior: " << maior << endl;
    menor = encontraMenor(&p);
    cout << "Menor: " << menor << endl;
    removeMaiorMenor(&p, maior, menor);
    mostraP(&p);
}

int encontraMaior(Pilha *p)
{
    int maior = 0, valor;
    Pilha pAux;

    inicializaP(&pAux, 10);

    while(!vaziaP(p))
    {
        valor = desempilhaP(p);
        {
            if (valor > maior)
            {
                maior = valor;
            }
        }
        empilhaP(&pAux, valor);
    }
    while(!vaziaP(&pAux))
    {
        empilhaP(p, desempilhaP(&pAux));
    }

    destroiP(&pAux);
    return maior;
}

int encontraMenor(Pilha *p)
{
    int menor = -1, valor;
    Pilha pAux;

    inicializaP(&pAux, 10);

    while(!vaziaP(p))
    {
        valor = desempilhaP(p);
        {
            if(menor < 0)
            {
                menor = valor;
            }
            if (valor < menor)
            {
                menor = valor;
            }
        }
        empilhaP(&pAux, valor);
    }
    while(!vaziaP(&pAux))
    {
        empilhaP(p, desempilhaP(&pAux));
    }

    destroiP(&pAux);
    return menor;
}

void removeMaiorMenor(Pilha *p, int maior, int menor)
{
    Pilha pAux;
    int valor;
    inicializaP(&pAux, 10);

    bool flagMaior = false;
    bool flagMenor = false;

    while(!vaziaP(p))
    {
        valor = desempilhaP(p);

        if (valor == maior && !flagMaior)
        {
            flagMaior = true;
            continue;
        }
        else if (valor == menor && !flagMenor)
        {
            flagMenor = true;
            continue;
        }
        else
        {
            empilhaP(&pAux, valor);
        }
    }
    while(!vaziaP(&pAux))
    {
        empilhaP(p, desempilhaP(&pAux));
    }
}
