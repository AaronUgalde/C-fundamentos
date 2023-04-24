#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int toBase10 (char numero[], int baseActual);
int toAnyBase (int numero, int baseDestino, int *arrEnBaseDestino);
void toCadena(int *arrEnBaseDestino, char *cadena, int tamaño);

int main(){

    //Declarar las variables
    char numero1[100];
    int base1;
    char numero2[100];
    int base2;
    int baseSuma;

    //array donde estara ya convertido a la base deseada pero faltaria poner los numeros >= a 10 y <= 15 a base 16
    int arrEnBaseDestino[100];
    //array con la cadena final
    char numeroFinal[100];
    int tamañoFinal;

    //Escaneo de datos
    printf("ingrese el primer numero y la base de este: ");
    scanf("%s%i",numero1,&base1);
    printf("ingrese el segundo numero y la base de este: ");
    scanf("%s%i",numero2,&base2);
    printf("ingrese en que base quiere la suma: ");
    scanf("%i",&baseSuma);

    int sumaEnBase10 = toBase10(numero1,base1) + toBase10(numero2,base2);

    tamañoFinal = toAnyBase(123456789,baseSuma,arrEnBaseDestino);
    printf("tamaño: %i\n", tamañoFinal);

    for(int i=0;i<100;i++){
        printf("%i: %i\n",i,arrEnBaseDestino[i]);
    }

    toCadena(arrEnBaseDestino,numeroFinal,tamañoFinal);

    printf("cadena final: %s\n", numeroFinal);

return 0;}

//convertir a base 10
int toBase10 (char numero[], int baseActual){
    int nBase10;
    int tamaño = strlen(numero);
    for(int i=tamaño-1;i>=0;i--){
        char n = numero[i];
        int cifraSignificativa = pow(baseActual,tamaño-i-1);
        if(n >= 'A'){
            nBase10 += (n-'a'+10)*cifraSignificativa;
        }else{
            nBase10 += (n-48)*cifraSignificativa;
        }
    }
return nBase10;}

//convertir a la base deseada
int toAnyBase (int numero, int baseDestino, int *arrEnBaseDestino){
    
    int cociente = numero;
    int i;

    for(i=0;i<100;i++){
        printf("%i\n",i);
        if(cociente<baseDestino){
            arrEnBaseDestino[i] = cociente;
            break;
        }else{
            arrEnBaseDestino[i] = cociente%baseDestino;
            cociente = cociente/baseDestino;
        }
    }
return i;}

//Convertir de arreglo de int a cadena
void toCadena(int *arrEnBaseDestino, char *cadena, int tamaño){
    for(int i=0; i<=tamaño; i++){
        if(arrEnBaseDestino[tamaño-i] >= 10){
            cadena[i] = arrEnBaseDestino[tamaño-i] + ('a'-10);
            printf("char en %i es: %c",i, arrEnBaseDestino[tamaño-i] + ('a'-10));
        }else{
            cadena[i] = arrEnBaseDestino[tamaño-i] + '0';
        }
    }
    arrEnBaseDestino[tamaño+1] = '\0';
}