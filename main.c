#include <stdio.h>

#include "pilha.h"

/**
 * EMPILHAR
 * RESULTADO ESPERADO (Topo -> Base)
 * [30,20,10]
 */
void teste_empilhar() {
    printf(">>> TESTE EMPILHAR\n");
    Pilha* p = pilha_criar();
    TipoElemento newElement = {
        name : "Testerson"
    }

    for (int i = 0; i < 10000; i++) {
        pilha_empilhar(p, newElement);
    }

    pilha_imprimir(p);
    printf("\n");
    pilha_destruir(p);
}

int main() {
    teste_empilhar();
    return;
}