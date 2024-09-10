#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

int n;
void verenBinario(int);
int main() {
    printf("Ver en Binario: ");
    scanf("%d", &n);
    verenBinario(n);
    return 0;
}
void verenBinario(int pN){
    if (pN == 0){
        printf("0");
    }
    else{
    verenBinario(pN / 2);
    printf("%d", pN % 2);
    }
}