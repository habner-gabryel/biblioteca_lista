#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include Fila.h
#include Pilha.h

/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int comparaInt(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;
    return *p2 - *p1;
}
/* ---------------------------------------- */
void imprimeInt(void *info){
   int *pi = (int *) info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void* alocaInfoInt(void *info){
   int * pi = (int *) malloc(sizeof(int));
   *pi = *((int*)info);
   return pi;
}
/* ---------------------------------------- */
int* alocaInt(int n){
   int *pi = (int *) malloc(sizeof(int));
   *pi = n;
   return pi;
}

/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int          comparaData  (void *info1, void *info2){
    struct Data *p1 = (struct Data *) info1;
    struct Data *p2 = (struct Data *) info2;
    return ((p2->ano - p1->ano)*365) +
           ((p2->mes - p1->mes)*30)  +
            (p2->dia - p1->dia)  ;
}
/* ---------------------------------------- */
void         imprimeData  (void *info){
   struct Data *pd = (struct Data *) info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void*        alocaInfoData(void *info){
   struct Data * pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = ((struct Data*)info)->dia;
   pd->mes = ((struct Data*)info)->mes;
   pd->ano = ((struct Data*)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data* alocaData    (int dia, int mes, int ano){
   struct Data *pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}
/* ---------------------------------------- */
int palindroma (char palavra[]) {
   pDPilha pilha = criarPilha();
   int len = strlen(palavra);
   for (int i = 0; i < len / 2; i++) {
      empilharInfo(pilha, (void*)(intptr_t)palavra[i]);
   }

   while(!pilhaVazia(pilha)) {
      char topo = (char)(intptr_t)desempilharInfo(pilha);
      if (topo != palavra[len - 1 - (len / 2 - 1)]) {
         return 0; // Não é palíndroma
      }
   }
   return 1; // É palíndroma
}
/* ---------------------------------------- */
int balanceamento (char expressao[], int tamanho) {
   pDPilha pilha = criarPilha();
   for (int i = 0; i < tamanho; i++) {
      char c = expressao[i];
      if (c == '(' || c == '{' || c == '[') {
         empilharInfo(pilha, (void*)(intptr_t)c);
      } else if (c == ')' || c == '}' || c == ']') {
         if (pilhaVazia(pilha)) {
            return 0; // Expressão desequilibrada
         }
         char topo = (char)(intptr_t)desempilharInfo(pilha);
         if ((c == ')' && topo != '(') ||
             (c == '}' && topo != '{') ||
             (c == ']' && topo != '[')) {
            return 0; // Expressão desequilibrada
         }
      }
   }
   return pilhaVazia(pilha); // Retorna 1 se equilibrada, 0 caso contrário
}
/* ---------------------------------------- */
int avaliaExpressaoAritmetica(char expressao[]) {
   pDPilha pilha = criarPilha();
   for (int i = 0; i < strlen(expressao); i++) {

      char caracter = expressao[i];
      
      if (caracter >= '0' && caracter <= '9') {
         empilharInfo(pilha, (void*)(intptr_t)(caracter - '0'));
      } else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {
         if (pilhaVazia(pilha)) {
            return 0; // Expressão inválida
         }
         int b = (int)(intptr_t)desempilharInfo(pilha);
         if (pilhaVazia(pilha)) {
            return 0; // Expressão inválida
         }
         int a = (int)(intptr_t)desempilharInfo(pilha);
         int resultado;
         switch (caracter) {
            case '+': resultado = a + b; break;
            case '-': resultado = a - b; break;
            case '*': resultado = a * b; break;
            case '/': 
               if (b == 0) {
                  return 0; // Divisão por zero
               }
               resultado = a / b; 
               break;
         }
         empilharInfo(pilha, (void*)(intptr_t)resultado);
      }
   }
   if (pilhaVazia(pilha)) {
      return 0; // Expressão inválida
   }
   int resultadoFinal = (int)(intptr_t)desempilharInfo(pilha);
   return pilhaVazia(pilha) ? resultadoFinal : 0; // Retorna o resultado se válido, caso contrário 0
}

#endif /* UTILS_H */
