#include <iostream>
using namespace std;

#include "pilha.hpp"

void repetidos(Pilha *p, Pilha *r, int tamPilha);
int busca(Pilha **p, int valor, int tamPilha);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    Pilha r;
    int valor;
    int tamPilha = 15;
    inicializaP(&p, tamPilha);
    inicializaP(&r, tamPilha);

    empilhaP(&p, 8);
    empilhaP(&p, 9);
    empilhaP(&p, 7);
    empilhaP(&p, 5);
    empilhaP(&p, 7);
    empilhaP(&p, 6);
    empilhaP(&p, 7);
    empilhaP(&p, 0);
    empilhaP(&p, 4);
    empilhaP(&p, 8);
    empilhaP(&p, 3);
    empilhaP(&p, 4);
    empilhaP(&p, 1);

    mostraP(&p);
    mostraP(&r);
    cout << endl << endl;
    repetidos(&p, &r, tamPilha);
}

void repetidos(Pilha *p, Pilha *r, int tamPilha)
{
    int valor;

    Pilha pAux;
    inicializaP(&pAux, tamPilha);

        while(!vaziaP(p))
        {
            valor = desempilhaP(p);
            if (busca(&p, valor, tamPilha) >= 1)
            {
                if(busca(&r, valor, tamPilha) == 0)
                {
                    empilhaP(r, valor);
                }
            }
            empilhaP(&pAux, valor);
        }
        while(!vaziaP(&pAux))
        {
            empilhaP(p, desempilhaP(&pAux));
        }

    cout << "PILHA P" << endl;
    mostraP(p);
    cout << "PILHA R" << endl;
    mostraP(r);
}

int busca(Pilha **p, int valor, int tamPilha)
{
    Pilha pAux;
    int valorPilha;
    int cont = 0;

    inicializaP(&pAux, 13);

    while(!vaziaP(*p))
    {
        valorPilha = desempilhaP(*p);
        if (valor == valorPilha)
        {
            cont++;
        }
        empilhaP(&pAux, valorPilha);
    }
    while(!vaziaP(&pAux))
    {
        empilhaP(*p, desempilhaP(&pAux));
    }
    return cont;
}
