#include "ex1.h"

int STACKempty(TipoPilha *pilha) { 
   return pilha->topo == NULL; 
}
void STACKinit (TipoPilha *pilha) { 
   pilha->topo = NULL;
}

void STACKdestroy(TipoPilha *pilha){
   TipoNoh *ptrAux;
   if(!STACKempty(pilha)){
      ptrAux = pilha->topo;
      while(ptrAux!=NULL){
         pilha->topo = ptrAux->prox;
         free(ptrAux);
         ptrAux = pilha->topo;
      }
   }
}

void STACKpush(int item) { 
   s[topo++] = item; 
}

// Retira o item que estiver no topo da
// pilha. Devolve o valor do elemento
// retirado. 
int STACKpop() { 
   return s[--topo]; 
}

int STACKcalculator(){
   for (i = 0; i < strlen(item.exp); i++) {
      if (item->exp[i] == '+')
         STACKpush(STACKpop(item->exp[i]) + STACKpop());
      if (item->exp[i] == '*')
         STACKpush(STACKpop() * STACKpop());
      if (item->exp[i] >= '0' && item->exp[i] <= '9') 
         STACKpush(0);
      while (item->exp[i] >= '0' && item->exp[i] <= '9') 
         STACKpush(10*STACKpop() + (item->exp[i++] - '0')); 
   }
}

void imprimePilha(TipoItem item){
   printf("%d \n", STACKpop());
}