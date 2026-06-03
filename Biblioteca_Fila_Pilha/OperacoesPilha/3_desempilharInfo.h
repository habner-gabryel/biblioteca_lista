#ifndef DESEMPILHAR_INFO_PILHA_H
#define DESEMPILHAR_INFO_PILHA_H

void* desempilharInfo(pDPilha pilha){

   if(pilha->lista->quantidade == 0)
      return NULL;

   void* temp;
   // lembrando que usamos o final da lista como
   // topo da pilha
   temp = excluirInfoPos(pilha->lista,
                         pilha->lista->quantidade);
   return temp;
}

#endif
