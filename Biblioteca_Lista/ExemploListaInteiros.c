#include <stdio.h>
#include "Lista.h"
#include "Utils.h"

int main(){

    pDLista listaInt;

    listaInt = criarLista();

    /* teste de inclusao */
    incluirInfoFim(listaInt, alocaInt(5));
    incluirInfoFim(listaInt, alocaInt(3));
    incluirInfoFim(listaInt, alocaInt(9));
    incluirInfoFim(listaInt, alocaInt(1));
    incluirInfoFim(listaInt, alocaInt(2));

    printf("\nResultado da inclusao \n");
    imprimirLista(listaInt, imprimeInt);

    /* teste de existencia */
    printf("Tem o nr 9: %d", contemInfo(listaInt, alocaInt(9), comparaInt));

    pDLista novaListaInt;
    novaListaInt = duplicarLista(listaInt, alocaInfoInt);

    incluirInfoFim(novaListaInt, alocaInt(8));
    imprimirLista(novaListaInt, imprimeInt);

    destruirListaInfo(novaListaInt, liberaInt);
    imprimirLista(novaListaInt, imprimeInt);

    pDLista outraLista;
    outraLista = criarLista();
    incluirInfoFim(outraLista, alocaInt(12));
    incluirInfoFim(outraLista, alocaInt(4));
    incluirInfoFim(outraLista, alocaInt(3));

    pDLista uniao = unirListas(listaInt, outraLista, comparaInt);
    printf("\n");
    imprimirLista(uniao, imprimeInt);

    //printf("\nResultado da exclusao \n");
    //imprimirLista(listaInt);
}
