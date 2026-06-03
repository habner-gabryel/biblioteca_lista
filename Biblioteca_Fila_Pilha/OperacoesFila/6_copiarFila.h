#ifndef COPIAR_FILA_H
#define COPIAR_FILA_H

pDFila copiarFila(pDFila fila) {
    pDFila filaCopia = criarFila();

    while(!filaVazia(fila)) {
        void* info = desenfileirarInfo(fila);
        enfileirarInfo(filaCopia, info);
        enfileirarInfo(fila, info);
    }

    return filaCopia;
}

#endif