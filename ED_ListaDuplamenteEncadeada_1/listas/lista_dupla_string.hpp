#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA


struct No
{
    string dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
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
ostream& operator << (ostream& os, const Lista &l)
{
    No *n = l.inicio;
    os << "L[" << l.tamanho << "]:{";
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

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->prox;
        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no início da lista
bool insereInicioL(Lista *lista, string valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

bool insereFinalL(Lista *lista, string valor)
{
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;
    novo->ant = lista->fim;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}

No* buscaL(Lista *lista, string valor)
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

string removerPrimeiroNoL(Lista *lista)
{
    if(!lista || vaziaL(lista))
        return 0;

    string dado = lista->inicio->dado;

    lista->inicio = lista->inicio->prox;
    lista->inicio->ant = nullptr;

    if (!lista->inicio) ///lista ficou vazia ?
        lista->fim = nullptr;
    else
        lista->inicio->ant = nullptr;

    /// libera a memória do elemento
    lista->tamanho--;
    return dado;
}

string removerUltimoNoL(Lista *lista)
{
    if(!lista || vaziaL(lista))
        return 0;

    string dado = lista->fim->dado;

    No *aux = lista->fim;

    lista->fim = lista->fim->ant;
    if (lista->fim)
        lista->fim->prox = nullptr;
    else
        lista->inicio = nullptr;

    /// libera a memória do elemento
    lista->tamanho--;
    delete aux;
    return dado;
}

bool removerNoL(Lista *lista, No *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }
    else   /// elemento está no meio ou no fim
    {

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

/*
bool encontraValor(Lista *lista, int valor)
{
    if(vaziaL(lista))
        return false;
    else
    {
        No *n = lista->inicio;
        while(n)
        {
           if (n->dado == valor)
           {
              return true;
           }
           n = n->prox;
        }
    }
}
*/

bool removeL(Lista *lista, string valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

bool removeTodos(Lista *lista, string valor)
{
    while(removeL(lista, valor))
    {

    }

    return true;
}

void ordenaLista(Lista *lista)
{
    No *n = lista->inicio;
    string Aux; ///
    int trocas;

    if(n == NULL)
    {
       cout << "Lista vazia";
    }


    do
    {
        trocas = 0;
        while(n->prox != NULL)
        {
            if (n->dado < n->prox->dado)
            {
                Aux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = Aux;
                trocas++;
            }
            n = n->prox;
        }
        n = lista->inicio;
    }
    while (trocas != 0);
}

Lista copiaLista(Lista *lista)
{
    Lista listaAux = Lista();
    Lista listaAux2 = Lista();
    string aux;

    while(!vaziaL(lista))
    {
        insereInicioL(&listaAux, removerUltimoNoL(lista));
    }
    while(!vaziaL(&listaAux))
    {
        aux = removerUltimoNoL(&listaAux);
        insereInicioL(lista, aux);
        insereInicioL(&listaAux2, aux);
    }
    return listaAux2;
}

Lista leMaiores(Lista *lista, int qtd)
{
    Lista listaAux = Lista();
    listaAux = copiaLista(lista);
    mostraL(lista);
    mostraL(&listaAux);
    ordenaLista(&listaAux);
    mostraL(&listaAux);

    int cont = 0;
    Lista listaDosMaiores= Lista();


    while (cont != qtd)
    {
       mostraL(&listaAux);
       insereFinalL(&listaDosMaiores, removerPrimeiroNoL(&listaAux));
       mostraL(&listaDosMaiores);
       cont++;
    }

    mostraL(&listaDosMaiores);

    return listaDosMaiores;
}




#endif // _HPP_LISTA_DUPLA



