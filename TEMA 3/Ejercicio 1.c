#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

int n;
void cuentaRegresiva(int);
int main() {
    printf("Ingrese el Numero (Cuenta Regresiva): ");
    scanf("%d", &n);
    cuentaRegresiva(n);
    return 0;
}
void cuentaRegresiva(int pN){
    if (pN == 0){
        printf("Tiempo Agotado");
    }
    else {
        printf("Tiempo: %d s ...\n",pN);
        cuentaRegresiva(pN-1);
    }
}