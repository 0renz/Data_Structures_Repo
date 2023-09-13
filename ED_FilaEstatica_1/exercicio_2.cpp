#include <iostream>
using namespace std;


/*
Crie um programa para verificar se uma cadeia de caracteres é palíndroma. Uma cadeia é palíndroma se ela é igual
à sua inversa. Por exemplo, “ovo”, “arara” e “ata” são cadeias palíndromas. Faça uso de uma fila e de uma pilha
para implementar o programa.
*/

#include "filas/filacircular.hpp"
#include "pilhas/pilha-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string palavra;

    cout << "Digite uma cadeia de caracteres: ";
    cin.ignore();
    getline(cin, palavra);

    for(int i = 0; i < palavra.length(); i++)
    {
        cout << palavra[i] << endl;
    }


}

