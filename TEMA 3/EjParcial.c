#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

typedef char tString[MAX];

void ImprimirMayus(tString, int);

int main(){
    int A = 300;
    tString Texto;
    strcpy(Texto,"celoopatA");
    //printf("%d\n",strlen(Texto));
    ImprimirMayus(Texto,strlen(Texto));
    return 0;
}


void ImprimirMayus(tString pTexto, int pDim) {
    if (pDim <= 0) {
        return;
    }
    int i = strlen(pTexto) - pDim;
    if (pDim == strlen(pTexto)) {
        printf("\"");
    }
    printf("%c", toupper(pTexto[i]));
    ImprimirMayus(pTexto, pDim - 1);

    // Imprimir la comilla de cierre solo en la última llamada
    if (pDim == 1) {
        printf("\"");
    }
}