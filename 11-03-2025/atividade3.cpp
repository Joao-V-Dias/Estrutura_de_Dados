//Escreva uma função que dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionária deste número.
//Escreva um programa que chama esta função.

#include<stdio.h>

void calcular(double num, int *inteiro, double *fracao){
    *inteiro = (int)num;
    *fracao = num - (int)num;
}

int main(){

    int inteiro;
    double fracao, num;

    scanf("%lf", &num);

    calcular(num, &inteiro, &fracao);

    printf("%d %.2f", inteiro, fracao);

    return 0;
}
