#include <iostream>
using namespace std;
#include "listas/lista_dupla_string.hpp"

/*
a. Inserir no final da lista
b. Remover o primeiro elemento
c. Remover o �ltimo elemento. � proibido percorrer alista. Para encontrar o pen�ltimo n�,
acesse o ponteiro �anterior�.
Observa��o: fa�a uso do descritor da lista para remover ou inserir um novo n�, ou seja, n�o �
necess�rio percorrer a lista.
*/
void alteraLista(Lista *volta);


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Lista caminho = Lista();

    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "esquerda");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "baixo");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "cima");
    insereInicioL(&caminho, "direita");
    insereInicioL(&caminho, "baixo");
    insereInicioL(&caminho, "direita");
    mostraL(&caminho);

    Lista volta = Lista();
    volta = copiaLista(&caminho);

    alteraLista(&volta);
    cout << endl;
    mostrarInversoL(&volta);

    destroiL(&caminho);
    return EXIT_SUCCESS;
}

void alteraLista(Lista *volta)
{
     No* n = volta->inicio;
    while(n)
    {
        if(n->dado == "direita")
        {
            n->dado = "esquerda";
        }
        else if (n->dado == "esquerda")
        {
            n->dado = "direita";
        }
        else if (n->dado == "cima")
        {
            n->dado = "baixo";
        }
        else if (n->dado == "baixo")
        {
            n->dado = "cima";
        }
        n = n->prox;
    }
}



