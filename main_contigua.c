#include <stdio.h>

#include "pilha_contigua.h"

void teste_empilhar_10k_contigua() {
    Pilha* p = pilha_criar_contigua();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 10000; i++) pilha_empilhar_contigua(p, newElement);
    for (int i = 0; i < 10000; i++) pilha_desempilhar_contigua(p, &oldElement);

    pilha_destruir_contigua(&p);
}

void teste_empilhar_100k_contigua() {
    Pilha* p = pilha_criar_contigua();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 100000; i++) pilha_empilhar_contigua(p, newElement);
    for (int i = 0; i < 100000; i++) pilha_desempilhar_contigua(p, &oldElement);

    pilha_destruir_contigua(&p);
}

void teste_empilhar_1m_contigua() {
    Pilha* p = pilha_criar_contigua();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 1000000; i++) pilha_empilhar_contigua(p, newElement);
    for (int i = 0; i < 1000000; i++)
        pilha_desempilhar_contigua(p, &oldElement);

    pilha_destruir_contigua(&p);
}

void teste_empilhar_10m_contigua() {
    Pilha* p = pilha_criar_contigua();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 10000000; i++) pilha_empilhar_contigua(p, newElement);
    for (int i = 0; i < 10000000; i++)
        pilha_desempilhar_contigua(p, &oldElement);

    pilha_destruir_contigua(&p);
}

int main() {
    teste_empilhar_10m_contigua();
    return 0;
}