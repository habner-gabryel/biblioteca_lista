#ifndef REMOVE_INFO_H
#define REMOVE_INFO_H

int removeInfo(pDPilha pilha, void *info, FuncaoComparacao funcaoComparacao){
    if(pilhaVazia(pilha)){
        return 0;
    }

    pDPilha pilhaAuxiliar = criarPilha();
    int encontrado = 0;

    while(!pilhaVazia(pilha)){
        void *topo = desempilharInfo(pilha);
        if(funcaoComparacao(topo, info) == 0){
            encontrado = 1;
            break;
        } else {
            empilharInfo(pilhaAuxiliar, topo);
        }
    }

    while(!pilhaVazia(pilhaAuxiliar)){
        void *topoAux = desempilharInfo(pilhaAuxiliar);
        empilharInfo(pilha, topoAux);
    }

    free(pilhaAuxiliar);

    return encontrado;
}

#endif