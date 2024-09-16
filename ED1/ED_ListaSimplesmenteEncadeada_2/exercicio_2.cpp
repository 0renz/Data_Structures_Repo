#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Um grupo de pesquisa em segurança da informação está estudando a frequência de uso de senhas
semelhantes pelos usuários de um determinado sistema. Assim, foi criada uma lista contendo as
senhas dos usuários. Uma das análises a ser realizada é a verificação de senhas não seguras. Uma
senha pode ser considerada “não segura” se ela possuir uma quantidade muito pequena de
caracteres ou for utilizada por uma quantidade muito grande de usuários. Para classificar as senhas
não seguras, você deve criar uma lista simplesmente encadeada contendo todas as senhas com
menos de 4 caracteres ou cuja frequência de utilização é maior que 5 (ou seja, senhas que aparecem
mais que cinco vezes na lista). Crie a função naoSeguras que recebe uma lista de senhas e retorna
outra lista contendo todas as senhas não seguras existentes.
*/

void senhasFracas(No<string> **ListaSenhas);
int buscaQuantidade(No<string> ***ListaSenhas, string senha);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<string> *ListaSenhas; // cria o primeiro nó
    inicializaL(&ListaSenhas);

    string senha = "aaaaaaaaa";
    insereInicioL(&ListaSenhas, senha);
    senha = "abc1234";
    insereInicioL(&ListaSenhas, senha);
    senha = "hgflkj99";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "123";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "123";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);
    senha = "AAA11022";
    insereInicioL(&ListaSenhas, senha);



    mostraL(&ListaSenhas);
    senhasFracas(&ListaSenhas);

    int num = 5;

    return EXIT_SUCCESS;
}

void senhasFracas(No<string> **ListaSenhas)
{
    No<string> *senhasFracas; // cria o primeiro nó
    inicializaL(&senhasFracas);
    string senha;

    for (int i = 0; i < totalL(ListaSenhas); i++)
    {
        senha = removeInicioL(ListaSenhas);
        if (senha.length() < 4 || (buscaQuantidade(&ListaSenhas, senha) >= 5))
        {
            if (buscaL(&senhasFracas, senha) == NULL)
            {
              insereInicioL(&senhasFracas, senha);
            }
        }
        insereFinalL(ListaSenhas, senha);
    }
    mostraL(&senhasFracas);
}

int buscaQuantidade(No<string> ***ListaSenhas, string senha)
{
    int cont = 0;
    string senhaAux;

    No<string> *listaAux; // cria o primeiro nó
    inicializaL(&listaAux);

    while (!(vaziaL(*ListaSenhas)))
    {
        senhaAux = removeInicioL(*ListaSenhas);
        if (senha == senhaAux)
        {
            cont++;
        }
        insereFinalL(&listaAux, senhaAux);
    }

    while(!vaziaL(&listaAux))
    {
        insereFinalL(*ListaSenhas, removeInicioL(&listaAux));
    }
    return cont;
}
