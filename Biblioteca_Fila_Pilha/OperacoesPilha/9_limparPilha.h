#ifndef LIMPAR_PILHA_H
#define LIMPAR_PILHA_H

void limparPilha(pDPilha pilha, FuncaoLiberacao funcaoLiberacao){
    if(pilha == NULL) {
        return;
    }
   
    limparPilha(pilha, funcaoLiberacao);
    void* info = desempilharInfo(pilha);
    funcaoLiberacao(info);
}

#endif