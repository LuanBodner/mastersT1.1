#include "pilha_contigua.h"

#define TAM_INICIAL 5
struct _pilha {
    TipoElemento* vetor;
    int tamVetor;
    int qtdeElementos;
};

void verifica_aumenta_contigua(Pilha* p) {
    if (p->qtdeElementos < p->tamVetor) return;

    int novoTamanho = p->tamVetor * 2;
    TipoElemento* vetorAuxiliar =
        (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for (i = 0; i < p->qtdeElementos; i++) vetorAuxiliar[i] = p->vetor[i];
    free(p->vetor);
    p->vetor = vetorAuxiliar;
    p->tamVetor = novoTamanho;
}

void verifica_reduz_contigua(Pilha* p) {
    int livre = p->tamVetor - p->qtdeElementos;
    if (livre < (p->tamVetor / 2) || p->tamVetor == TAM_INICIAL) return;

    int novoTamanho = p->tamVetor / 2;
    TipoElemento* vetorAuxiliar =
        (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for (i = 0; i < p->qtdeElementos; i++) vetorAuxiliar[i] = p->vetor[i];
    free(p->vetor);
    p->vetor = vetorAuxiliar;
    p->tamVetor = novoTamanho;
}

bool pilha_ehValida_contigua(Pilha* p) { return (p != NULL ? true : false); }

Pilha* pilha_criar_contigua() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->vetor = (TipoElemento*)calloc(TAM_INICIAL, sizeof(TipoElemento));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;
    return p;
}

void pilha_destruir_contigua(Pilha** endPilha) {
    if (!pilha_ehValida_contigua(*endPilha)) return;

    free((*endPilha)->vetor);
    free(*endPilha);
    *endPilha = NULL;
}

bool pilha_empilhar_contigua(Pilha* p, TipoElemento elemento) {
    if (!pilha_ehValida_contigua(p)) return false;
    verifica_aumenta_contigua(p);

    p->vetor[p->qtdeElementos++] = elemento;
    return true;
}

bool pilha_desempilhar_contigua(Pilha* p, TipoElemento* saida) {
    if (!pilha_ehValida_contigua(p)) return false;
    if (pilha_vazia_contigua(p)) return false;

    *saida = p->vetor[--p->qtdeElementos];

    verifica_reduz_contigua(p);

    return true;
}

bool pilha_topo_contigua(Pilha* p, TipoElemento* saida) {
    if (!pilha_ehValida_contigua(p)) return false;
    if (pilha_vazia_contigua(p)) return false;

    *saida = p->vetor[p->qtdeElementos - 1];
    return true;
}

bool pilha_vazia_contigua(Pilha* p) {
    if (!pilha_ehValida_contigua(p)) return false;

    return (p->qtdeElementos == 0 ? true : false);
}

void pilha_imprimir_contigua(Pilha* p, void (*printElemento)(void*)) {
    if (!pilha_ehValida_contigua(p)) return;

    printf("Contígua");
    printf("[");
    int i;
    for (i = p->qtdeElementos - 1; i >= 0; i--) {
        printElemento(&p->vetor[i]);
        if (i >= 1) printf(", ");
    }
    printf("]");
}

int pilha_tamanho_contigua(Pilha* p) {
    if (!pilha_ehValida_contigua(p)) return false;

    return p->qtdeElementos;
}

bool pilha_empilharTodos_contigua(Pilha* p, TipoElemento* vetor, int tamVetor) {
    if (!pilha_ehValida_contigua(p)) return false;

    int i;
    for (i = 0; i < tamVetor; i++) {
        pilha_empilhar_contigua(p, vetor[i]);
    }
    return true;
}
