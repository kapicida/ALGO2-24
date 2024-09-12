#include <stdio.h>
#include <ctype.h>
int num = 0;
/*/
Escribir una función que calcule la división entera entre 2 números de manera recursiva. Recordar que la 
división matemática se define como una operación aritmética, que consiste en saber cuántas veces un 
número (divisor) está contenido en otra cifra (dividendo).*/
void IngresarNum(){
    printf("Ingrese Numero Entero a Invertir: \n");
    scanf("%d",&num);
}

int NumInv(int pNum){
    if (pNum<10){
        return pNum;
    }
    else{
        return (pNum/10)+NumInv(pNum/10);
    }
}

void NumInv2(int pN){
    if (pN < 10){
        printf("%d",pN);
    }
    else{
    printf("%d", pN % 10);   
    NumInv2(pN / 10);
    }
}

int main(){
num = 123;
//NumInv2(num);
printf("%d",Division(10,250));
//printf("%d",NumInv(num));
}

/*/
Escribir una función que calcule la división entera entre 2 números de manera recursiva. Recordar que la 
división matemática se define como una operación aritmética, que consiste en saber cuántas veces un 
número (divisor) está contenido en otra cifra (dividendo).*/

int Division(int pDivisor,int pDividendo){
    if(pDividendo < pDivisor){
        return 0;
    }
    else{
        return 1 + Division(pDivisor,pDividendo-pDivisor);
    }
}