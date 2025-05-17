#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h" //inclui os Prot�tipos

//Definicao do tipo Pilha
struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *p;
	p = (Pilha*) malloc(sizeOf(Pilha));
	if(!p)exit(1);
	p->qtd = 0;
	return p;
}

void libera_Pilha(Pilha* pi){
	free(pi);
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
	return 0; // Terminar depois
}

int insere_Pilha(Pilha* pi, struct aluno al){
	if(pi == NULL) return 0;
	if(pi->qtd == MAX) return 0;
	pi->dados = al;
	pi->qtd++;
	return 1;
}

int remove_Pilha(Pilha* pi) {
	if (pi == NULL || pi->qtd == 0) return 0;
	pi->qtd--;
	return 1;
}

int tamanho_Pilha(Pilha* pi) {
	if (pi == NULL) return 0;
	return pi->qtd;
}

int pilha_vazia(Pilha* pi) {
	if (pi == NULL) return -1;
	if (pi->qtd == 0 ) return 1;
	return 0;
}

int pilha_cheia(Pilha* pi) {
	if (pi == NULL) return -1;
	if (pi->qtd == MAX) return 1;
	return 0;
}

void imprime_Pilha(Pilha* pi) {
	if (pi == NULL || pi->qtd == 0) return;
	for (int i = pi->qtd-1; i >= 0; i--) {
		printf("Aluno %d: %c\n", i, pi->dados[i].nome);
	}
	printf("_________________________________________\n");
}