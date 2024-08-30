#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
int n;
int factorial(int);
int main() {
    printf("Ingrese el Numero para calcular el factorial: ");
    scanf("%d",&n);
    printf("%d", factorial(n));
    return 0;
}
int factorial(int pN){
    if (pN == 0  || pN == 1){
        return 1;
    }
    else {
        return pN * factorial(pN-1);
    }
}