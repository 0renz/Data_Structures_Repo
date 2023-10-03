#include <iostream>
using namespace std;

struct fichaAtendimento
{
    string nome;
    int idade;
    char tipo;
    char quadroClinico;
};

#include "filas/fila-dinamica-ex04.hpp"
#include "pilhas/pilha-dinamica-ex04.hpp"

void criaFicha(Fila *Prioritaria, Fila *NaoPrioritaria, fichaAtendimento fA);
void atenderFicha(Fila *Prioritaria, Fila *NaoPrioritaria, fichaAtendimento fA);
void infoFichas(Fila *Prioritaria, Fila *NaoPrioritaria, fichaAtendimento fA);
void menorIdadeGrave(Pilha *ANIMALD, Pilha *ANIMALS, fichaAtendimento fA);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pilha ANIMALD, ANIMALS;
    Fila Prioritaria, NaoPrioritaria;
    fichaAtendimento fA;

    int escolha = -1;
    int contPrioritaria = 0;
    bool chegou3 = false;
    char pilhaC;

    do
    {
        system("cls");
        cout << "[VETERINÁRIA]" << endl << endl;
        cout << "[1] - Criar ficha de atendimento e adicionar na fila" << endl;
        cout << "[2] - Atender ficha da fila " << endl;
        cout << "[3] - Mostrar os dados das fichas de atendimento das filas (todas as filas);" << endl;
        cout << "[4] - Listar as informações sobre as filas de forma unificada" << endl;
        cout << "[5] - Listar as fichas já atendidas" << endl;
        cout << "[6] - Remover uma ficha da pilha" << endl;
        cout << "[7] - Mostrar o nome do animal armazenado nas pilhas que possui a menor idade com o quadro clínico grave." << endl << endl;

        cin >> escolha;

        switch(escolha)
        {
        case 1:
            criaFicha(&Prioritaria, &NaoPrioritaria, fA);
            break;
        case 2:
            if (contPrioritaria == 3)
            {
                chegou3 = true;
                contPrioritaria = 0;
            }

            if (!vaziaF(&Prioritaria) && !vaziaF(&NaoPrioritaria))
            {
                if(chegou3)
                {
                    fA = desenfileiraF(&NaoPrioritaria);
                    chegou3 = false;
                }
                else
                {
                    fA = desenfileiraF(&Prioritaria);
                    contPrioritaria++;
                }

            }
            else if (!vaziaF(&Prioritaria) && vaziaF(&NaoPrioritaria))
            {
                fA = desenfileiraF(&Prioritaria);
            }
            else
            {
                fA = desenfileiraF(&NaoPrioritaria);
            }

            if(fA.tipo == 'S')
                empilhaP(&ANIMALS, fA);
            else if (fA.tipo == 'D')
                empilhaP(&ANIMALD, fA);
            else
                cout << "Tipo de animal desconhecido";

            mostraF(&Prioritaria);
            mostraF(&NaoPrioritaria);
            system("pause");

            break;
        case 3:
            mostraF(&Prioritaria);
            mostraF(&NaoPrioritaria);
            system("pause");
            break;
        case 4:
            infoFichas(&Prioritaria, &NaoPrioritaria, fA);
            break;
        case 5:
            cout << "Animais selvagens: " << endl;
            mostraP(&ANIMALS);
            cout << "\nAnimais domésticos: " << endl;
            mostraP(&ANIMALD);
            system("pause");
            break;
        case 6:
            cout << "Informe a pilha (D-doméstico/S-selvagem): ";
            cin >> pilhaC;

            if(pilhaC == 'D')
            {
                if (!vaziaP(&ANIMALD))
                {
                    desempilhaP(&ANIMALD);
                    cout << "Desempilhado com sucesso." << endl;
                }
                else
                    cout << "Pilha vazia" << endl;

            }
            else if (pilhaC == 'S')
            {
                if (!vaziaP(&ANIMALS))
                {
                    desempilhaP(&ANIMALS);
                    cout << "Desempilhado com sucesso." << endl;
                }
                else
                    cout << "Pilha vazia" << endl;
            }
            else
                cout << "Pilha não reconhecida" << endl;

            system("pause");
            break;
        case 7:
            menorIdadeGrave(&ANIMALD, &ANIMALS, fA);
            system("pause");
            break;
        }
    }
    while(escolha != 0);

}

void criaFicha(Fila *Prioritaria, Fila *NaoPrioritaria, fichaAtendimento fA)
{
    cout << "\nDigite o nome: ";
    cin.ignore();
    getline(cin, fA.nome);
    cout << "\nDigite a idade: ";
    cin >> fA.idade;
    cout << "\nDigite o tipo (S-selvagem/D-doméstico): ";
    cin >> fA.tipo;
    cout << "\nDigite o quadro clínico (G-grave/E-estável): ";
    cin >> fA.quadroClinico;

    if (fA.quadroClinico == 'G')
    {
        enfileiraF(Prioritaria, fA);
        cout << "Adicionado com sucesso na fila prioritária." << endl;
        system("pause");
    }
    else if (fA.quadroClinico == 'E')
    {
        enfileiraF(NaoPrioritaria, fA);
        cout << "Adicionado com sucesso na fila não prioritária." << endl;
        system("pause");
    }
    else
    {
        cout << "Erro: tipo não identificado" << endl;
        system("pause");
    }
}

void infoFichas(Fila *Prioritaria, Fila *NaoPrioritaria, fichaAtendimento fA)
{
    Fila PrioritariaAux, NaoPrioritariaAux;
    int totalFichas = 0;
    float porcGrave = 0.0;
    int totalDomesticos = 0;

    while(!vaziaF(Prioritaria))
    {
        fA = desenfileiraF(Prioritaria);
        totalFichas++;
        if (fA.quadroClinico == 'G')
        {
            porcGrave++;
        }
        if (fA.tipo == 'D')
        {
            totalDomesticos++;
        }
        enfileiraF(&PrioritariaAux, fA);
    }

    while(!vaziaF(NaoPrioritaria))
    {
        fA = desenfileiraF(NaoPrioritaria);
        totalFichas++;
        if (fA.quadroClinico == 'G')
        {
            porcGrave++;
        }
        if (fA.tipo == 'D')
        {
            totalDomesticos++;
        }
        enfileiraF(&NaoPrioritariaAux, fA);
    }

    while(!vaziaF(&PrioritariaAux))
    {
        enfileiraF(Prioritaria, desenfileiraF(&PrioritariaAux));
    }

    while(!vaziaF(&NaoPrioritariaAux))
    {
        enfileiraF(NaoPrioritaria, desenfileiraF(&NaoPrioritariaAux));
    }

    if(totalFichas > 0)
        porcGrave = (porcGrave / totalFichas) * 100;

    cout << "Total de fichas: " << totalFichas << endl;
    cout << "Porcentagem de animais com quadro clínico grave: " << porcGrave << "%" << endl;
    cout << "Total de animais domésticos: " << totalDomesticos << endl;
    system("pause");
}

void menorIdadeGrave(Pilha *ANIMALD, Pilha *ANIMALS, fichaAtendimento fA)
{
    Pilha ANIMALDAUX;
    Pilha ANIMALSAUX;

    string nomeMenorIdadeGrave = "";
    int menorIdadeGrave = 0;

    while(!vaziaP(ANIMALD))
    {
        fA = desempilhaP(ANIMALD);

        if (fA.quadroClinico == 'G')
        {

            if(menorIdadeGrave == 0)
            {
                nomeMenorIdadeGrave = fA.nome;
                menorIdadeGrave = fA.idade;
            }

            if (fA.idade < menorIdadeGrave)
            {
                nomeMenorIdadeGrave = fA.nome;
                menorIdadeGrave = fA.idade;
            }
        }
        empilhaP(&ANIMALDAUX, fA);
    }

    while(!vaziaP(ANIMALS))
    {
        fA = desempilhaP(ANIMALS);

        if (fA.quadroClinico == 'G')
        {

            if(menorIdadeGrave == 0)
            {
                nomeMenorIdadeGrave = fA.nome;
                menorIdadeGrave = fA.idade;
            }

            if (fA.idade < menorIdadeGrave)
            {
                nomeMenorIdadeGrave = fA.nome;
                menorIdadeGrave = fA.idade;
            }
        }
        empilhaP(&ANIMALSAUX, fA);
    }

    while(!vaziaP(&ANIMALDAUX))
    {
        empilhaP(ANIMALD, desempilhaP(&ANIMALDAUX));
    }

    while(!vaziaP(&ANIMALSAUX))
    {
        empilhaP(ANIMALS, desempilhaP(&ANIMALSAUX));
    }

    cout << "Nome do animal armazenado mais novo com o quadro clínico grave: " << nomeMenorIdadeGrave << endl;
    cout << "Idade do animal: " << menorIdadeGrave << endl;
}
