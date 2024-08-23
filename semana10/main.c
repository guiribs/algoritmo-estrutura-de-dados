#include "ArvoreBinaria.h"


int main(){
  TipoArvore arvore, arvoreDir, arvoreEsq, aux1, aux2;

  arvore = inicializaArvore();
  arvore = instanciaArvore(arvore, "A");

  arvoreDir = inicializaArvore();
  arvoreDir = instanciaArvore(arvoreDir, "B");
  arvore = insereSubArvoreDir(arvore, arvoreDir);
  arvoreEsq = inicializaArvore();
  arvoreEsq = instanciaArvore(arvoreEsq, "C");
  arvore = insereSubArvoreEsq(arvore, arvoreEsq);

  aux1 = arvoreDir;
  arvoreDir = inicializaArvore();
  arvoreDir = instanciaArvore(arvoreDir, "G");
  aux1 = insereSubArvoreDir(aux1, arvoreDir);
  arvoreEsq = inicializaArvore();
  arvoreEsq = instanciaArvore(arvoreEsq, "F");
  aux1 = insereSubArvoreEsq(aux1, arvoreEsq);

  aux2 = arvoreEsq;
  arvoreDir = inicializaArvore();
  arvoreDir = instanciaArvore(arvoreDir, "E");
  aux2 = insereSubArvoreDir(aux2, arvoreDir);
  arvoreEsq = inicializaArvore();
  arvoreEsq = instanciaArvore(arvoreEsq, "D");
  aux2 = insereSubArvoreEsq(aux2, arvoreEsq);

  imprimeArvorePreOrdem(arvore);
  imprimeArvoreEmOrdem(arvore);
  imprimeArvorePosOrdem(arvore);

  arvore = destroiArvore(arvore);

  return 0;
}