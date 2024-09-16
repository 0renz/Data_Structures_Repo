#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Faça um programa para ler uma string e após empilhar os caracteres que são letras em uma pilha P1 e empilhar
os que são dígitos em outra pilha P2. Ao final, desempilhe os dados de P2 e em seguida, os de P1, imprimindo-os
na tela.
Dicas:
− Use as funções isdigit e isalpha da biblioteca “#include <cctype>”
− A pilha P1 deve armazenar letras. Dessa forma, altere o arquivo “pilha.hpp” para atender esta
necessidade.
*/

#include "pilhas/pilhaChar.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha pAlpha;
    Pilha pNum;

    string palavra;
    int tamAlpha = 0, tamNum = 0;

    cout << "Digite uma palavra: ";
    getline(cin, palavra);

    inicializaP(&pAlpha, palavra.size());
    inicializaP(&pNum, palavra.size());

    for (int i = 0; i < palavra.size(); i++)
    {
        if (isdigit(palavra[i]))
        {
            empilhaP(&pNum, palavra[i]);
            tamNum++;
        }
        else if (isalpha(palavra[i]))
        {
            empilhaP(&pAlpha, palavra[i]);
            tamAlpha++;
        }
    }

    mostraP(&pAlpha);
    mostraP(&pNum);

    for (int i = 0; i < tamNum; i++)
        cout << desempilhaP(&pNum);

    for (int i = 0; i < tamAlpha; i++)
        cout << desempilhaP(&pAlpha);

    destroiP(&pAlpha);
    destroiP(&pNum);
}



