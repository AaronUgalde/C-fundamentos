#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //Declarar las variables
    char *numero1=NULL;
    int base1;
    char *numero2=NULL;
    int base2;
    int baseSuma;
    
    //Escaneo de datos
    printf("ingrese el primer numero y la base de este: ");
    scanf("%s%i",&numero1,&base1);
    printf("ingrese el segundo numero y la base de este: ");
    scanf("%s%i",&numero2,&base2);
    printf("ingrese en que base quiere la suma: ");
    scanf("%i",&baseSuma);
    printf("%s, %i, %s, %i, %i",numero1,base1,numero2,base2,baseSuma);

    for(int i=0; i)

return 0;}