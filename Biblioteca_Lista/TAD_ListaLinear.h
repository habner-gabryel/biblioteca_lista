#ifndef LISTA_TAD_H
#define LISTA__TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh  Noh;
typedef Noh*        pNoh;

/* descritor da lista */
typedef struct dLista  DLista;
typedef DLista*        pDLista;

// defini��es de ponteiros para fun��o
typedef int   (*FuncaoComparacao)(void*, void*);
typedef void  (*FuncaoImpressao) (void*);
typedef void* (*FuncaoAlocacao)  (void*);
typedef void  (*FuncaoLiberacao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista  criarLista    ();
pDLista  criarListaComTamanho(int);

void     incluirInfoFim   (pDLista, void*);
void     incluirInfoInicio(pDLista, void*);
void     incluirInfoMeio  (pDLista, void*, int);
void     incluirInfoOrdenada (pDLista, void*, FuncaoComparacao);

int      excluirInfo   (pDLista, void*);
int      excluirInfo1   (pDLista, void*, FuncaoLiberacao);

int      contemInfo    (pDLista, void*, FuncaoComparacao);
void*    obterInfoPos  (pDLista, int);

void     imprimirLista (pDLista, FuncaoImpressao);

void     destruirLista     (pDLista);
void     destruirListaInfo (pDLista, FuncaoLiberacao);

pDLista  duplicarLista (pDLista, FuncaoAlocacao);

/* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista  dividirLista (pDLista, int);

pDLista  unirListas   (pDLista, pDLista, FuncaoComparacao);

pDLista  interseccaoListas (pDLista, pDLista, FuncaoComparacao);









#endif

