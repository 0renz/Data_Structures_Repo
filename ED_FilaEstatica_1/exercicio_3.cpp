#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

/*
Construa um programa para gerenciar duas filas de impressão de documentos, as filas P - Prioritária e N - Não
Prioritária. Cada documento é composto pelas seguintes informações: nome, quantidade de páginas. A impressão
dos documentos deve seguir a seguinte política de prioridade:
    a) Quando a fila P não está vazia, imprimir um documento que está no início da fila P.
    b) Quando não há documentos na Fila P, o documento que está no início da fila N deve ser impresso.

O programa deve ler o arquivo entrada.txt e realizar as operações:
o Inicializar (TAM) – Inicializa as filas P e N com o tamanho TAM recebido por parâmetro.
o Mostrar (F) – Mostra os documentos da fila F. O parâmetro F pode assumir os valores “P” ou “N”.
o Enfileirar (NOME, PAG, F) – Cria-se um novo documento com os parâmetros NOME e PAG. O
documento criado deve ser enfileirado na fila F (o parâmetro F pode assumir os valores “P” ou
“N”).
o ImprimirDoc() – Remove um documento de uma das filas com base na política de prioridade.
o TotalPag() – Imprimir a soma do número de páginas de todos os documentos armazenados nas
filas.
o Consultar (NOME, F) – Consulta se o documento com nome NOME está armazenado na fila F (o
parâmetro F pode assumir os valores “P” ou “N”).
*/

struct Impressao
{
    string nome;
    int qtdPaginas;
};

#include "filas/filacircular-ex-3.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int escolha = -1;
    string operacao = "";

    Fila P;
    Fila N;

    ifstream entrada;
    entrada.open("entrada.txt");

    if(entrada.is_open())
    {
        Impressao imp;
        int n, pag;
        string nome;
        char c;

        while(entrada >> operacao)
        {
            if (operacao == "INICIALIZAR")
            {
                entrada >> n;

                if(verificaInicializacaoF(&P) || verificaInicializacaoF(&N))
                {
                    destroiF(&P);
                    destroiF(&N);
                }

                inicializaF(&P, n);
                inicializaF(&N, n);

                cout << "As filas P e N foram inicializadas com o tamanho " << n;
                getc(stdin);
            }
            else if (operacao == "MOSTRAR")
            {
                entrada >> c;

                if (c == 'P' && verificaInicializacaoF(&P))
                {
                    if (vaziaF(&P))
                    {
                        cout << "Fila vazia";
                        getc(stdin);
                    }
                    else
                    {
                        mostraF(&P);
                        getc(stdin);
                    }
                }
                else if (c == 'N' && verificaInicializacaoF(&N))
                {
                    if (vaziaF(&N))
                    {
                        cout << "Fila vazia";
                        getc(stdin);
                    }
                    else
                    {
                        mostraF(&N);
                        getc(stdin);
                    }
                }
                else if (c == 'P' && !verificaInicializacaoF(&P))
                {
                    cout << "ERRO: inicializar fila P";
                    getc(stdin);
                }
                else if (c == 'N' && !verificaInicializacaoF(&N))
                {
                    cout << "ERRO: inicializar fila N";
                    getc(stdin);
                }
            }
            else if (operacao == "ENFILEIRARDOC")
            {
                entrada >> nome >> n >> c;

                cout << "O documento " << nome << " (" << n << " pag) foi adicionado na fila " << c;

                if (c == 'P')
                {
                    imp.nome = nome;
                    imp.qtdPaginas = n;

                    if (!cheiaF(&P))
                    {
                        enfileiraF(&P, imp);
                        getc(stdin);
                    }
                    else
                    {
                        cout << "ERRO: Fila cheia";
                        getc(stdin);
                    }

                }
                else if (c == 'N')
                {
                    imp.nome = nome;
                    imp.qtdPaginas = n;

                    if (!cheiaF(&N))
                    {
                        enfileiraF(&N, imp);
                        getc(stdin);
                    }
                    else
                    {
                        cout << "ERRO: Fila cheia";
                        getc(stdin);
                    }
                }
            }
            else if(operacao == "IMPRIMIRDOC")
            {
                Impressao impAux;


                if (!verificaInicializacaoF(&P) || !verificaInicializacaoF(&N))
                {
                    if (!verificaInicializacaoF(&P) && !verificaInicializacaoF(&N))
                    {
                        cout << "ERRO: inicializar filas P e N";
                        getc(stdin);
                    }
                    else if (!verificaInicializacaoF(&P) && verificaInicializacaoF(&N))
                    {
                        cout << "ERRO: inicializar fila P";
                        getc(stdin);
                    }
                    else if (!verificaInicializacaoF(&N) && verificaInicializacaoF(&P))
                    {
                        cout << "ERRO: inicializar fila N";
                        getc(stdin);
                    }
                }
                else
                {
                    if(vaziaF(&P))
                    {
                        if(!vaziaF(&N))
                        {
                            impAux = desenfileiraF(&N);
                            cout << "O documento " << impAux.nome << " foi impresso.";
                            getc(stdin);
                        }
                        else
                        {
                            cout << "Não há documentos para imprimir.";
                            getc(stdin);
                        }
                    }
                    else
                    {
                        impAux = desenfileiraF(&P);
                        cout << "O documento " << impAux.nome << " foi impresso.";
                        getc(stdin);
                    }
                }
            }
            else if (operacao == "TOTALPAG")
            {
                Impressao impAux;
                int numPaginas = 0;
                Fila filaAux;
                inicializaF(&filaAux, 10);

                while(!vaziaF(&P))
                {
                    impAux = desenfileiraF(&P);
                    numPaginas += impAux.qtdPaginas;
                    enfileiraF(&filaAux, impAux);
                }
                while(!vaziaF(&filaAux))
                {
                    impAux = desenfileiraF(&filaAux);
                    enfileiraF(&P, impAux);
                }

                while(!vaziaF(&N))
                {
                    impAux = desenfileiraF(&N);
                    numPaginas += impAux.qtdPaginas;
                    enfileiraF(&filaAux, impAux);
                }
                while(!vaziaF(&filaAux))
                {
                    impAux = desenfileiraF(&filaAux);
                    enfileiraF(&N, impAux);
                }
                cout << numPaginas << " página(s)";
                getc(stdin);
            }
            else if(operacao == "CONSULTAR")
            {
                entrada >> nome >> c;
                Fila filaAux;
                inicializaF(&filaAux, 10);
                Impressao impAux;
                bool consulta = false;

                if (!verificaInicializacaoF(&P) || !verificaInicializacaoF(&N))
                {
                    if (!verificaInicializacaoF(&P) && !verificaInicializacaoF(&N))
                    {
                        cout << "ERRO: inicializar filas P e N";
                        getc(stdin);
                    }
                    else if (!verificaInicializacaoF(&P) && verificaInicializacaoF(&N))
                    {
                        cout << "ERRO: inicializar fila P";
                        getc(stdin);
                    }
                    else if (!verificaInicializacaoF(&N) && verificaInicializacaoF(&P))
                    {
                        cout << "ERRO: inicializar fila N";
                        getc(stdin);
                    }
                }
                else
                {
                    if (c == 'P')
                    {
                        if (!vaziaF(&P))
                        {
                            while(!vaziaF(&P))
                            {
                                impAux = desenfileiraF(&P);
                                if (impAux.nome == nome)
                                {
                                    consulta = true;
                                }
                                enfileiraF(&filaAux, impAux);
                            }
                            while(!vaziaF(&filaAux))
                            {
                                impAux = desenfileiraF(&filaAux);
                                enfileiraF(&P, impAux);
                            }

                            if (consulta)
                            {
                                cout << "O documento " << nome << " encontra-se na fila P";
                                getc(stdin);
                            }
                            else
                            {
                                cout << "O documento " << nome << " não está na fila P";
                                getc(stdin);
                            }
                        }
                        else
                        {
                            cout << "Fila vazia.";
                            getc(stdin);
                        }

                    }
                    else if (c == 'N')
                    {
                        if (!vaziaF(&N))
                        {
                            while(!vaziaF(&N))
                            {
                                impAux = desenfileiraF(&N);
                                if (impAux.nome == nome)
                                {
                                    consulta = true;
                                }
                                enfileiraF(&filaAux, impAux);
                            }
                            while(!vaziaF(&filaAux))
                            {
                                impAux = desenfileiraF(&filaAux);
                                enfileiraF(&N, impAux);
                            }

                            if (consulta)
                            {
                                cout << "O documento " << nome << " encontra-se na fila N";
                                getc(stdin);
                            }
                            else
                            {
                                cout << "O documento " << nome << " não está na fila N";
                                getc(stdin);
                            }
                        }
                        else
                        {
                            cout << "Fila vazia.";
                            getc(stdin);
                        }

                    }

                }

            }

        }
    }
    else
        cout << "Erro ao abrir o arquivo";
}
