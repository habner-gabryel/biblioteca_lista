#ifndef INTERSECCAO_PILHAS_H
#define INTERSECCAO_PILHAS_H

pDPilha interseccaoPilhas(pDPilha pilha1, pDPilha pilha2, FuncaoComparacao funcaoComparacao){
    pDPilha pilhaInterseccao = criarPilha();
    pDPilha pilhaAuxiliar = criarPilha();

    while (!pilhaVazia(pilha1)) {
        int info1 = (int)desempilharInfo(pilha1);
        empilharInfo(pilhaAuxiliar, info1);
    }

    while (!pilhaVazia(pilhaAuxiliar)) {
        int info1 = (int)desempilharInfo(pilhaAuxiliar);
        empilharInfo(pilha1, info1);

        pDPilha pilhaTemp = criarPilha();
        int encontrado = 0;

        while (!pilhaVazia(pilha2)) {
            int info2 = (int)desempilharInfo(pilha2);
            empilharInfo(pilhaTemp, info2);

            if (funcaoComparacao(info1, info2) == 0) {
                encontrado = 1;
            }
        }

        while (!pilhaVazia(pilhaTemp)) {
            int info2 = (int)desempilharInfo(pilhaTemp);
            empilharInfo(pilha2, info2);
        }

        if (encontrado) {
            empilharInfo(pilhaInterseccao, info1);
        }
    }

    return pilhaInterseccao;
}

#endif