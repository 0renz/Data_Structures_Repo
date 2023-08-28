#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
A convers�o de um n�mero decimal N (base 10) para bin�rio (base 2) � realizada por sucessivas divis�es de N por
2, em que o n�mero bin�rio � obtido pelos restos das divis�es realizadas. Crie um programa para converter
n�mero decimais em bin�rios empregando uma pilha.

*/

#include "pilhas/pilha.hpp"

void binario(Pilha *p, int num);


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    int num;

    cout << "Digite um n�mero: ";
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
