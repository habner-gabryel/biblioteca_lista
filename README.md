# 📚 Biblioteca de Estruturas de Dados em C

Uma biblioteca educacional completa implementando **Listas Lineares**, **Filas** e **Pilhas** em C usando princípios de **Tipo Abstrato de Dados (TAD)** e **Polimorfismo através de ponteiros de função**.

## 🎯 Visão Geral

Este projeto fornece implementações robustas e reutilizáveis das três estruturas de dados fundamentais mais comuns em Ciência da Computação, com ênfase em:

- ✅ **Abstração de Dados**: Interface pública separada da implementação
- ✅ **Polimorfismo**: Suporte a qualquer tipo de dado via `void*` e callbacks
- ✅ **Reutilização**: Fila e Pilha construídas sobre Lista Linear
- ✅ **Modularização**: Uma função por arquivo, fácil manutenção
- ✅ **Educacional**: Ideal para aprender C, ponteiros e estruturas de dados

---

## 📐 Arquitetura da Biblioteca

### Estrutura de Diretórios

```
biblioteca_lista/
│
├── Biblioteca_Lista/                 ← Implementação de Lista Linear
│   ├── TAD_ListaLinear.h            ← Contrato público
│   ├── Lista.h                       ← Agregador de includes
│   ├── Utils.h                       ← Utilitários (aloca, libera, compara)
│   ├── ExemploListaInteiros.c        ← Exemplo de uso
│   │
│   └── Operacoes/                    ← Operações individuais
│       ├── 0_structs.h               ← Definições de tipos privados
│       ├── 1_criarLista.h
│       ├── 2_incluirInfo.h
│       ├── 3_excluirInfo.h
│       ├── 4_contemInfo.h
│       ├── 5_imprimirLista.h
│       ├── 6_destruirLista.h
│       ├── 7_duplicarLista.h
│       ├── 8_dividirLista.h
│       ├── 9_unirListas.h
│       ├── 10_interseccaoListas.h
│       ├── 11_disjuncaoListas.h
│       ├── 12_contidaListas.h
│       └── 13_inverterLista.h
│
└── Biblioteca_Fila_Pilha/            ← Implementação de Fila e Pilha
    ├── Fila.h                        ← Agregador Fila
    ├── Pilha.h                       ← Agregador Pilha
    ├── TAD_Fila.h                    ← Contrato público (Fila)
    ├── TAD_Pilha.h                   ← Contrato público (Pilha)
    ├── Utils.h                       ← Utilitários compartilhados
    ├── ExemploFilaInteiros.c
    ├── ExemploPilhaInteiros.c
    ├── ExemploLista_Fila_e_Pilha.c
    │
    ├── ListaLinear/                  ← Reutiliza Lista (composição)
    │   └── (mesma estrutura da Biblioteca_Lista)
    │
    ├── OperacoesFila/                ← Operações FIFO (7 operações)
    │   ├── 0_structs.h
    │   ├── 1_criarFila.h
    │   ├── 2_enfileirarInfo.h
    │   ├── 3_desenfileirarInfo.h
    │   ├── 4_filaVazia.h
    │   ├── 5_inverterFila.h
    │   ├── 6_copiarFila.h
    │   └── 7_trocaValores.h
    │
    └── OperacoesPilha/               ← Operações LIFO (9 operações)
        ├── 0_structs.h
        ├── 1_criarPilha.h
        ├── 2_empilharInfo.h
        ├── 3_desempilharInfo.h
        ├── 4_pilhaVazia.h
        ├── 5_pilhasIguais.h
        ├── 6_copiaPilha.h
        ├── 7_removeInfo.h
        ├── 8_interseccaoPilhas.h
        └── 9_limparPilha.h
```

### Relacionamento entre Módulos

```
┌─────────────────────────────────────────────────────┐
│                   CLIENTE (seu código)              │
└─────────────────────────────────────────────────────┘
           ↓                    ↓                    ↓
    ┌─────────────┐     ┌─────────────┐     ┌─────────────┐
    │  Lista.h    │     │   Fila.h    │     │   Pilha.h   │
    │ (público)   │     │ (público)   │     │ (público)   │
    └─────────────┘     └─────────────┘     └─────────────┘
           ↓                    ↓                    ↓
    ┌─────────────────────────────────────────────────────┐
    │   TAD_ListaLinear.h (Interface abstrata)            │
    └─────────────────────────────────────────────────────┘
           ↓
    ┌─────────────────────────────────────────────────────┐
    │       Operacoes/  (Implementação)                   │
    │   - 0_structs.h (tipos privados)                    │
    │   - 1_criarLista.h ... 13_inverterLista.h           │
    │       (uma função por arquivo)                      │
    └─────────────────────────────────────────────────────┘
           ↓
    ┌─────────────────────────────────────────────────────┐
    │         Utils.h (Utilitários genéricos)             │
    │   - alocaInt(), liberaInt(), comparaInt()           │
    │   - alocaData(), liberaData(), comparaData(), etc.  │
    └─────────────────────────────────────────────────────┘
```

---

## 📊 Estruturas de Dados Implementadas

### 1️⃣ Lista Linear (13 operações)

Uma **lista duplamente encadeada genérica** com suporte a qualquer tipo de dado.

#### Operações Disponíveis

| # | Operação | Descrição |
|---|----------|-----------|
| 1 | `criarLista()` | Inicializa lista vazia |
| 2 | `incluirInfoFim()` | Insere elemento no final |
| 2 | `incluirInfoInicio()` | Insere elemento no início |
| 2 | `incluirInfoMeio()` | Insere elemento na posição específica |
| 2 | `incluirInfoOrdenada()` | Insere mantendo ordem (usando comparação) |
| 3 | `excluirInfo()` | Remove primeiro elemento igual |
| 3 | `excluirInfoPos()` | Remove por posição |
| 4 | `contemInfo()` | Busca elemento |
| 5 | `imprimirLista()` | Exibe todos elementos |
| 6 | `destruirLista()` | Libera memória |
| 7 | `duplicarLista()` | Copia profunda |
| 8 | `dividirLista()` | Divide em duas no ponto especificado |
| 9 | `unirListas()` | União de dois conjuntos |
| 10 | `interseccaoListas()` | Elementos comuns |
| 11 | `disjuncaoListas()` | Verifica se disjuntas |
| 12 | `contidaListas()` | Verifica se uma está contida em outra |
| 13 | `inverterLista()` | Reverte ordem dos elementos |

#### Exemplo de Uso

```c
#include "Lista.h"

int main() {
    pDLista lista = criarLista();
    
    // Inserir elementos
    incluirInfoFim(lista, alocaInt(5));
    incluirInfoFim(lista, alocaInt(10));
    incluirInfoFim(lista, alocaInt(3));
    
    // Buscar
    if (contemInfo(lista, alocaInt(10), comparaInt)) {
        printf("Elemento encontrado!\n");
    }
    
    // Imprimir
    imprimirLista(lista, imprimeInt);
    
    // Duplicar
    pDLista copia = duplicarLista(lista, alocaInfoInt);
    
    // Liberar
    destruirLista(lista, liberaInt);
    destruirLista(copia, liberaInt);
    
    return 0;
}
```

---

### 2️⃣ Fila (7 operações)

Uma **fila FIFO** construída sobre Lista Linear com operações sincronizadas.

#### Operações Disponíveis

| # | Operação | Descrição | Padrão |
|---|----------|-----------|--------|
| 1 | `criarFila()` | Inicializa fila vazia | - |
| 2 | `enfileirarInfo()` | Adiciona no **final** | FIFO |
| 3 | `desenfileirarInfo()` | Remove do **início** | FIFO |
| 4 | `filaVazia()` | Verifica se vazia | - |
| 5 | `inverterFila()` | Reverte ordem | Utilitário |
| 6 | `copiarFila()` | Copia sem alterar original | Utilitário |
| 7 | `trocaValores()` | Troca dois elementos | Utilitário |

#### Exemplo de Uso

```c
#include "Fila.h"

int main() {
    pDFila fila = criarFila();
    
    // Enfileirar (adiciona no final)
    enfileirarInfo(fila, alocaInt(1));
    enfileirarInfo(fila, alocaInt(2));
    enfileirarInfo(fila, alocaInt(3));
    
    // Desenfileirar (remove do início - FIFO)
    void *primeiro = desenfileirarInfo(fila);  // Retorna 1
    void *segundo = desenfileirarInfo(fila);   // Retorna 2
    
    // Invertir (transforma em pilha)
    inverterFila(fila);
    
    // Liberar
    destruirFila(fila, liberaInt);
    
    return 0;
}
```

---

### 3️⃣ Pilha (9 operações)

Uma **pilha LIFO** construída sobre Lista Linear com operações especializadas.

#### Operações Disponíveis

| # | Operação | Descrição | Padrão |
|---|----------|-----------|--------|
| 1 | `criarPilha()` | Inicializa pilha vazia | - |
| 2 | `empilharInfo()` | Adiciona no **topo** | LIFO |
| 3 | `desempilharInfo()` | Remove do **topo** | LIFO |
| 4 | `pilhaVazia()` | Verifica se vazia | - |
| 5 | `pilhasIguais()` | Compara duas pilhas recursivamente | Comparação |
| 6 | `copiaPilha()` | Copia com alocação | Utilitário |
| 7 | `removeInfo()` | Remove elemento específico | Utilitário |
| 8 | `interseccaoPilhas()` | Elementos comuns em duas pilhas | Operação |
| 9 | `limparPilha()` | Libera todos elementos | Limpeza |

#### Exemplo de Uso

```c
#include "Pilha.h"

int main() {
    pDPilha pilha = criarPilha();
    
    // Empilhar (adiciona no topo)
    empilharInfo(pilha, alocaInt(1));
    empilharInfo(pilha, alocaInt(2));
    empilharInfo(pilha, alocaInt(3));
    
    // Desempilhar (remove do topo - LIFO)
    void *topo = desempilharInfo(pilha);  // Retorna 3
    topo = desempilharInfo(pilha);        // Retorna 2
    
    // Verificar igualdade com outra pilha
    pDPilha outraPilha = criarPilha();
    empilharInfo(outraPilha, alocaInt(1));
    
    if (pilhasIguais(pilha, outraPilha, comparaInt)) {
        printf("Pilhas iguais!\n");
    }
    
    // Liberar
    destruirPilha(pilha, liberaInt);
    destruirPilha(outraPilha, liberaInt);
    
    return 0;
}
```

---

## 🔧 Utilitários Genéricos (Utils.h)

A biblioteca fornece funções auxiliares para tipos comuns:

### Operações para Inteiros

```c
void* alocaInt(int valor)              // Aloca e retorna cópia
int comparaInt(void *a, void *b)       // Compara: a < b (-1), a > b (1), a == b (0)
void imprimeInt(void *info)            // Imprime valor inteiro
void liberaInt(void *info)             // Libera memória
```

### Operações para Strings

```c
void* alocaStr(char *valor)            // Aloca e duplica string
int comparaStr(void *a, void *b)       // Compara lexicograficamente
void imprimeStr(void *info)            // Imprime string
void liberaStr(void *info)             // Libera string
```

### Operações para Datas

```c
void* alocaData(struct tm *data)       // Aloca cópia de data
int comparaData(void *a, void *b)      // Compara datas cronologicamente
void imprimeData(void *info)           // Imprime formato DD/MM/YYYY
void liberaData(void *info)            // Libera data
```

---

## 🎨 Padrões de Design

### 1. Tipo Abstrato de Dados (TAD)

**Objetivo**: Separar interface da implementação

```c
// TAD_ListaLinear.h (CONTRATO PÚBLICO)
typedef struct descricaoLista *pDLista;
pDLista criarLista();
void incluirInfoFim(pDLista lista, void *info);
// ... mais operações

// Operacoes/0_structs.h (IMPLEMENTAÇÃO PRIVADA)
struct descricaoLista {
    struct noLista *inicio;
    struct noLista *fim;
    int quantidade;
};
```

**Benefício**: Usuário não precisa conhecer a estrutura interna.

---

### 2. Polimorfismo via Callbacks

**Objetivo**: Mesma estrutura para qualquer tipo de dado

```c
// Definições de tipo para callbacks
typedef int (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao)(void*);
typedef void* (*FuncaoAlocacao)(void*);
typedef void (*FuncaoLiberacao)(void*);

// Uso genérico
void imprimirLista(pDLista lista, FuncaoImpressao imprime) {
    // percorre lista e chama imprime(elemento)
}

// Aplicações específicas
imprimirLista(listaInteiros, imprimeInt);
imprimirLista(listaStrings, imprimeStr);
imprimirLista(listaDatas, imprimeData);
```

**Benefício**: Reusabilidade completa sem duplicação de código.

---

### 3. Composição (Fila e Pilha sobre Lista)

**Objetivo**: Reutilizar implementação de Lista com semântica diferente

```c
// Fila.h
struct descricaoFila {
    pDLista lista;  // Usa Lista internamente
};

// Fila.h - Operações
void enfileirarInfo(pDFila fila, void *info) {
    incluirInfoFim(fila->lista, info);  // Adiciona no fim
}

void* desenfileirarInfo(pDFila fila) {
    return excluirInfoPos(fila->lista, 1);  // Remove do início
}
```

**Benefício**: Evita duplicação; Fila e Pilha ganham todas operações de Lista automaticamente.

---

### 4. Modularização Extrema

**Objetivo**: Uma função por arquivo para máxima clareza

```
Operacoes/
├── 1_criarLista.h      ← Contém apenas criarLista()
├── 2_incluirInfo.h     ← Contém incluirInfoFim(), Inicio(), Meio(), Ordenada()
├── 3_excluirInfo.h     ← Contém excluirInfo()
└── ...
```

**Benefício**: Fácil localização, teste isolado, compreensão clara do escopo.

---

## 📖 Como Usar a Biblioteca

### Passo 1: Incluir Header Apropriado

```c
// Para usar Lista Linear
#include "Biblioteca_Lista/Lista.h"

// Para usar Fila
#include "Biblioteca_Fila_Pilha/Fila.h"

// Para usar Pilha
#include "Biblioteca_Fila_Pilha/Pilha.h"
```

### Passo 2: Compilar

```bash
# Compilar exemplo com Lista
gcc -o exemplo_lista Biblioteca_Lista/ExemploListaInteiros.c

# Compilar exemplo com Fila
gcc -o exemplo_fila Biblioteca_Fila_Pilha/ExemploFilaInteiros.c

# Compilar exemplo combinado
gcc -o exemplo_combinado Biblioteca_Fila_Pilha/ExemploLista_Fila_e_Pilha.c
```

### Passo 3: Executar

```bash
./exemplo_lista
./exemplo_fila
./exemplo_combinado
```

---

## 💡 Exemplos Práticos

### Exemplo 1: Busca em Lista

```c
#include "Lista.h"

int main() {
    pDLista lista = criarLista();
    
    // Preencher lista
    for (int i = 1; i <= 5; i++) {
        incluirInfoFim(lista, alocaInt(i * 10));
    }
    
    // Buscar
    int *busca = malloc(sizeof(int));
    *busca = 30;
    
    if (contemInfo(lista, busca, comparaInt)) {
        printf("Encontrou 30 na lista!\n");
    }
    
    imprimirLista(lista, imprimeInt);
    destruirLista(lista, liberaInt);
    
    return 0;
}
```

### Exemplo 2: Simular Fila de Atendimento

```c
#include "Fila.h"

int main() {
    pDFila fila = criarFila();
    
    // Clientes chegando
    for (int i = 1; i <= 5; i++) {
        enfileirarInfo(fila, alocaInt(i));
        printf("Cliente %d entrou na fila\n", i);
    }
    
    // Atender clientes (FIFO)
    while (!filaVazia(fila)) {
        void *cliente = desenfileirarInfo(fila);
        printf("Atendendo cliente %d\n", *(int*)cliente);
        liberaInt(cliente);
    }
    
    destruirFila(fila, liberaInt);
    return 0;
}
```

### Exemplo 3: Pilha para Inverter Sequência

```c
#include "Pilha.h"

int main() {
    pDPilha pilha = criarPilha();
    
    // Empilhar números
    for (int i = 1; i <= 5; i++) {
        empilharInfo(pilha, alocaInt(i));
    }
    
    printf("Números empilhados: 1, 2, 3, 4, 5\n");
    printf("Desempilhando (ordem inversa): ");
    
    while (!pilhaVazia(pilha)) {
        void *numero = desempilharInfo(pilha);
        printf("%d ", *(int*)numero);
        liberaInt(numero);
    }
    printf("\n");
    
    destruirPilha(pilha, liberaInt);
    return 0;
}
```

### Exemplo 4: Operações de Conjunto com Listas

```c
#include "Lista.h"

int main() {
    // Criar dois conjuntos
    pDLista lista1 = criarLista();
    pDLista lista2 = criarLista();
    
    // Lista 1: {1, 2, 3, 4}
    for (int i = 1; i <= 4; i++) {
        incluirInfoFim(lista1, alocaInt(i));
    }
    
    // Lista 2: {3, 4, 5, 6}
    for (int i = 3; i <= 6; i++) {
        incluirInfoFim(lista2, alocaInt(i));
    }
    
    printf("Lista 1: "); imprimirLista(lista1, imprimeInt);
    printf("Lista 2: "); imprimirLista(lista2, imprimeInt);
    
    // União: {1, 2, 3, 4, 5, 6}
    pDLista uniao = criarLista();
    unirListas(uniao, lista1, comparaInt);
    unirListas(uniao, lista2, comparaInt);
    printf("União: "); imprimirLista(uniao, imprimeInt);
    
    // Interseção: {3, 4}
    pDLista intersecao = interseccaoListas(lista1, lista2, comparaInt);
    printf("Interseção: "); imprimirLista(intersecao, imprimeInt);
    
    destruirLista(lista1, liberaInt);
    destruirLista(lista2, liberaInt);
    destruirLista(uniao, liberaInt);
    destruirLista(intersecao, liberaInt);
    
    return 0;
}
```

---

## 🎓 Conceitos Educacionais Cobertos

A biblioteca demonstra:

| Conceito | Exemplo |
|----------|---------|
| **Alocação Dinâmica** | `malloc()` em `alocaInt()`, `alocaStr()` |
| **Ponteiros** | `void*` para genéricos, `struct noLista *` |
| **Ponteiros de Função** | `FuncaoComparacao`, `FuncaoImpressao` |
| **Structs e Encapsulamento** | `struct descricaoLista` privada em TAD |
| **Listas Ligadas** | `struct noLista { void *info, *prox }` |
| **Recursão** | `pilhasIguais()` compara recursivamente |
| **Busca e Ordenação** | `contemInfo()`, `incluirInfoOrdenada()` |
| **Operações de Conjunto** | União, interseção, disjunção |
| **Padrões de Design** | TAD, Strategy, Composition |

---

## ✨ Características Principais

| Característica | Descrição |
|---|---|
| **Genérico** | Suporta qualquer tipo de dado via `void*` e callbacks |
| **Bem Organizado** | Uma função por arquivo, estrutura clara |
| **Reusável** | Fila e Pilha reutilizam implementação de Lista |
| **Educacional** | Código limpo, comentado, com exemplos |
| **Sem Dependências** | Apenas C puro, sem bibliotecas externas |
| **Modular** | Importe apenas o que precisa |
| **Type Safe** | Abstração clara com `typedef` para ponteiros |

---

## 📋 Checklist de Qualidade

- ✅ Abstração de Dados bem definida
- ✅ Interface pública separada da implementação
- ✅ Polimorfismo via callbacks
- ✅ Reusabilidade através de composição
- ✅ Modularização extrema
- ✅ Exemplos práticos funcionais
- ✅ Gerenciamento de memória
- ✅ Suporte a múltiplos tipos de dados
- ✅ Operações avançadas (intersecção, união, etc)
- ✅ Documentação clara

---

## 🚀 Sugestões de Extensão

Possíveis melhorias:

1. **Adicionar mais tipos utilitários**: Floats, estruturas customizadas
2. **Implementar iteradores**: Para navegação customizada
3. **Adicionar tratamento de erros**: Retornos de status
4. **Criar testes unitários**: Validar cada operação
5. **Adicionar persistência**: Salvar/carregar em arquivo
6. **Documentação Doxygen**: Comentários padronizados
7. **Performance**: Análise de complexidade
8. **Thread-safety**: Para ambientes multi-thread

---

## 📝 Autor & Licença

Projeto educacional de estruturas de dados em C.

Perfeito para estudantes, professores e desenvolvedores aprendendo C avançado! 🎓

---

**Status**: ✅ Completo e funcional
**Última atualização**: Junho 2026
