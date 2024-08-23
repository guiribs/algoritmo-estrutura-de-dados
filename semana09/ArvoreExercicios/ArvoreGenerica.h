#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvGen{
  char info;
  struct arvgen *prim; //Ponteiro para lista de filhos
  struct arvgen *prox; //Ponteiro para lista de irmãos
}TArvGen;

typedef TArvGen *PArvGen;

PArvGen cria(char);
void insere(PArvGen, PArvGen);
void imprime(PArvGen);
void libera(PArvGen);
char verificaInfo(PArvGen); //Exercicio slide IMPLEMENTAR
int igual(PArvGen, PArvGen); //IMPLEMENTAR
PArvGen copia(PArvGen); //IMPLEMENTAR
//Ex.4 - Faça uma função para inserir um valor na arvore generica
//Ex.5
//Ex.6
//Ex.7