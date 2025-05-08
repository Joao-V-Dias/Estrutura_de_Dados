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
   // implementar aqui
}

void insere_Pilha(Pilha* pi, int num){
    pi->topo++;
    pi->dados[pi->topo] = num;
}

int remove_Pilha(Pilha* pi){
    int elemento;
    elemento = pi->dados[pi->topo];
    pi->topo--;
    return elemento;
}

int tamanho_Pilha(Pilha* pi){
    return pi->topo + 1;
}

int pilha_cheia(Pilha* pi){
    // implementar aqui
}

int pilha_vazia(Pilha* pi){
   // implementar aqui
}

void imprime_Pilha(Pilha* pi){
    // implementar aqui
}
