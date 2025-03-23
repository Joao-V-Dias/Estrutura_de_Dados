//Crie uma função que receba por parâmetro um vetor de números inteiros, o tamanho do vetor e os endereços de duas variáveis inteiras (que podemos chamar de min e max).
//Ao passar essas variáveis para a função seu programa deverá analisar qual é o maior e o menor elemento do vetor e depositar esses elementos nas variáveis do parâmetro.

#include<stdio.h>

void calcular(int array[], int tamanho, int *maior, int *menor){
    *maior = array[0];
    *menor = array[0];
    for(int i = 1 ; i < tamanho ; i++){
    	if (*maior < array[i]) *maior = array[i];
        if (*menor > array[i]) *menor = array[i];
    }
}

int main(){
    int tamanho, maior, menor;
    scanf("%d", &tamanho);

    int array[tamanho];
    for(int i = 0 ; i < tamanho ; i++){
        scanf("%d", &array[i]);
    }

    calcular(array, tamanho, &maior, &menor);
    printf("%d %d", menor, maior);

    return 0;
}
