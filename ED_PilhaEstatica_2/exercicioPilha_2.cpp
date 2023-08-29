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
    bool balanceada = true;
    string exp;

    cout << "Digite uma expressão matemática: ";
    getline(cin, exp);

    inicializaP(&p, exp.size());

    for (int i = 0; i < exp.size(); i++)
    {
        if(exp[i] == '(')
        {
            empilhaP(&p, exp[i]);
            system("pause");
        }
        else if(exp[i] == ')')
        {
            if (vaziaP(&p))
            {
                cout << "A expressão não está balanceada.";
                return 0;
            }
            desempilhaP(&p);
            system("pause");
        }
    }

    if (vaziaP(&p))
                balanceada = true;
    else
        balanceada = false;

    if(balanceada)
        cout << "A expressão está balanceada.";
    else
        cout << "A expressão não está balanceada.";
}

