#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, crie uma função para verificar se uma expressão composta apenas por chaves, colchetes e
parênteses está ou não balanceada.
a) Exemplo de expressões balanceadas: “[ { () () } {} ]”, “{ [ ( [ { } ] ) ] }”
b) Exemplo de expressões não balanceadas: “{ [ ( } ] )”, “{ [ ) () ( ] }”

*/

#include "Pilhas/pilha-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    bool balanceada = true;
    string exp;

    cout << "Digite uma expressão matemática: ";
    getline(cin, exp);


    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            empilhaP(&p, exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (vaziaP(&p))
                balanceada = false;

            char topo = desempilhaP(&p);

            if ((exp[i] == ')' && topo != '(') ||
                    (exp[i] == ']' && topo != '[') ||
                    (exp[i] == '}' && topo != '{'))
                balanceada = false;
        }
    }

    if(balanceada)
        cout << "A expressão está balanceada.";
    else
        cout << "A expressão não está balanceada.";
}


