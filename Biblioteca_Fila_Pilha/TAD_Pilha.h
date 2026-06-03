#ifndef PILHA_TAD_H
#define PILHA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da pilha */
typedef struct dPilha  DPilha;
typedef DPilha*        pDPilha;

typedef int   (*FuncaoComparacao)(void *, void *);
typedef void* (*FuncaoAlocacao)  (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPilha  criarPilha     ();
void     empilharInfo   (pDPilha, void *);
void*    desempilharInfo(pDPilha);
int      pilhaVazia     (pDPilha);
int      pilhasIguais   (pDPilha, pDPilha, FuncaoComparacao);
pDPilha  copiaPilha     (pDPilha, FuncaoAlocacao);

#endif

