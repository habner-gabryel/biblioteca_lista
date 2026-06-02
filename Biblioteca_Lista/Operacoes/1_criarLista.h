#ifndef CRIAR_LISTA_H
#define CRIAR_LISTA_H

pDLista criarLista(){

   pDLista lista = malloc(sizeof(DLista));
   //  struct dLista* lista = malloc(sizeof(struct dLista));

   lista->quantidade = 0;
   lista->inicio     = NULL;
   lista->fim        = NULL;

   return lista;
}

#endif
