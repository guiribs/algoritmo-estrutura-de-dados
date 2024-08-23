#include "FilaDinamicaSenhas.h"

void imprimeMenu();
void leDadosNome(TipoItem*);
void leDadosNomePreferencial(TipoItem*);

int main(){
  TipoFila fila;
  TipoItem item;
  int op = 0, i;

  inicializaFila(&fila);

  while(op != 5){
    imprimeMenu();
    printf("\nOpção: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosNome(&item);
        if(insereNaFila(&fila,item))
          printf("\nSenha retirada com sucesso!\n");
        else
          printf("\nErro! Não foi possível retirar senha!\n");
        break;
      case 2:
        leDadosNomePreferencial(&item);
        if(insereNaFila(&fila,item))
          printf("\nSenha retirada com sucesso!\n");
        else
          printf("\nErro! Não foi possível retirar senha!\n");
        break;
      case 3:
        if(!filaVazia(&fila)){
          printf("\nFila:\n");
          imprimeFila(&fila);
        }
        else{
          printf("\nFila Vazia!\n");
        }
        break;
      case 4:
        if(retiraDaFila(&fila,&item)){
          printf("\nAtendimento realizado com sucesso!");
          printf("\nItem: %i %s\n",item.senha,item.nome);
        }
        else{
          printf("\nErro! Não foi possível retirar da fila!\n");
        }
        break;
      case 5:
        destroiFila(&fila);
        printf("\nAtedimento Encerrado!\nAté logo!\n");
        break;
      default:
        break;
    }
  }

  return 0;
}

void imprimeMenu(){
  printf("\nMenu");
  printf("\n1 - Imprimir Senha");
  printf("\n2 - Imprimir Senha Preferencial");
  printf("\n3 - Imprime fila");
  printf("\n4 - Retirar Da Fila");
  printf("\n5 - Sair");
}

void leDadosNomePreferencial(TipoItem *item){
  item->senha = 1;
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
}

void leDadosNome(TipoItem *item){
  item->senha = 0;
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
}