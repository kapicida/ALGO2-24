#include <stdio.h>
#include <string.h>

typedef char tString[50];
void detPalindromo(tString,int,tString);

int main() {
tString Palabra;
strcpy(Palabra,"RECONOCER");
tString InvPalabra;
detPalindromo(Palabra,0,InvPalabra);
    return 0;
}

void detPalindromo(tString pPalabra, int pInicio, tString pInvPalabra){
    if(pPalabra[pInicio] == '\0'){
        pInvPalabra[pInicio] = '\0';
        printf("La Palabra Invertida es %s\n",pInvPalabra);
        printf("La Palabra Ingresada es %s\n",pPalabra);
        if(strcmp(pPalabra,pInvPalabra) == 0){

            printf("Las Palabras son Palindromos\n");
        }
        else{
            printf("Las Palabras no son Palindromos");
        }
    }
    else{
        int largoPalabra = strlen(pPalabra);
        char CaracterActual = pPalabra[pInicio];
        pInvPalabra[largoPalabra-pInicio-1]= CaracterActual;
        detPalindromo(pPalabra,pInicio+1,pInvPalabra);
    }
}