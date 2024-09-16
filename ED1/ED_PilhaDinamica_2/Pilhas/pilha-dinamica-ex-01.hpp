#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha


struct NoPilha
{
    Cadastro dado; //informa��o do n�
    NoPilha *prox; //pr�ximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, Cadastro dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.
    return true;
}

//pop
Cadastro desempilhaP(Pilha *p)
{
    Cadastro dado;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado.nome = p->topo->dado.nome; //pega o dado armazenado no n� do topo
        dado.codigo = p->topo->dado.codigo;
        dado.idade = p->topo->dado.idade;
        dado.saldo = p->topo->dado.saldo;

        NoPilha *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}

int desempilhaPCodigo(Pilha *p)
{
    int dado = 0;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado.codigo;

        NoPilha *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}

//peek
int espiaP(Pilha* p)
{
    int dado = 0;

    if (vaziaP(p) == false)
        dado = p->topo->dado.codigo;

    return dado;
}

string espiaPNome(Pilha* p)
{
    string dado = "";

    if (vaziaP(p) == false)
        dado = p->topo->dado.nome;

    return dado;
}

void mostraP(Pilha *p)
{
    if(vaziaP(p) == false)
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            cout << no->dado.nome
            << ", codigo " << no->dado.codigo
            << ", idade " << no->dado.idade
            << ", saldo " << no->dado.saldo;
            cout << endl;

            no = no->prox;
        }
        cout << endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
bool buscaP(Pilha *p, int dado)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == dado)
            return true;

        no = no->prox;
    }

    return false;

}

void destroiP(Pilha *p)
{
    Cadastro dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

#endif // _HPP_PILHA_DINAMICA





