#ifndef DESENFILEIRAR_INFO_FILA_H
#define DESENFILEIRAR_INFO_FILA_H

void* desenfileirarInfo(pDFila pdFila){

   // para saber se a fila está vazia
   if (pdFila->lista->quantidade == 0)
       return NULL;


   void* temp = excluirInfoPos(pdFila->lista, 1);

   return temp;
}

#endif
