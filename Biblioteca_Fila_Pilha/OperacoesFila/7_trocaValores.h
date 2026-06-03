#ifndef TROCA_VALORES_H
#define TROCA_VALORES_H

void trocaValores(pDFila fila, int pos1, int pos2) {
    if (pos1 < 0 || pos2 < 0) {
        return;
    }

    void* valor1 = nullptr;
    void* valor2 = nullptr;
    int index = 0;

    pDFila filaAuxiliar = criarFila();

    while (!filaVazia(fila)) {
        void* info = desenfileirarInfo(fila);

        if (index == pos1) {
            valor1 = info;
        } else if (index == pos2) {
            valor2 = info;
        }

        enfileirarInfo(filaAuxiliar, info);
        index++;
    }

    while (!filaVazia(filaAuxiliar)) {
        void* info = desenfileirarInfo(filaAuxiliar);

        if (info == valor1) {
            enfileirarInfo(fila, valor2);
        } else if (info == valor2) {
            enfileirarInfo(fila, valor1);
        } else {
            enfileirarInfo(fila, info);
        }
    }
}

#endif