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
TipoArvore retira(TipoArvore, int);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvorePreOrdemParenteses(TipoArvore,int);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);
void ImprimePorAltura(TipoArvore,int);
void AAA (TipoArvore);
int Pesquisa(TipoArvore, int);
int VerificaAltura(TipoArvore);

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
      arvore->subArvoreEsq = montaArvore(arvore->subArvoreEsq,cod);
    }
    if(arvore->dado < cod){
     arvore->subArvoreDir = montaArvore(arvore->subArvoreDir, cod);
    }
  }
  return arvore;
  }

/*TipoArvore montaArvoreEmOrdemPreOrdem(TipoArvore arvore, char *em, char *pre){
  if(arvoreVazia(arvore)){
    return instanciaArvore(cod);
  }
  if(!arvoreVazia(arvore)){
    if(arvore->dado > cod){
      arvore->subArvoreEsq = montaArvore(arvore->subArvoreEsq,cod);
    }
    if(arvore->dado < cod){
     arvore->subArvoreDir = montaArvore(arvore->subArvoreDir, cod);
    }
  }
  return arvore;
}*/


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

TipoArvore retira(TipoArvore arvore, int alvo){
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
          arvore->subArvoreEsq = retira(arvore->subArvoreEsq, alvo); //Neste passo, ele irá fazer a remoção como se o nó alvo estivesse em uma subarvore sem filhos (ou com apenas um filho);
          return arvore;
        }
      
    if(arvore->dado > alvo){
      arvore->subArvoreEsq = retira(arvore->subArvoreEsq,alvo);
      }
    if(arvore->dado < alvo){
      arvore->subArvoreDir = retira(arvore->subArvoreDir,alvo);
    }
  }
}
  return arvore;
  }

int VerificaAltura(TipoArvore arvore){
  int esquerda, direita;
  if(!(arvoreVazia(arvore))){
    esquerda = 1 + VerificaAltura(arvore->subArvoreEsq);
    direita = 1 + VerificaAltura(arvore->subArvoreDir);
    if(esquerda>direita)
      return esquerda;
    else
      return direita;
  }
  return 0;
} 

void AAA (TipoArvore arvore){
  int h = VerificaAltura(arvore);
  int i;
  for (i=1;i<=h;i++){
    ImprimePorAltura(arvore,i);
  }
}

void ImprimePorAltura(TipoArvore arvore, int altura){
  if(arvoreVazia(arvore)){
    return;
  }
  else{
    if(altura == 1)
      printf("%i",arvore->dado);
    else if (altura > 1){
      ImprimePorAltura(arvore->subArvoreEsq, altura-1);
      ImprimePorAltura(arvore->subArvoreDir, altura-1);
    }
  }
}

TipoArvore BuscaNo(TipoArvore arvore,int alvo){
  if((!arvoreVazia(arvore))){
    if(arvore->dado == alvo){
      return arvore;
    }
    if(arvore->dado != alvo){
      BuscaNo(arvore->subArvoreDir,alvo);
      BuscaNo(arvore->subArvoreEsq,alvo);
    }
  }
  else
    return NULL;
  
  return 0;
}

int AlturaArvore(TipoArvore arvore, int chave){
  TipoArvore aux = BuscaNo(arvore,chave);
  if(!arvoreVazia(aux)){
    return VerificaAltura(aux);
  }
  else
    return -1;
}
  
int main(){
  int codigo;
  TipoArvore arvore;
  inicializaArvore(arvore);

  return 0;
}