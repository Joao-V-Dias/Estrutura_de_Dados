//Escreva um programa que contenha duas variaveis inteiras. Leia essas variáveis do teclado.
//Em seguida, compare seus endereços e exiba o conteudo do maior endereço.

#include<stdio.h>

int main(){
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    if(&num1 > &num2){
        printf("%d", num1);
        return 0;
    }
    printf("%d", num2);
    return 0;
}
