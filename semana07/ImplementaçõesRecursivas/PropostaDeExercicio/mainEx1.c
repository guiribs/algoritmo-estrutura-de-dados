#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

int main (){
   TipoPilha pilha;
   TipoItem item;
   int n, i;

   STACKinit(&pilha);

   printf("Digite a expressão posfixa de no max. 100 caracteres:\n");
   fgets(item.exp, sizeof(item.exp), stdin);
   item.exp[strlen(item.exp)-1] = '\0';

   STACKcalculator(&pilha);
   imprimePilha(&pilha);
   STACKdestroy(&pilha);

   return 0;
}