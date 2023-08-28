#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
A conversão de um número decimal N (base 10) para binário (base 2) é realizada por sucessivas divisões de N por
2, em que o número binário é obtido pelos restos das divisões realizadas. Crie um programa para converter
número decimais em binários empregando uma pilha.

*/

#include "pilhas/pilha.hpp"

void binario(Pilha *p, int num);


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    int num;

    cout << "Digite um número: ";
    cin >> num;

    binario(&p, num);
}

void binario(Pilha *p, int num)
{
    cout << endl;
    int cont = 0;
    int auxNum = num;

    while((auxNum / 2 != 0) || (auxNum / 2 != 0))
    {
        auxNum = auxNum / 2;
        cont++;

        if((auxNum / 2 == 0) || (auxNum / 2 == 0))
            cont++;
    }

    inicializaP(p, cont);

    while((num / 2 != 0) || (num / 2 != 0))
    {
        empilhaP(p, (num % 2));
        num = num / 2;

        if((num / 2 == 0) || (num / 2 == 0))
            empilhaP(p, (num));
    }

    mostraP(p);
    destroiP(p);
}
