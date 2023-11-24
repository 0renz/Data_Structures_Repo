#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA

template<typename T>
struct No
{
    T dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
    }
};

template<typename T>
struct Lista
{
    No<T> *inicio; /// descritores
    No<T> *fim;
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
template<typename T>
ostream& operator<<(ostream& os, const No<T> *n)
{
    /// cout << n
    return os << "[ " << n->dado.codigo << ", " << n->dado.idade << ", " << n->dado.peso << " ]";
}

/// quanto cout receber uma struct Lista
template<typename T>
ostream& operator << (ostream& os, const Lista<T> &l)
{
    No<T> *n = l.inicio;
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

template<typename T>
void destroiL(Lista<T> *l)
{
    No<T> *n = l->inicio;
    while(n)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

template<typename T>
bool vaziaL(Lista<T> *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

template<typename T>
void mostraL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
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

template<typename T>
void mostrarInversoL(Lista<T> *lista)
{
    No<T> *n = lista->fim;
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
template<typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{

    No<T> *novo = new No<T>();
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

template<typename T>
bool insereFinalL(Lista<T> *lista, T valor)
{
    No<T> *novo = new No<T>();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;

    if (!lista->fim) //lista vazia?
    {
        novo->ant = nullptr;
        lista->inicio = novo;
    }
    else
    {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
    }

    lista->fim = novo;
    lista->tamanho++;

    return true;
}

template<typename T>
No<T>*buscaL(Lista<T> *lista, int valor)
{
    No<T> *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

template<typename T>
int removerPrimeiroNoL(Lista<T> *lista)
{
    if(!lista || vaziaL(lista))
        return 0;

    No<T> *aux = lista->inicio;
    int dado = lista->inicio->dado;

    lista->inicio = lista->inicio->prox;

    if (!lista->inicio) ///lista ficou vazia ?
        lista->fim = nullptr;
    else
        lista->inicio->ant = nullptr;

    /// libera a memória do elemento
    lista->tamanho--;
    delete aux;
    return dado;
}

template<typename T>
int removerUltimoNoL(Lista<T> *lista)
{
    if(!lista || vaziaL(lista))
        return 0;

    No<T> *aux = lista->fim;
    int dado = lista->fim->dado;

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

template<typename T>
bool removerNoL(Lista<T> *lista, No<T> *no)
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

template<typename T>
bool removeL(Lista<T> *lista,  int valor)
{
    No<T>* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

template<typename T>
bool removeTodos(Lista<T> *lista, T valor)
{
    while(removeL(lista, valor))
    {

    }

    return true;
}

template<typename T>
void ordenaLista(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    T Aux; ///
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

template<typename T>
Lista<T> copiaLista(Lista<T> *lista)
{
    Lista<T> listaCopia = Lista<T>();
    T aux;

    No<T> *n = lista->inicio;

    while(n)
    {
        aux = n->dado;
        insereFinalL(&listaCopia, aux);
        n = n->prox;
    }

    return listaCopia;
}

template<typename T>
void mostraOrdenadoCodigo(Lista<T> *lista)
{
    Lista<animal> listaAux = Lista<animal> ();
    listaAux = copiaLista(lista);
    No<T> *n = listaAux.inicio; //
    T Aux; ///
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
            if (n->dado.codigo > n->prox->dado.codigo)
            {
                Aux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = Aux;
                trocas++;
            }
            n = n->prox;
        }
        n = listaAux.inicio; //
    }
    while (trocas != 0);
    mostraL(&listaAux);
}

template<typename T>
Lista<T> leMaiores(Lista<T> *lista, int qtd)
{
    Lista<T> listaAux = Lista<T>();
    listaAux = copiaLista(lista);
    ordenaLista(&listaAux);

    int cont = 0;
    Lista<T> listaDosMaiores= Lista<T>();

    while (cont != qtd)
    {
        insereFinalL(&listaDosMaiores, removerPrimeiroNoL(&listaAux));
        cont++;
    }
    return listaDosMaiores;
}
#endif // _HPP_LISTA_DUPLA



