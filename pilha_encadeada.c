#include "pilha_encadeada.h"

typedef struct no {
    TipoElemento dado;
    struct no* prox;
} No;

struct _pilha {
    No* topo;
    int qtdeElementos;
};

bool pilha_ehValida_encadeada(Pilha* p) { return (p != NULL ? true : false); }

No* criar_no(TipoElemento elemento, No* proximoNo) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = elemento;
    no->prox = proximoNo;
    return no;
}

Pilha* pilha_criar_encadeada() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtdeElementos = 0;
    return p;
}

void pilha_destruir_encadeada(Pilha* p) {
    if (!pilha_ehValida_encadeada(p)) return;

    No* aux;
    while (p->topo != NULL) {
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }

    free(p);
}

bool pilha_empilhar_encadeada(Pilha* p, TipoElemento elemento) {
    if (!pilha_ehValida_encadeada(p)) return false;

    No* novo = criar_no(elemento, NULL);
    novo->prox = p->topo;
    p->topo = novo;
    p->qtdeElementos++;
    return true;
}

bool pilha_desempilhar_encadeada(Pilha* p, TipoElemento* saida) {
    if (!pilha_ehValida_encadeada(p)) return false;
    if (pilha_vazia_encadeada(p)) return false;

    No* noRemovido = p->topo;
    p->topo = p->topo->prox;
    noRemovido->prox = NULL;
    p->qtdeElementos--;
    *saida = noRemovido->dado;
    free(noRemovido);

    return true;
}

bool pilha_topo_encadeada(Pilha* p, TipoElemento* saida) {
    if (!pilha_ehValida_encadeada(p)) return false;
    if (pilha_vazia_encadeada(p)) return false;

    *saida = p->topo->dado;
    return true;
}

bool pilha_vazia_encadeada(Pilha* p) {
    return (p->qtdeElementos == 0 ? true : false);
}

void pilha_imprimir(Pilha* p) {
    if (!pilha_ehValida_encadeada(p)) return;

    printf("Encadeada");
    printf("[");
    No* aux = p->topo;
    while (aux != NULL) {
        printf("%s", aux->dado.name);
        if (aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

int pilha_tamanho_encadeada(Pilha* p) { return p->qtdeElementos; }
