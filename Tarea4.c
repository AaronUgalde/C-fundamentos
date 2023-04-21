#include <stdio.h>

int main() {

    int desicion;

    printf("Si quieres saber cuantos dias tiene un mes presiona 1, si quieres saber que mes tiene cierta cantidad de dias presiona 2: ");
    scanf("%i", &desicion);

    if(desicion != 1 && desicion != 2){
        
        printf("%i", desicion);
        printf("Ingresa un numero valido");

    }else if(desicion == 1){

        int mes;
        printf("Ingresa el mes del que quieres saber su numero de dias: ");
        scanf("%i", &mes);
        if(!(mes >= 1 && mes <= 12)){

            printf("ingresa un mes valido");

        }else if(mes == 1 || mes == 3 || mes == 5 || mes == 7|| mes == 8 || mes == 10 || mes == 12){

            printf("Este mes tiene 31 dias");

        }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

            printf("Este mes tiene 30 dias");

        }else if(mes == 2){

            printf("Este mes tiene 28 o 29 dias si es año bisiesto");

        }

    }else if(desicion == 2){
        
        int dias;
        printf("Ingrese la cantidad de dias para saber que meses tienen estos dias: ");
        scanf("%i", &dias);

        if(!(dias >= 28 && dias <= 31)){

            printf("ingrese un numero de dias valido");

        }else if(dias == 28){

            printf("Febrero tiene 28 dias si no es dia bisiesto");

        }else if(dias == 29){

            printf("Febrero tiene 29 dias si es bisiesto");

        }else if(dias == 30){

            printf("Abril, Junio, Septiembre, Noviembre");

        }else if(dias == 31){

            printf("Enero, Marzo, Mayo, Julio, Agosto, Octubre, Diciembre");

        }

    }

    return 0;

}