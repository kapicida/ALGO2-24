/*/
Escribir una función recursiva que reciba como parámetros un arreglo de números enteros y 
su dimensión y retorne la Multiplicación de los números impares que se encuentran almacenados en el 
arreglo.
/*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// Función para crear un arreglo dinámicamente
int* CrearArreglo(int pTamanio) {
    int* pArreglo = (int*) malloc(pTamanio * sizeof(int));
    if (pArreglo == NULL) {
        printf("Error al asignar memoria \n");
        return NULL;
    }

    // Solicitar los elementos del arreglo
    for (int i = 0; i < pTamanio; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &pArreglo[i]);
    }

    return pArreglo;
}

int MultiNumImpares(int* pArreglo, int pDimension) {
    if (pDimension == 0) {
        return 1;
    }

    if (pArreglo[pDimension - 1] % 2 != 0) {
        return pArreglo[pDimension - 1] * MultiNumImpares(pArreglo, pDimension - 1);
    } else {
        return MultiNumImpares(pArreglo, pDimension - 1);
    }
}

int main() {
    int Dimension;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &Dimension);

    int* arreglo = CrearArreglo(Dimension);

    if (arreglo != NULL) {
        // Multiplicación de los números impares
        int resultado = MultiNumImpares(arreglo, Dimension);

        printf("El producto de los números impares es: %d\n", resultado);

        // Liberar la memoria asignada al arreglo
        free(arreglo);
    }

	 if (arreglo == NULL){
		printf("que rico lo mamas");
		printf("%s",arreglo);
	 }

    return 0;
}
