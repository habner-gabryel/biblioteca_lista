#include <stdio.h>
#include "Utils.h"
#include "Pilha.h"
#include "Fila.h"

int main(){
    pDPilha pilhaInt = criarPilha();

    /* teste de empilhamento */
    empilharInfo(pilhaInt, alocaInt(5));
    empilharInfo(pilhaInt, alocaInt(3));
    empilharInfo(pilhaInt, alocaInt(9));
    empilharInfo(pilhaInt, alocaInt(1));
    empilharInfo(pilhaInt, alocaInt(2));


    pDFila filaAux = criarFila();

    /* teste de desempilhamento */
    void *info;

    while (! pilhaVazia(pilhaInt) ){
        info = desempilharInfo(pilhaInt);
        enfileirarInfo(filaAux, info);
    }

    while (! filaVazia(filaAux) ){
        info = desenfileirarInfo(filaAux);
        empilharInfo(pilhaInt, info);
    }

    // imprimir a pilha
    while (! pilhaVazia(pilhaInt) ){
        info = desempilharInfo(pilhaInt);
        printf("%d - ", *((int*)info));
    }


}
