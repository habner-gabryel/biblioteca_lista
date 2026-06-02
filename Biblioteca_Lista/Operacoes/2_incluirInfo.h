#ifndef INCLUIR_INFO_FIM_H
#define INCLUIR_INFO_FIM_H

void incluirInfoFim(pDLista pd, void* info){

       pNoh novoNoh;
       novoNoh = malloc(sizeof(Noh));

       novoNoh->info = info;
       novoNoh->prox = NULL;

       if(pd->inicio == NULL)
          pd->inicio = novoNoh;
       else
          pd->fim->prox = novoNoh;

       pd->fim = novoNoh;
}

#endif
