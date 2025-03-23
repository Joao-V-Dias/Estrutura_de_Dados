//Escreva uma fun��o que dado um n�mero real passado como par�metro, retorne a parte inteira e a parte fracion�ria deste n�mero.
//Escreva um programa que chama esta fun��o.

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
