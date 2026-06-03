#ifndef PILHAS_IGUAIS_H
#define PILHAS_IGUAIS_H

int pilhasIguais(pDPilha p1, pDPilha p2, FuncaoComparacao funcaoComparacao){
    if(pilhaVazia(p1) && pilhaVazia(p2)){
        return 1; // Ambas as pilhas estão vazias, são iguais
    }
    
    if(pilhaVazia(p1) || pilhaVazia(p2)){
        return 0; // Uma das pilhas está vazia e a outra não, não são iguais
    }
    
    void* info1 = desempilharInfo(p1);
    void* info2 = desempilharInfo(p2);
    
    int comparacao = funcaoComparacao(info1, info2);
    
    int resultado = 0;
    
    if(comparacao == 0){
        resultado = pilhasIguais(p1, p2, funcaoComparacao); // Verifica o restante das pilhas
    }
    
    empilharInfo(p1, info1); // Reempilha as informações para manter as pilhas inalteradas
    empilharInfo(p2, info2);
    
    return resultado; // Retorna o resultado da comparação
}

#endif