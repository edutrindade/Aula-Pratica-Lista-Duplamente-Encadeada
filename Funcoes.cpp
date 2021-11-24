#include <iostream>
#include <windows.h>
#include "ListaDuplamenteEncadeada.hpp"

using namespace std;

//Funções
void Menu();
void CabecalhoCadastro();
void CabecalhoListagemCompleta(); 
int CadastraTrabalho(TipoLista *lista);
int RemoveTrabalho(TipoLista *lista);
void RemovePorCodigo(TipoLista *lista);
void ListaTodosTrabalhos(TipoLista *lista);


void Menu() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     TRABALHOS ACADÊMICOS                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - INCLUIR NOVO TRABALHO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - REMOVER UM TRABALHO                                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - NAVEGAR PELOS TRABALHOS                                  �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - PESQUISAR UM TRABALHO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 5 - LISTAR TODOS OS TRABALHOS                                �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 6 - SAIR                                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CabecalhoCadastro() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     CADASTRO DE TRABALHO                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void CabecalhoListagemCompleta() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    TRABALHOS CADASTRADOS                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void MenuRemocao() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                       EXCLUIR TRABALHO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - PRIMEIRO DA LISTA                                        �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - ÚLTIMO DA LISTA                                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - POR CÓDIGO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - VOLTAR                                                   �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CabecalhoRemocaoPorCodigo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    EXCLUSÃO DE TRABALHO                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}


int CadastraTrabalho(TipoLista *lista) {
    system("cls");
    CabecalhoCadastro();

    TipoItem item;

    while((cout << "\n\n1. Código: ") && !(cin >> item.id)) {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    cin.ignore();

    cout << "2. Título: ";
    gets(item.titulo);
    cout << "3. Descrição: ";
    gets(item.descricao);
    cout << "4. Data de Entrega: ";
    gets(item.dataEntrega);

    InsereListaUltimo(lista, &item);

    cout << "\nTrabalho cadastrado com sucesso!\n\n";
    system("pause");
    system("cls");
}

int RemoveTrabalho(TipoLista *lista) {
    system("cls");
    
    TipoItem item;

    int opcao_menu;
    do {
        MenuRemocao();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu)) {
            cout << "  \n        Digite um valor válido."; 
            cin.clear(); 
            cin.ignore();
            Sleep(1000);
            system ("cls");
            MenuRemocao();
        }
        system ("cls");
        switch (opcao_menu) {
              case 1: RemoveListaPrimeiro(lista, &item); 
                      MenuRemocao();
                      cout << "\n\nTrabalho removido com sucesso!\n\n";
                      system("pause");
                      system("cls");
                      break;   
              case 2: RemoveListaUltimo(lista, &item); 
                      MenuRemocao();
                      cout << "\n\nTrabalho removido com sucesso!\n\n";
                      system("pause");
                      system("cls");
                      break; 
              case 3: RemovePorCodigo(lista);
                      cout << "\n\nTrabalho removido com sucesso!\n\n";
                      system("pause");
                      system("cls");
                      break;
              case 4: system("cls"); break;
              default: RemoveTrabalho(lista);
         }
    } while (opcao_menu>4 && opcao_menu<1); 
}

void RemovePorCodigo(TipoLista *lista) {
    TipoItem item;
    int cod;
    CabecalhoRemocaoPorCodigo();
    while((cout << "  \n        Informe o código do trabalho a ser removido: ") && !(cin >> cod)) {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    RemoveElementoXbyId(lista, &item, cod);
}

void ListaTodosTrabalhos(TipoLista *lista) {
    system("cls");
    CabecalhoListagemCompleta();
    ImprimeLista(lista);
    cout << endl << endl;
    system("pause");
    system("cls");
}