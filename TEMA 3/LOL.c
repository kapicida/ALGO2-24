#include <stdio.h>
int DETPAR (int,int*,int*,int*);
int main() {
int X,men,may,BPP=0; 
while(X>0){
printf ("Ingrese un numero natural: ");
scanf("%d",&X);
if(DETPAR(X,&men,&may,&BPP)==0&&X!=0){
printf("EL NUMERO ESTA FORMADO UNICAMENTE POR DIGITOS PARES\n");
}
}
if(BPP==0){
  printf("Ningun numero formado solo con digitos pares fue ingresado");
}else{
printf ("\nEl menor es %d",men);
  printf ("\nEl mayor es %d",may);
}
return 0;
}

int DETPAR(int X,int *men,int *may,int *BPP){
int D,aux=X,B=0; 
while (X>0&&B==0){ //mientras X tenga digitos y no se haya detectado ningun dig impar
D=X%10; //saco el ultimo digito
if(D%2!=0){ //si el digito es impar
B=1;}
else{
X/=10;
}
}
if(B==0){  //pregunto por que se salio del ciclo V=el numero solo tiene digitos pares, F=tiene digitos impares
if(*BPP==0){ //para determinar si es el primer par que entra (para inicializar la vble men y may)
*men=aux;
*may=aux;
*BPP=1;
}
else{
if(aux<*men&&aux!=0){ //si no pongo aux!=0 el programa toma a la bandera de fin de entrada como numero ingresado y lo asigna al valor de men
*men=aux;
}
else if(aux>*may&&aux!=0){
*may=aux;
}
}
}
return B;
}