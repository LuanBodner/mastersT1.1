#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
    int id;
    char name[255];
    float salary;
    int status;
    char address[255];
} TipoElemento;

typedef struct _pilha Pilha;

Pilha* pilha_criar_encadeada();
void pilha_destruir_encadeada(Pilha* p);
bool pilha_empilhar_encadeada(Pilha* p, TipoElemento elemento);
bool pilha_desempilhar_encadeada(Pilha* p, TipoElemento* saida);
bool pilha_vazia_encadeada(Pilha* p);
void pilha_destruir_encadeada(Pilha* p);