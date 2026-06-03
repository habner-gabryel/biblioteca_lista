#ifndef ESTAVAZIA_FILA_H
#define ESTAVAZIA_FILA_H

int filaVazia(pDFila pdFila){

    if (pdFila->lista->quantidade != 0)
        return 0;
    else
        return 1;

}
#endif
