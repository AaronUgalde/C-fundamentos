#include <stdio.h>

#define PI 3.141592


int main() {

    float r,a;

    printf("Ingrese el radio del circulo: "),
    scanf("%f", &r);

    a = PI*r*r;

    printf("El area es %.2f", a);

    return 0;

}