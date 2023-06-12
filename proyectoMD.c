#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int toInt(char c);
void toCadena(int *arrEnBaseDestino, char *cadena, int tamaño);
void toAnyBase2 (char *numero, int baseActual, int baseDestino, char *cadena);
void sumaEnBaseDestino(char *numero1, char *numero2, int baseDestino, char *sumaFinal);

int main(){

    //Resultado
    char sumaFinal[100];

    //Declarar las variables
    char numero1[100];
    int base1;
    char numero2[100];
    int base2;
    int baseSuma;

    //array con la cadena final
    char numeroFinal1[100];
    char numeroFinal2[100];

    //Escaneo de datos
    printf("ingrese el primer numero y la base de este: ");
    scanf("%s%i",numero1,&base1);
    printf("ingrese el segundo numero y la base de este: ");
    scanf("%s%i",numero2,&base2);
    printf("ingrese en que base quiere la suma: ");
    scanf("%i",&baseSuma);

    toAnyBase2(numero1, base1, baseSuma, numeroFinal1);
    toAnyBase2(numero2, base2, baseSuma, numeroFinal2);

    printf("\nnumero 1: %s = %s, numero 2: %s = %s", numero1, numeroFinal1, numero2, numeroFinal2);

    sumaEnBaseDestino(numeroFinal1, numeroFinal2, baseSuma, sumaFinal);
    printf("\n suma: %s", sumaFinal);

return 0;}

//Pasar de un char a un int
int toInt(char c){
    if((c >= '0') && (c <= '9')){
        return (c-'0');
    }else if((c >= 'a')&&(c <= 'f')){
        return (c-'a'+10);
    }else{
        return 0;
    }
}

//suma
void sumaEnBaseDestino(char *numero1, char *numero2, int baseDestino, char *sumaFinal){

    int arrayInts[100];
    int acarreo = 0;
    int tamañoNumero1 = strlen(numero1);
    int tamañoNumero2 = strlen(numero2);
    int tamañoMayor;

    if(tamañoNumero1 > tamañoNumero2){
        tamañoMayor = tamañoNumero1;
    }else{
        tamañoMayor = tamañoNumero2;
    }

    for(int i=0;i<tamañoMayor;i++){
        char c1 = numero1[tamañoNumero1-1-i];
        char c2 = numero2[tamañoNumero2-1-i];
        int ic1 = toInt(c1);
        int ic2 = toInt(c2);
        int suma = ic1+ic2+acarreo;
        int residuo = suma%baseDestino;
        acarreo = suma/baseDestino;
        arrayInts[i] = residuo;
    }

    if(acarreo!=0){
        arrayInts[tamañoMayor]=acarreo;
        tamañoMayor++;
    }

    toCadena(arrayInts, sumaFinal, tamañoMayor-1);
}

//Convertir de arreglo de int a cadena
void toCadena(int *arrEnBaseDestino, char *cadena, int tamaño){
    for(int i=0; i<=tamaño; i++){
        if(arrEnBaseDestino[tamaño-i] >= 10){
            cadena[i] = arrEnBaseDestino[tamaño-i] + ('a'-10);
        }else{
            cadena[i] = arrEnBaseDestino[tamaño-i] + '0';
        }
    }
    cadena[tamaño+1] = '\0';
}

void toAnyBase2 (char *numero, int baseActual, int baseDestino, char *cadena){
    
    int tamañoDeNIni = strlen(numero);

    //Validacion
    if(baseActual >= 2 && baseActual <= 16 && baseDestino >= 2 && baseDestino <= 16){
        for(int i=tamañoDeNIni-1;i>=0;i--){
            char n = numero[i];
            if(!(((n >= '0' && n <= '9') || (n >= 'a' && n <= 'f')) && ((baseActual > 10 && n < baseActual-10+'a')  || (n < baseActual+'0')))){
                printf("\ninserte valores validos");
                exit(-1);
            }
        }
    }else{
        printf("\ninserte una base valida");
        exit(-1);
    }

    //Convertimos a base 10
    int nBase10 = 0;
    for(int i=tamañoDeNIni-1;i>=0;i--){
        char n = numero[i];
        int cifraSignificativa = pow(baseActual,tamañoDeNIni-i-1);
        if(n >= 'A'){
            nBase10 += (n-'a'+10)*cifraSignificativa;
        }else{
            nBase10 += (n-48)*cifraSignificativa;
        }
    }

    //Convertimos a la base deseada pero dentro de un arreglo de enteros
    int arrEnBaseDestino[500];
    int cociente = nBase10;
    int tamaño;

    for(tamaño=0;tamaño<100;tamaño++){
        if(cociente<baseDestino){
            arrEnBaseDestino[tamaño] = cociente;
            break;
        }else{
            arrEnBaseDestino[tamaño] = cociente%baseDestino;
            cociente = cociente/baseDestino;
        }
    }

    //Convertimos a una cadena el array de enteros
    toCadena(arrEnBaseDestino, cadena, tamaño);
}