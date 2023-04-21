#include <stdio.h>

#define PI 3.141592


int main() {

    float r,a;

    printf("Ingrese el radio de la esfera: "),
    scanf("%f", &r);

    a = 4*PI*r*r;

    printf("El area es %.2f", a);

    return 0;

}