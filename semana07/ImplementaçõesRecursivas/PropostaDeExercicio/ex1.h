#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 99

typedef struct{
  int chave;
  char exp[MAX];
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  TipoNoh *topo;
} TipoPilha;

void STACKinit (TipoPilha*);
void STACKdestroy (TipoPilha*);
int STACKempty(TipoPilha*);
int STACKpush(TipoPilha*, TipoItem);
int STACKpop(TipoPilha*, TipoItem*);
int STACKcalculator(TipoPilha*; TipoItem*);
int consultaTopo(TipoPilha*,TipoItem*);
void imprimeItem(TipoPilha*);
void imprimePilha(TipoItem);