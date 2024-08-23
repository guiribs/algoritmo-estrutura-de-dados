#include "FilaDinamicaCircular.h"

void inicializaFila(TipoFila *fila){

}

void destroiFila(TipoFila *fila){

}

int filaVazia(TipoFila *fila){

}

int insereNaFila(TipoFila *fila,TipoItem item){
    TipoNoh *novoNoh;
    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    if(novoNoh!=NULL){
        if(!filaVazia(fila)){
            novoNoh->prox = fila->fim->prox;
            fila->fim->prox = novoNoh;
            fila->fim = novoNoh;
        }
        else{
            novoNoh->prox = novoNoh;
            fila->fim->prox = novoNoh;
        }
        fila->n++;
        novoNoh->item = item;
        novoNoh->prox = NULL;
        fila->fim = novoNoh;
        return 1;
    }
    return 0;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}