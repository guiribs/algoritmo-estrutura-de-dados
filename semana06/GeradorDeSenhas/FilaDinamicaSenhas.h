#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int senha;
  char nome[30];
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  int n;
  TipoNoh *inicio;
  TipoNoh *fim;
} TipoFila;

void inicializaFila(TipoFila*);
void destroiFila(TipoFila*);
int filaVazia(TipoFila*);
int insereNaFilaPreferencial(TipoFila*,TipoItem);
int insereNaFila(TipoFila*,TipoItem);
int retiraDaFila(TipoFila*,TipoItem*);
int imprimeFila(TipoFila*);
void imprimeItem(TipoItem);