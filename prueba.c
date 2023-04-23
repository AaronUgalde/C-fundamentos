#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int *arr = (int*)malloc(n * sizeof(int)); // Se reserva memoria para el arreglo

    if(arr == NULL) { // Verificación de errores al asignar memoria
        printf("Error al asignar memoria.");
        return 1;
    }

    // Inicializar el arreglo
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Imprimir el arreglo original
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Cambiar la memoria asignada y agregar un nuevo dato
    n++; // Incrementar el tamaño del arreglo
    arr = (int*)realloc(arr, n * sizeof(int)); // Se cambia la memoria asignada

    if(arr == NULL) { // Verificación de errores al asignar memoria
        printf("Error al asignar memoria.");
        return 1;
    }

    arr[n-1] = n; // Se agrega un nuevo dato al final del arreglo

    // Imprimir el arreglo modificado
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arr);
    return 0;
}
