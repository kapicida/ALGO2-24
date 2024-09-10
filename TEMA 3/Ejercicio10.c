#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXC 50

typedef char tString[MAXC];

void analizarP(tString pPalabra, int i, tString PalabraInv);

int main() {
    tString PalabraInv;
    tString Palabra;
    strcpy(Palabra, "RECONOCER");
    analizarP(Palabra, 0, PalabraInv);
    return 0;
}


void analizarP(tString pPalabra, int i, tString PalabraInv) {
    int len = strlen(pPalabra);

    if (pPalabra[i] == '\0') {
        PalabraInv[len] = '\0';
        printf("Palabra Invertida: %s\n", PalabraInv);

        if (strcasecmp(pPalabra, PalabraInv) == 0) {
            printf("La palabra ingresada es Palíndromo\n");
        } else {
            printf("No son Palíndromos\n");
        }
    } else {
        PalabraInv[len - i - 1] = pPalabra[i];
        analizarP(pPalabra, i + 1, PalabraInv);
    }
}
