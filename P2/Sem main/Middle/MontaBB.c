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
TipoArvore montaArvore(int*,TipoArvore, int);
TipoArvore montaArvoreEmOrdemPreOrdem(TipoArvore,char*,char*);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvorePreOrdemParenteses(TipoArvore,int);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);
void verificaAltura(TipoArvore, int);
void ColocaEmOrdem(char*);

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

TipoArvore insereSubArvoreEsq(TipoArvore pai, int k){ 
  TipoArvore filho;
  filho = instanciaArvore(k);
  pai->subArvoreEsq = filho;
  return pai;
  }
  

TipoArvore insereSubArvoreDir(TipoArvore pai, int k){ 
    TipoArvore filho;
  filho = instanciaArvore(k);
  pai->subArvoreDir = filho;
  return pai;
}
/*
TipoArvore montaArvore(TipoArvore pai,TipoArvore filhoEsq,TipoArvore filhoDir){
pai = insereSubArvoreEsq(pai,filhoEsq);
pai = insereSubArvoreDir(pai,filhoDir);
  return pai;
  }
*/

/*
TipoArvore montaArvoreVetor(int* elementos,TipoArvore arvore, int k){
  if(k<sizeof(elementos)){
  if(arvoreVazia(arvore)){
    arvore = instanciaArvore(elementos[k]);
  }
  if(!arvoreVazia(arvore)){
    if(arvore->dado < elementos[k]){
      montaArvore(elementos,arvore->subArvoreDir,k);
    }
    if(arvore->dado > elementos[k]){
      montaArvore(elementos,arvore->subArvoreEsq,k);
    }
  }
    }
  return arvore;
  }
*/
  
TipoArvore montaArvore(int elementos,TipoArvore arvore, int ){
  if(k<sizeof(elementos)){
  if(arvoreVazia(arvore)){
    arvore = instanciaArvore(elementos[k]);
  }
  if(!arvoreVazia(arvore)){
    if(arvore->dado < elementos[k]){
      montaArvore(elementos,arvore->subArvoreDir,k);
    }
    if(arvore->dado > elementos[k]){
      montaArvore(elementos,arvore->subArvoreEsq,k);
    }
  }
    }
  return arvore;
  }


/*
  TipoArvore MontaArvoreEmOrdemPreOrdem(TipoArvore arvore, char *EmOrdem, char *PreOrdem){
    int i, RaizEmOrdem;
    for(i=0;i<(strlen(EmOrdem));i++){
if(PreOrdem[0]==EmOrdem[i]){
  RaizEmOrdem = i;
}
}
  for(i=1;i<RaizEmOrdem;i++){
    if(RaizEmOrdem-i<EmOrdem[0]){
      
    } 
  }
return 0;
}


void imprimeArvorePreOrdem(TipoArvore arvore){
    int i;
  if(!arvoreVazia(arvore)){ 
      printf("%c\n",arvore->dado);
      imprimeArvorePreOrdem(arvore->subArvoreEsq);
      imprimeArvorePreOrdem(arvore->subArvoreDir);
}
  }
*/

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

int main(){
int i,exemplos,qntd,j;
  int *elementos;
  TipoArvore arvore;

  inicializaArvore(arvore);
  scanf("%i",&exemplos);

  for(j=0;j<exemplos;j++){
    printf("Case %i:\n",j+1);
    scanf("%i", &qntd);
    elementos = malloc(sizeof(qntd));
    for(i=0;i<qntd;i++){
      scanf("%i", &elementos[i]);  
    }
  arvore = montaArvore(elementos,arvore,0);
  printf("Pre.:");
  imprimeArvorePreOrdem(arvore);
  printf("\n");
  printf("In.:");
  imprimeArvoreEmOrdem(arvore);
  printf("\n");
  printf("Pos.:");
  imprimeArvorePosOrdem(arvore);
  printf("\n");
  }
  return 0;
}