#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR



struct No
{
    Funcionario dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};

/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, Lista &l)
{
    No *n = l.inicio;
    os << "L:{";
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    os << "}";
    return os;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado.codigo;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while(n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

Funcionario leInicio(Lista *lista)
{
    Funcionario doInicio;

    if(lista->inicio == NULL)
    {
        cout << "Lista vazia;";
        return doInicio;
    }

    doInicio = lista->inicio->dado;
    return doInicio;
}

Funcionario leFim(Lista *lista)
{
    Funcionario doFim;

    if(lista->inicio == NULL)
    {
        cout << "Lista vazia;";
        return doFim;
    }

    doFim = lista->fim->dado;
    return doFim;
}

Funcionario removeInicio(Lista *lista)
{
    Funcionario removido;
    No *aux;

    if(lista->inicio == NULL)
    {
        cout << "Lista vazia;";
        return removido;
    }

    if (lista->tamanho == 1)
    {
        removido = lista->inicio->dado;
        delete lista->inicio;
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
        return removido;
    }

    aux = lista->inicio;
    removido = lista->inicio->dado;
    lista->inicio = lista->inicio->prox;
    lista->tamanho--;

    delete aux;
    return removido;
}

/*
Funcionario removeFim(Lista *lista)
{
    Funcionario removido;
    No *aux;

    if(lista->inicio == NULL)
    {
        cout << "Lista vazia;";
        return removido;
    }

    if (lista->tamanho == 1)
    {
        removido = lista->inicio->dado; // mesmo que o fim
        delete lista->inicio;
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
        return removido;
    }

    aux = lista->fim;
    removido = lista->fim->dado;
    delete aux;



    lista->tamanho--;

    lista->fim = anterior;
    anterior->prox = NULL;

    return removido;
}
*/

bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
bool insereInicioL(Lista *lista, Funcionario valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}
bool insereFimL(Lista *lista, Funcionario valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}



bool removeL(Lista *lista, Funcionario valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaL(Lista *lista, Funcionario valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

float mediaFuncionario(Lista *lista)
{
    float media = 0.0;
    No *n = lista->inicio;
    int tamanho = lista->tamanho;

    if(n == NULL)
        return media;

    while(n)
    {
        media += n->dado.salario;
        n = n->prox;
    }
    return media/tamanho;
}

void nomeMenorMedia(Lista *lista)
{
    No *n = lista->inicio;

    if(n == NULL)
        cout << "Lista vazia";

    while(n)
    {
        if (n->dado.salario < mediaFuncionario(lista))
        {
            cout << "[" << n->dado.nome << "] ";
        }
        n = n->prox;
    }
}

void ordena(Lista *lista)
{
    No *n = lista->inicio;
    Funcionario fAux;
    int trocas;

    if(n == NULL)
        cout << "Lista vazia";

    do
    {
        trocas = 0;
        while(n->prox != NULL)
        {
            if (n->dado.nome > n->prox->dado.nome)
            {
                fAux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = fAux;
                trocas++;
            }
            n = n->prox;
        }
        n = lista->inicio;
    }
    while (trocas != 0);
}

void inverteLista(Lista *lista)
{
    // Inverter lista -> para implementar, use uma lista auxiliar e as funções insere fim, insere início, remove
    //fim, remove início.

    No *n = lista->inicio;

    if(n == NULL)
        cout << "Lista vazia";

    Lista listaAux = Lista();

    while(!vaziaL(lista))
        insereFimL(&listaAux, removeInicio(lista));

    while(!vaziaL(&listaAux))
        insereInicioL(lista, removeInicio(&listaAux));

}

void mostraOrdenadoIdade (Lista *lista)
{
    // Mostrar a lista ordenada pela idade dos funcionários: para implementar, use uma lista auxiliar para
    //armazenar os funcionários ordenados e, em seguida, mostre a lista auxiliar.

    /// jogar desordenado na lista auxiliar e depois ordenar

    No *n = lista->inicio;
    Funcionario fAux, fAuxMaior;
    int trocas;
    Lista listaAux = Lista();

    if(n == NULL)
        cout << "Lista vazia";


}

#endif // _HPP_LISTA_DESCRITOR



