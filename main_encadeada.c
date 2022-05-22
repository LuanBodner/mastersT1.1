#include <stdio.h>

#include "pilha_encadeada.h"

void teste_empilhar_10k_encadeada() {
    Pilha* p = pilha_criar_encadeada();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 10000; i++) pilha_empilhar_encadeada(p, newElement);
    for (int i = 0; i < 10000; i++) pilha_desempilhar_encadeada(p, &oldElement);

    pilha_destruir_encadeada(p);
}

void teste_empilhar_100k_encadeada() {
    Pilha* p = pilha_criar_encadeada();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 100000; i++) pilha_empilhar_encadeada(p, newElement);
    for (int i = 0; i < 100000; i++)
        pilha_desempilhar_encadeada(p, &oldElement);

    pilha_destruir_encadeada(p);
}

void teste_empilhar_1m_encadeada() {
    Pilha* p = pilha_criar_encadeada();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 1000000; i++) pilha_empilhar_encadeada(p, newElement);
    for (int i = 0; i < 1000000; i++)
        pilha_desempilhar_encadeada(p, &oldElement);

    pilha_destruir_encadeada(p);
}

void teste_empilhar_10m_encadeada() {
    Pilha* p = pilha_criar_encadeada();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 10000000; i++) pilha_empilhar_encadeada(p, newElement);
    for (int i = 0; i < 10000000; i++)
        pilha_desempilhar_encadeada(p, &oldElement);

    pilha_destruir_encadeada(p);
}

int main() {
    teste_empilhar_10m_encadeada();
    return 1;
}