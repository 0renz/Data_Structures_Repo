#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "listas/lista_dupla_generica.hpp"

/*
a. Inserir no final da lista
b. Remover o primeiro elemento
c. Remover o último elemento. É proibido percorrer alista. Para encontrar o penúltimo nó,
acesse o ponteiro “anterior”.
Observação: faça uso do descritor da lista para remover ou inserir um novo nó, ou seja, não é
necessário percorrer a lista.
*/

void volta(Lista<string> *caminho);

int main(void)
{
    ifstream leitura;
    leitura.open("leitura.txt");
    setlocale(LC_ALL, "Portuguese");
    Lista<string> caminho = Lista<string>();
    //configurar para ler arquivo texto

    if (leitura.is_open())
    {
        string palavra;
        while(getline(leitura, palavra, ','))
        {
            insereFinalL(&caminho, palavra);
        }
    }
    else
        cout << "Deu ruim";

    cout << "Ida: ";
    mostraL(&caminho);
    cout << "\nVolta: ";
    volta(&caminho);
    destroiL(&caminho);
    return EXIT_SUCCESS;
}

void volta(Lista<string> *caminho)
{
    Lista<string> ListaVolta = Lista<string>();

    ListaVolta = copiaLista(caminho);
    No<string>* n = ListaVolta.inicio;
    // lista aqui é um objeto, mas quando tu passa pra função o
    // que tu manipula é um ponteiro.

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
    mostrarInversoL(&ListaVolta);
}
