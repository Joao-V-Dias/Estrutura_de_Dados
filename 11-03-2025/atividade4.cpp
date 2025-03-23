//Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R.
//A area da superfície e o volume são dados, respectivamente, por:

//A = 4 * p * R^2
//V = 4/3 * p * R^3

#include<stdio.h>
#include<math.h>
#define PI 3.14

void calcular(double raio, double *area, double *volume){
    *area = 4.0 * PI * pow(raio, 2);
    *volume = (4.0/3.0) * PI * pow(raio, 3);
}

int main(){

    double area, volume, raio, perimetro;

    scanf("%lf", &raio);

    calcular(raio, &area, &volume);

    printf("%.2f %.2f", area, volume);

    return 0;
}
