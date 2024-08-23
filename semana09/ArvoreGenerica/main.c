#include "Arvore.h"

int main(){
  TipoArvore a,aux,aux1;

  inicializaArvore(a);
  a = instanciaArvore(a,'A');
  imprimeArvore(a,0);
  printf("\n");


  inicializaArvore(aux);
  aux = instanciaArvore(aux,'B');
  inicializaArvore(aux1);
  aux1 = instanciaArvore(aux1,'E');
  aux = insereNaArvore(aux,aux1);
  aux1 = instanciaArvore(aux1,'F');
  aux = insereNaArvore(aux,aux1);
  a = insereNaArvore(a,aux);
  imprimeArvore(a,0);
  printf("\n");

  inicializaArvore(aux);
  aux = instanciaArvore(aux,'C');
  a = insereNaArvore(a,aux);
  imprimeArvore(a,0);
  printf("\n");


  inicializaArvore(aux);
  aux = instanciaArvore(aux,'D');
  inicializaArvore(aux1);
  aux1 = instanciaArvore(aux1,'G');
  aux = insereNaArvore(aux,aux1);
  aux1 = instanciaArvore(aux1,'H');
  aux = insereNaArvore(aux,aux1);
  a = insereNaArvore(a,aux);
  imprimeArvore(a,0);
  printf("\n");

//Parênteses aninhados
  printf("Parenteses aninhados:\n");
  imprimeArvorePA(a,0);
  printf("\n\n");

  a = destroiArvore(a);

  imprimeArvore(a,0);
  
  return 0;
}