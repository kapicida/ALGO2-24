//Recursividad
#include <stdio.h>
#define MAX 5

typedef int tArreglo[MAX];

int MultiNumImpar(tArreglo pArreglo,int pDim){
    if(pDim < 0){
        return 1;
    }
    else{
        if((pArreglo[pDim] % 2) != 0){
            return pArreglo[pDim]*MultiNumImpar(pArreglo,pDim-1);
        }
        else
        {
             return MultiNumImpar(pArreglo,pDim-1);
        }
    }
}

int main(){
    tArreglo Array = {5, 2, 3, 4, 5}; 
    //for(i=0;i<MAX;i++){
    //    printf("Ingrese Num Entero: \n");
    //    scanf("%d",&Array[i]);
    //}
    printf("La multi de num impar es %d",MultiNumImpar(Array,MAX-1));
}
