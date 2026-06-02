#ifndef INCLUIR_INFO_FIM_H
#define INCLUIR_INFO_FIM_H

void incluirInfoInicio(pDLista pd, void* info){

       pNoh novoNoh;
       novoNoh = malloc(sizeof(Noh));

       novoNoh->info = info;
       novoNoh->prox = pd->inicio;

       if(pd->inicio == NULL)
          pd->fim = novoNoh;

       pd->inicio = novoNoh;
}

void incluirInfoMeio(pDLista pd, void* info, int pos){

       pNoh novoNoh;
       novoNoh = malloc(sizeof(Noh));

       novoNoh->info = info;

       if(pos == 0){
          novoNoh->prox = pd->inicio;
          pd->inicio = novoNoh;
          if(pd->fim == NULL)
             pd->fim = novoNoh;
       }
       else{
          pNoh aux = pd->inicio;
          int i;

          for(i=0; i<pos-1 && aux != NULL; i++)
              aux = aux->prox;

          if(aux != NULL){
             novoNoh->prox = aux->prox;
             aux->prox = novoNoh;
             if(novoNoh->prox == NULL)
                pd->fim = novoNoh;
          }
          else
             free(novoNoh);
       }
} 

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
