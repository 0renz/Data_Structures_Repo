#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, crie uma função para verificar se uma expressão matemática composta apenas por parênteses
está ou não balanceada.

• Exemplo de expressões balanceadas: “(A+B)”, “((A+B)+(C+D))”
• Exemplo de expressões não balanceadas: “((A+B)”, “)A+B(”, “(A+B)) – (C + D”
*/

#include "pilhas/pilhaChar.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;

    string exp;
    bool balanceada = true;

    cout << "Digite uma expressão matemática: ";
    getline(cin, exp);

    inicializaP(&p, exp.size());
    for (int i = 0; i < exp.size(); i++)
    {
        cout << "a";
        if(exp[i] == '(')
        {
            empilhaP(&p, exp[i]);
            mostraP(&p);
            system("pause");
        }


        if(exp[i] == ')')
        {
            if (vaziaP(&p))
            {
                balanceada = false;
                break;
            }

            desempilhaP(&p);
            cout << "Desempilhou";
            system("pause");
        }

    }

    if(vaziaP(&p))
        cout << "A expressão está balanceada.";
    else
        cout << "A expressão não está balanceada.";
}




