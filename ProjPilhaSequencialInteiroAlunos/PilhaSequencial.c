#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h" //inclui os Protótipos

//Definição do tipo Pilha
struct pilha{
    int topo;
    int dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *p;
   p = (Pilha*) malloc(sizeof(Pilha));
   if(!p)exit(1);
   p->topo = -1;
    return p;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int consulta_topo_Pilha(Pilha* pi, int *num){
    if(pi == NULL) return 0;
    if(pilha_vazia(pi)) return 0;
    *num = pi->dados[pi->topo - 1];
    return 1;
}

void insere_Pilha(Pilha* pi, int num){
    pi->topo++;
    pi->dados[pi->topo] = num;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL) return 0;
    if(pi->topo == 0) return 0;
    int elemento;
    elemento = pi->dados[pi->topo];
    pi->topo--;
    return elemento;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL) return 0;
    return pi->topo;
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL) return -1;
    if(pi->topo == MAX) return 1;
    return 0;
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL) return -1;
    if(pi->topo == 0) return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL) return 0;
    int i;
    for(i = pi->topo-1; i >= 0 ; i--){
        printf("Pos %d: %d\n", i, pi->dados[i]);
    }
    printf("---------------------------");
}
