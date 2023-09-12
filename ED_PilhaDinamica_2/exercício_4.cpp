
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Crie um programa para converter número decimais em hexadecimais empregando uma pilha
*/

#include "Pilhas/pilha-dinamica.hpp"

void hexadecimal(Pilha *p, int num);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int num;

    Pilha p;

    cout << "Digite um número: ";
    cin >> num;

    hexadecimal(&p, num);
}

void hexadecimal(Pilha *p, int num)
{
    while((num / 16 != 0))
    {
        empilhaP(p, (num % 16));
        num = num / 16;

        if((num / 16 == 0))
            empilhaP(p, num);
    }

    mostraP(p);
    destroiP(p);
}
