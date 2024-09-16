#include <iostream>
using namespace std;


/*
Crie um programa para verificar se uma cadeia de caracteres � pal�ndroma. Uma cadeia � pal�ndroma se ela � igual
� sua inversa. Por exemplo, �ovo�, �arara� e �ata� s�o cadeias pal�ndromas. Fa�a uso de uma fila e de uma pilha
para implementar o programa.
*/

#include "filas/filacircular-char.hpp"
#include "pilhas/pilha-dinamica-char.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string palavra;
    char cFila, cPilha;
    Pilha p;
    Fila f;
    bool palindromo = true;

    cout << "Digite uma cadeia de caracteres: ";
    getline(cin, palavra);

    inicializaF(&f, palavra.length());

    for (int i = 0; i < palavra.length(); i++)
    {
      enfileiraF(&f, palavra[i]);
      empilhaP(&p, palavra[i]);
    }

    for (int i = 0; i < palavra.length(); i++)
    {
        cFila = desenfileiraF(&f);
        cPilha = desempilhaP(&p);

        if (cFila != cPilha)
            palindromo = false;
    }

    if (palindromo)
    {
        cout << "Essa palavra � um pal�ndromo.";
    }
    else
        cout << "Essa palavra n�o � um pal�ndromo";

    destroiF(&f);
    destroiP(&p);

}

