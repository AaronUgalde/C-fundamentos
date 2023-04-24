#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int toBase10 (char *numero, int baseActual, int tamaño);

int main(){

    //Declarar las variables
    char numero1I[100];
    char *numero1= (char*)malloc(sizeof(char));
    int base1;
    char numero2I[100];
    char *numero2= (char*)malloc(sizeof(char));
    int base2;
    int baseSuma;

    //Verficar que se asgino bien la memoria
    if(numero1 == NULL || numero2 == NULL){
        printf("Error al asignar memoria");
        return 1;
    }

    //Escaneo de datos
    printf("ingrese el primer numero y la base de este: ");
    scanf("%s%i",&numero1I,&base1);
    printf("ingrese el segundo numero y la base de este: ");
    scanf("%s%i",&numero2I,&base2);
    printf("ingrese en que base quiere la suma: ");
    scanf("%i",&baseSuma);

    //reasignacion de tamaño de memoria y copiar str
    numero1 = (char*)realloc(numero1, strlen(numero1I)*sizeof(char));
    numero2 = (char*)realloc(numero2, strlen(numero2I)*sizeof(char));
    strcpy(numero1,numero1I);
    strcpy(numero2,numero2I);

    printf("%s, %i, %s, %i, %i\n",numero1,base1,numero2,base2,baseSuma);

    printf("el numero en base 10 es: %i\n", toBase10(numero1,base1,strlen(numero1)));

    free(numero1);
    free(numero2);
return 0;}

//convertir a base 10
int toBase10 (char *numero, int baseActual, int tamaño){
    int nBase10;
    for(int i=tamaño-1;i>=0;i--){
        printf("a%i\n", tamaño);
        printf("b%i\n",i);
        char n = numero[i];
        printf("aqui: %c\n",n);
        int cifraSignificativa = pow(baseActual,tamaño-i-1);
        printf("cifra significativa: %i\n",cifraSignificativa);
        if(n >= 'A'){
            if(n=='a'){
                nBase10 += 10*cifraSignificativa;
            }
            if(n=='b'){
                nBase10 += 11*cifraSignificativa;
            }
            if(n=='c'){
                nBase10 += 12*cifraSignificativa;
            }
            if(n=='d'){
                nBase10 += 13*cifraSignificativa;
            }
            if(n=='e'){
                nBase10 += 14*cifraSignificativa;
            }
            if(n=='f'){
                nBase10 += 15*cifraSignificativa;
            }
        }else{
            nBase10 += (n-48)*cifraSignificativa;
        }
        printf("nbase10: %i\n",nBase10);
    }
return nBase10;}