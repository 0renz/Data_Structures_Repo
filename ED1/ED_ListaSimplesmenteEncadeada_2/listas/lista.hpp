#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA



template<typename T>
struct No
{
    T dado;
    struct No *prox;
};

template<typename T>
void inicializaL(No<T> **lista)
{
    *lista = NULL;
}

template<typename T>
bool vaziaL(No<T> **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
template<typename T>
void destroiL(No<T> **lista)
{
    No<T> *n = *lista;
    while (n != NULL)
    {
        No<T> *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

template<typename T>
void mostraL(No<T> **lista, string nome="")
{
    No<T> *n = *lista;

    cout << "L<" << nome << ">:{";
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
int totalL(No<T> **lista)
{
    int cont = 0;
    No<T> *n = *lista;

    if(n == NULL)
    {
        cout << "Lista vazia." << endl;
        return cont;
    }

    while(n != NULL)
    {
        cont++;
        n = n->prox;
    }

    return cont;
}

//insere no início da lista
template<typename T>
bool insereInicioL(No<T> **lista, T valor)
{

    No<T> *novo = new No<T>(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//insere no final da lista
template<typename T>
bool insereFinalL(No<T> **lista, T valor)
{
    No<T> *n = *lista;
    No<T> *novo = new No<T>(); // aloca memória para o nó

    novo->dado = valor;

    if (novo == NULL)
        return false;

    if(n == NULL)
    {
        novo->prox = *lista;
        *lista = novo;
        return true;
    }
    else if (n->prox == NULL)
    {
        n->prox = novo;
        novo->prox = NULL;
        return true;
    }
    else
    {
        while (n->prox != NULL)
        {
            n = n->prox;
            if (n->prox == NULL)
            {
                n->prox = novo;
                novo->prox = NULL;
                return true;
            }

        }
    }

    return true;
}

template<typename T>
T leFinalL(No<T> **lista)
{
    T valor = 0;
    No<T> *n = *lista;

    if(n == NULL)
        return false;

    while (n->prox != NULL)
    {
        n = n->prox;
        if (n->prox == NULL)
        {
            valor = n->dado;
            return valor;
        }
    }
}

template<typename T>
bool igualL(No<T> **lista, No<T> **lista2)
{
    No<T> *n = *lista;
    No<T> *n2 = *lista2;

    if(n == NULL && n2 == NULL) // listas vazias (iguais)
        return true;

    if (totalL(&n) != totalL(&n2)) // tamanhos diferentes (diferentes)
        return false;

    while (n != NULL || n2 != NULL)
    {
        if (n->dado != n2->dado)
            return false;

        n = n->prox;
        n2 = n2->prox;
    }
    return true;
}

template<typename T>
//retorna o valor do primeiro elemento da lista SEM removê-lo
T leInicioL(No<T> **lista)
{
    T dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

template<typename T>
//retorna o valor do primeiro elemento da lista e REMOVE o elemento
T removeInicioL(No<T> **lista)
{
    No<T>* aux;
    T dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}




///remover um nó da lista com um valor específico
template<typename T>
bool removeL(No<T> **lista, int valor)
{
    No<T> *anterior = NULL;
    No<T> *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endereço do elemento para excluir
    if(atual == NULL) /// se atual é NULL -> não encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a memória do elemento
    delete(atual);
    return true;
}

template<typename T>
T removeFinalL(No<T> **lista)
{
    T valor = 0;
    No<T> *n = *lista;
    No<T> *anterior;

    if(n == NULL)
        return false;
    else if (n->prox == NULL)
    {
        valor = n->dado;
        n->dado = 0;
        return valor;
    }
    else
    {
        while (n->prox != NULL)
        {
            anterior = n;

            n = n->prox;
            if (n->prox == NULL)
            {
                valor = n->dado;
                n = anterior;
                n->prox = NULL;
                return valor;
            }
        }
    }

}

template<typename T>
T lePosicao(No<T> **lista, T posicao)
{
    int cont = 0;
    int valor = 0;

    No<T> *n = *lista;

    if(n == NULL)
        return false;

    while (n->prox != NULL)
    {
        if (cont == posicao)
        {
            return n->dado;
        }
        cont++;
        n = n->prox;
    }
}

template<typename T>
No<T>* buscaL(No<T> **lista, T valor)
{
    No<T> *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

template<typename T>
void uniao(No<T> **lista1, No<T> **lista2, No<T> **listaSaida)
{
    No<T> *n = *lista1;
    No<T> *n2 = *lista2;
    No<T> *nSaida = *listaSaida;

    while(n != NULL)
    {
        insereInicioL(&nSaida, n->dado);
        n = n->prox;
    }
    while(n2 != NULL)
    {
        insereInicioL(&nSaida, n2->dado);
        n2 = n2->prox;
    }
    cout << "\nnSaida: ";
    mostraL(&nSaida);
}

#endif // _HPP_LISTA_DINAMICA
