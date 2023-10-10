#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Crie um programa para converter número decimais em hexadecimais empregando uma pilha
*/

#include "pilhas/pilha-dinamica.hpp"

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
    char num2;

    for(int i = 0; i < 16; i++)
    {
        if(num == i)
        {
            empilhaP(p, num);
        }
    }

    while((num / 16 != 0))
    {
        empilhaP(p, (num % 16));
        num = num / 16;

        if((num / 16 == 0))
            empilhaP(p, num);
    }

    mostraP(p);

    while(!vaziaP(p))
    {
        for(int i = 0; i < 16; i++)
        {
            if(espiaP(p) == i)
            {
                num = desempilhaP(p);

                if(num < 10)
                {
                    cout << num;
                }
                else
                {
                    switch(num)
                    {
                    case 10:
                        cout << "A";
                        break;
                    case 11:
                        cout << "B";
                        break;
                    case 12:
                        cout << "C";
                        break;
                    case 13:
                        cout << "D";
                        break;
                    case 14:
                        cout << "E";
                        break;
                    case 15:
                        cout << "F";
                        break;
                    }
                }
            }
        }
    }
    destroiP(p);
}
