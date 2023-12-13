#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA



struct No
{
    int dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

    cout << "{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

int totalL(No **lista)
{
    int cont = 0;
    No *n = *lista;

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
bool insereInicioL(No **lista, int valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//insere no final da lista
bool insereFinalL(No **lista, int valor)
{
    No *n = *lista;
    No *novo = new No(); // aloca memória para o nó

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

int leFinalL(No **lista)
{
    int valor = 0;
    No *n = *lista;

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

bool igualL(No **lista, No **lista2)
{
    No *n = *lista;
    No *n2 = *lista2;

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

//retorna o valor do primeiro elemento da lista SEM removê-lo
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
int removeInicioL(No **lista)
{
    No* aux;
    int dado;

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
bool removeL(No **lista, int valor)
{
    No *anterior = NULL;
    No *atual = *lista;
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

int removeFinalL(No **lista)
{
    int valor = 0;
    No *n = *lista;
    No *anterior;

    if(n == NULL)
        return false;

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

int lePosicao(No **lista, int posicao)
{
    int cont = 0;
    int valor = 0;

    No *n = *lista;

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

No* buscaL(No **lista, int valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

void uniao(No **lista1, No **lista2, No **listaSaida)
{
    No *n = *lista1;
    No *n2 = *lista2;
    No *nSaida = *listaSaida;

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









