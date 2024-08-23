#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohArvore{
  char dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore);
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(char);
TipoArvore insereSubArvoreEsq(TipoArvore,int);
TipoArvore insereSubArvoreDir(TipoArvore,int);
TipoArvore montaArvore(TipoArvore, int);
TipoArvore montaArvoreEmOrdemPreOrdem(TipoArvore,char*,char*);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvorePreOrdemParenteses(TipoArvore,int);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);
int Pesquisa(TipoArvore, int);
TipoArvore retira(TipoArvore, int);

int arvoreVazia(TipoArvore arvore){
  return arvore==NULL; 
  }

TipoArvore inicializaArvore(TipoArvore arvore){
  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    arvore->subArvoreEsq = destroiArvore(arvore->subArvoreEsq);
    arvore->subArvoreDir = destroiArvore(arvore->subArvoreDir);
  free(arvore);
  }
return NULL;
}

TipoArvore instanciaArvore(char dado){ 
  TipoArvore arvore;
  arvore = (TipoArvore) malloc(sizeof(TipoArvore));
  arvore->dado = dado;
    arvore->subArvoreDir = inicializaArvore(arvore->subArvoreDir);
    arvore->subArvoreEsq = inicializaArvore(arvore->subArvoreEsq);

  return arvore;
}

TipoArvore montaArvore(TipoArvore arvore, int cod ){
  if(arvoreVazia(arvore)){
    return instanciaArvore(cod);
  }
  if(!arvoreVazia(arvore)){
    if(arvore->dado > cod){
      montaArvore(arvore->subArvoreEsq,cod);
    }
    if(arvore->dado < cod){
      montaArvore(arvore->subArvoreDir, cod);
    }
  }
  return arvore;
  }




void imprimeArvorePreOrdem(TipoArvore arvore){
    int i;
  if(!arvoreVazia(arvore)){ 
      printf("%c\n",arvore->dado);
      imprimeArvorePreOrdem(arvore->subArvoreEsq);
      imprimeArvorePreOrdem(arvore->subArvoreDir);
}
  }

/*
  void imprimeArvorePreOrdemParenteses(TipoArvore arvore,int n){
  if(!arvoreVazia(arvore)){ 
    if(n==0){
      printf("-");
    }
      printf("%c",arvore->dado);
    if(!arvoreVazia(arvore->subArvoreEsq) && !arvoreVazia(arvore->subArvoreDir)){
      printf("(");
      imprimeArvorePreOrdemParenteses(arvore->subArvoreEsq,n+1);
      }
      if(!arvoreVazia(arvore->subArvoreEsq) && !arvoreVazia(arvore->subArvoreDir)){
      imprimeArvorePreOrdemParenteses(arvore->subArvoreDir,n+1);
        printf(")");
        }
    if(n==0){
      printf("-");
    }
}
  }
*/

void imprimeArvoreEmOrdem(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
      imprimeArvoreEmOrdem(arvore->subArvoreEsq);
     printf("%c",arvore->dado);
      imprimeArvoreEmOrdem(arvore->subArvoreDir);
    }
  }

void imprimeArvorePosOrdem(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
      imprimeArvorePosOrdem(arvore->subArvoreEsq);
      imprimeArvorePosOrdem(arvore->subArvoreDir);
    printf(" %c",arvore->dado);
}
  }

int Pesquisa(TipoArvore arvore,int alvo){
  if((!arvoreVazia(arvore))){
    if(arvore->dado == alvo){
      return 1;
    }
    if(arvore->dado != alvo){
      Pesquisa(arvore->subArvoreDir,alvo);
      Pesquisa(arvore->subArvoreEsq,alvo);
    }
  }
  return 0;
}

TipoArvore Retira(TipoArvore arvore, int alvo){
  TipoArvore ajudante;
  if(!arvoreVazia(arvore)){
    if(arvore->dado == alvo){
      
      if(arvore->subArvoreDir == NULL && arvore->subArvoreEsq == NULL){
        destroiArvore(arvore);
      }
      
      if(arvore->subArvoreDir != NULL && arvore->subArvoreEsq == NULL){
        ajudante = arvore->subArvoreDir;
        free(arvore);
        return ajudante;
      }
      
      if(arvore->subArvoreEsq != NULL && arvore->subArvoreDir ==NULL){
        ajudante = arvore->subArvoreEsq;
        free (arvore);
        return ajudante;
      }
      
      if(arvore->subArvoreEsq != NULL && arvore->subArvoreDir !=NULL){
        ajudante = arvore->subArvoreEsq;
        while(ajudante->subArvoreDir != NULL){
              ajudante = ajudante->subArvoreDir;
          }
          arvore->dado = ajudante->dado;
          ajudante->dado = alvo;
          arvore->subArvoreEsq = Retira(arvore->subArvoreEsq, alvo); //Neste passo, ele irá fazer a remoção como se o nó alvo estivesse em uma subarvore sem filhos (ou com apenas um filho);
          return arvore;
        }
      
    if(arvore->dado > alvo){
      arvore->subArvoreEsq = Retira(arvore->subArvoreEsq,alvo);
      }
    if(arvore->dado < alvo){
      arvore->subArvoreDir = Retira(arvore->subArvoreDir,alvo);
    }
  }
}

int main(){
  int codigo;
  TipoArvore arvore;
  inicializaArvore(arvore);

  return 0;
}