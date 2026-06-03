#ifndef INVERTER_FILA_H
#define INVERTER_FILA_H

PDFila inverterFila(pDFila fila) {
    pDFila filaInvertida = criarFila();

    while(!filaVazia(fila)) {
        void* info = desenfileirarInfo(fila);
        enfileirarInfo(filaInvertida, info);
    }

    return filaInvertida;
}

#endif