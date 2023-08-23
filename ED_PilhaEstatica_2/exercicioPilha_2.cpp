#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Empregando pilha, crie uma fun��o para verificar se uma express�o matem�tica composta apenas por par�nteses
est� ou n�o balanceada.

� Exemplo de express�es balanceadas: �(A+B)�, �((A+B)+(C+D))�
� Exemplo de express�es n�o balanceadas: �((A+B)�, �)A+B(�, �(A+B)) � (C + D�
*/

#include "pilhas/pilhaChar.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;

    string exp;
    bool balanceada = true;

    cout << "Digite uma express�o matem�tica: ";
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
        cout << "A express�o est� balanceada.";
    else
        cout << "A express�o n�o est� balanceada.";
}




