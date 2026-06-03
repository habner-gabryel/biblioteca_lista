#ifndef EMPILHAR_INFO_PILHA_H
#define EMPILHAR_INFO_PILHA_H

void empilharInfo(pDPilha pilha, void *info){
   // usaremos o final da lista como topo da pilha
   incluirInfo(pilha->lista, info);
}

#endif
