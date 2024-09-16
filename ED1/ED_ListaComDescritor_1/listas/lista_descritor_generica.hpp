#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR


template<typename T>
struct No
{
    T dado; ///
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

template<typename T>
struct Lista
{
    No<T> *inicio;
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
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
template<typename T>
ostream& operator << (ostream& os, Lista<T> &l)
{
    No<T> *n = l.inicio;
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

template<typename T>
void mostraL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

template<typename T>
void destroiL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    while(n != nullptr)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

template<typename T>
No<T>* leInicio(Lista<T> *lista) ///
{
    No<T>* doInicio; ///

    if(lista->inicio == NULL)
    {
        cout << "Lista vazia;";
        return doInicio;
    }

    doInicio = lista->inicio->dado;
    return doInicio;
}

template<typename T>
No<T>*  leFim(Lista<T> *lista) ///
{
    No<T>*  doFim; ///

    if(lista->inicio == NULL)
    {
        cout << "Lista vazia;";
        return doFim;
    }

    doFim = lista->fim->dado;
    return doFim;
}

template<typename T>
No<T>*  removeInicio(Lista<T> *lista) ///
{
    No<T>* removido; ///
    No <T>*aux;

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

template<typename T>
bool vaziaL(Lista<T> *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
template<typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{

    No<T> *novo = new No<T>();
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

template<typename T>
bool insereFimL(Lista<T> *lista, No<T>*  valor)
{

    No<T> *novo = new No<T>();
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

template<typename T>
bool removeL(Lista<T> *lista, No<T>*  valor)
{
    No <T>*anterior = nullptr;
    No <T>*atual = lista->inicio;
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

template<typename T>
No<T>* buscaL(Lista<T> *lista, No<T>* valor) ///
{
    No <T>*n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

/// exclusivos para funcionarios
template<typename T>
float mediaFuncionario(Lista<T> *lista)
{
    float media = 0.0;
    No<T> *n = lista->inicio;
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

template<typename T>
void nomeMenorMedia(Lista<T> *lista)
{
    No<T> *n = lista->inicio;

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
/// exclusivos para funcionarios

template<typename T>
void ordena(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    T fAux; ///
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

template<typename T>
void inverteLista(Lista<T> *lista)
{
    No<T> *n = lista->inicio;

    if(n == NULL)
        cout << "Lista vazia";

    Lista<T> listaAux = Lista<T>();

    while(!vaziaL(lista))
        insereFimL(&listaAux, removeInicio(lista));

    while(!vaziaL(&listaAux))
        insereInicioL(lista, removeInicio(&listaAux));

}

template<typename T>
Lista<T> uniao (Lista<T> *lista, Lista<T> *lista2)
{
    Lista<T> lista3 = Lista<T>();
    Lista<T> listaAux = Lista<T>();

    T Aux; ///


    if(vaziaL(lista) && vaziaL(lista2))
    {
        cout << "Listas vazias";
        return lista3;
    }

    while (!vaziaL(lista))
    {
        Aux = removeInicio(lista);
        insereInicioL(&lista3, Aux);
        insereInicioL(&listaAux, Aux);
    }

    while (!vaziaL(&listaAux))
        insereInicioL(lista, removeInicio(&listaAux));

    while (!vaziaL(lista2))
    {
        Aux = removeInicio(lista2);
        insereInicioL(&lista3, Aux);
        insereInicioL(&listaAux, Aux);
    }

    while (!vaziaL(&listaAux))
        insereInicioL(lista2, removeInicio(&listaAux));

    return lista3;

}

template<typename T>
bool repetido(Lista<T> *lista3, T Aux)
{
    No<T> *n3 = lista3->inicio;

    if (n3 == NULL)
        return false;

    while (n3 != NULL)
    {
        if (n3->dado == Aux)
            return true;

        n3 = n3->prox;
    }
    return false;
}

template<typename T>
Lista<T> intersec (Lista<T> *lista, Lista<T> *lista2)
{
    Lista<T> lista3 = Lista<T>();
    Lista<T> listaAux = Lista<T>();

    T Aux; ///

    No<T> *n = lista->inicio;
    No<T> *n2 = lista2->inicio;

    if(n == NULL && n2 == NULL)
    {
        cout << "Listas vazias";
        return lista3;
    }

    while (!vaziaL(lista))
    {
        Aux = removeInicio(lista);
        while (n2 != NULL)
        {
            if (n2->dado == Aux && !repetido(&lista3, Aux))
            {
                insereInicioL(&lista3, Aux);
            }
            n2 = n2->prox;
        }
        n2 = lista2->inicio;
        insereFimL(&listaAux, Aux);
    }

    while (!vaziaL(&listaAux))
        insereInicioL(lista, removeInicio(&listaAux));

    return lista3;

}

template<typename T>
bool insereOrdenadoL(Lista<T> *lista, T valor)
{
    No<T> *novo = new No<T>();
    if (novo == nullptr)
        return false;

    novo->dado = valor;

    if (vaziaL(lista) || valor > lista->inicio->dado) // inverte esse > aqui
    {
        // Inserção no início da lista ou em lista vazia
        novo->prox = lista->inicio;
        lista->inicio = novo;

        if (!lista->fim)
            lista->fim = lista->inicio;

        lista->tamanho++;
        return true;
    }

    No<T> *anterior = nullptr;
    No<T> *atual = lista->inicio;

    // Encontrar a posição de inserção
    while (atual && valor < atual->dado) // inverte esse < aqui
    {
        anterior = atual;
        atual = atual->prox;
    }

    // Inserir o novo elemento
    novo->prox = atual;
    anterior->prox = novo;

    if (!novo->prox)
        lista->fim = novo;

    lista->tamanho++;
    return true;
}

#endif // _HPP_LISTA_DESCRITOR



