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

Pilha* pilha_criar_contigua();
void pilha_destruir_contigua(Pilha** endPilha);
bool pilha_empilhar_contigua(Pilha* p, TipoElemento elemento);
bool pilha_desempilhar_contigua(Pilha* p, TipoElemento* saida);
bool pilha_vazia_contigua(Pilha* p);