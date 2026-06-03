#include <stdio.h>
#include "Utils.h"
#include "Pilha.h"
#include "Fila.h"
#include "ListaLinear/Lista.h"

int main(){

    pDLista pListaInt = criarLista();
    incluirInfo(pListaInt, alocaInt(5));
    incluirInfo(pListaInt, alocaInt(8));
    incluirInfo(pListaInt, alocaInt(6));

    pDFila pFilaInt = criarFila();
    /* teste de enfileiramento */
    enfileirarInfo(pFilaInt, alocaInt(5));
    enfileirarInfo(pFilaInt, alocaInt(3));
    enfileirarInfo(pFilaInt, alocaInt(9));
    enfileirarInfo(pFilaInt, alocaInt(1));
    enfileirarInfo(pFilaInt, alocaInt(2));

    pDPilha pPilha = criarPilha();
    /* teste de empilhamento */
    empilharInfo(pPilha, pDFila);
    empilharInfo(pPilha, pDLista);
    empilharInfo(pPilha, pPilha);

}
