#ifndef LDE_H
#define LDE_H

typedef struct TipoItem{
    int id;
    char titulo[20];
    char descricao[300];
    char dataEntrega[10];
} TipoItem;

typedef struct TipoElemento* Apontador;

typedef struct TipoElemento{ //Célula
    TipoItem item;
    struct TipoElemento *prox;
    struct TipoElemento *ant;
} TipoElemento;

typedef struct TipoLista{
    Apontador primeiro;
    Apontador ultimo;
} TipoLista;

void CriaListaVazia(TipoLista *lista);

bool VerificaListaVazia(TipoLista * lista);

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item);

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int idEleX);

void InsereListaUltimo(TipoLista *lista, TipoItem *item);

void RemoveListaPrimeiro(TipoLista *lista, TipoItem *item);

void RemoveListaUltimo(TipoLista *lista, TipoItem *item);

void RemoveElementoXbyId(TipoLista *lista, TipoItem *item, int idEle);

void ImprimeLista(TipoLista *lista);

void Menu();

#endif