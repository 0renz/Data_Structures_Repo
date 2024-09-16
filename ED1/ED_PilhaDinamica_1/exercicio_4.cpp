#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, crie uma fun��o para verificar se uma express�o composta apenas por chaves, colchetes e
par�nteses est� ou n�o balanceada.
a) Exemplo de express�es balanceadas: �[ { () () } {} ]�, �{ [ ( [ { } ] ) ] }�
b) Exemplo de express�es n�o balanceadas: �{ [ ( } ] )�, �{ [ ) () ( ] }�

*/

#include "Pilhas/pilha-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    bool balanceada = true;
    string exp;

    cout << "Digite uma express�o matem�tica: ";
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
        cout << "A express�o est� balanceada.";
    else
        cout << "A express�o n�o est� balanceada.";
}


