#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

typedef char tString[50];

typedef struct{
    int id;
    tString IP;
    tString Nombre;
    int tamanio;
}tDocum;

typedef struct nodo{
    tDocum documento;
    struct nodo * siguiente;
}tNodo;

typedef struct Cola {
    tNodo *inicio;
    tNodo *final;
}tCola;

tCola cola;

//Funciones de Cola
void InicializarCola();
bool ColaVacia();
tDocum cargarDoc();
void InsertarCola(tDocum);
void desencolarCola();
void visualizarCola(tNodo*);
//Funciones Especificas de mi Problema
int TotalDocImagenes(tNodo*);
float TamanioTotal(tNodo*);
tDocum PrimeroenCola(tNodo*);
void Imprimir(tNodo*);
//Menu
void menu();

int main(){
    tDocum auxdocumento;
    InicializarCola();
    auxdocumento = cargarDoc();
    InsertarCola(auxdocumento);
    visualizarCola(cola.inicio);
    return 0;
}

void InicializarCola(){
    cola.inicio = NULL;
    cola.final = NULL;
    printf("Cola Inicializada... \n");
}

bool ColaVacia(){
    return (cola.inicio == NULL && cola.final == NULL);
}

tDocum cargarDoc(){
    tDocum auxdoc;
    strcpy(auxdoc.IP,"192.168.0.1");
    strcpy(auxdoc.Nombre,"EL UNTITLED1");
    auxdoc.id =1;
    auxdoc.tamanio = 10000;
    return auxdoc;
}

void InsertarCola(tDocum pDoc){
    tNodo *nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
    nuevoNodo->documento = pDoc;
    nuevoNodo->siguiente = NULL;
    if(ColaVacia()){
        cola.inicio = nuevoNodo;
        cola.final = nuevoNodo;
    }
    else{
        cola.final->siguiente = nuevoNodo;
        cola.final = nuevoNodo;
    }
    printf("Se inserto un Nodo en la Cola\n");
}

void visualizarCola(tNodo* pAux){
    tNodo * auxNodo;
    auxNodo = pAux;
    while(auxNodo !=  NULL){
       printf("IP : %s / Nombre Documento :%s\n", auxNodo->documento.IP, auxNodo->documento.Nombre);
       auxNodo = auxNodo->siguiente;
    }
}