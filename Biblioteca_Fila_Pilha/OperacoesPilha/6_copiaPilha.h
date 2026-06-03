#ifndef COPIA_PILHA_H
#define COPIA_PILHA_H

pDPilha copiaPilha(pDPilha pilha, FuncaoAlocacao funcaoAlocacao){
    pDPilha novaPilha = criarPilha();
    pDPilha pilhaAuxiliar = criarPilha();

    while(!pilhaVazia(pilha)){
        void* info = desempilharInfo(pilha);
        empilharInfo(novaPilha, funcaoAlocacao(info));
        empilharInfo(pilhaAuxiliar, info);
    }

    while(!pilhaVazia(pilhaAuxiliar)){
        void* info = desempilharInfo(pilhaAuxiliar);
        empilharInfo(pilha, info);
    }

    return novaPilha;
}

#endif