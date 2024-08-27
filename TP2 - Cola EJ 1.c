#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

#define MAXCAR 100

typedef char tString[MAXCAR];
tString operaciones[2] = {"Transaccion", "Consulta"};

typedef struct {
    int codturno; 
    tString nombre;  
    int motivo;      
} tTicket;

typedef struct nodo {
    tTicket ticket;                 
    struct nodo *siguiente;  
} tNodo;

typedef struct Cola {
    tNodo* inicio;
    tNodo* fin;
    int tamano;
}tCola;

tCola cola;

// Declaracion de funciones
int contarTransacciones(tCola *cola) {
    int contador = 0;
    tNodo* aux = cola->inicio;
    while (aux != NULL) {
        if (aux->ticket.motivo == 1) {
            contador++;
        }
        aux = aux->siguiente;
    }
    return contador;
}

int contarConsultas(tCola *cola) {
    int contador = 0;
    tNodo* aux = cola->inicio;
    while (aux != NULL) {
        if (aux->ticket.motivo == 2) {
            contador++;
        }
        aux = aux->siguiente;
    }
    return contador;
}

void inicializarCola(tCola *cola){
    cola->inicio = NULL;
    cola->fin = NULL;
    cola->tamano = 0;
    printf("Cola Inicializada...\n");
}

void agregarTicket(tCola *cola, tTicket ticket) {
    tNodo* nuevo = (tNodo*)malloc(sizeof(tNodo));
    nuevo->ticket = ticket;
    nuevo->siguiente = NULL;
    if (cola->inicio == NULL) {
        cola->inicio = nuevo;
        cola->fin = nuevo;
    } else {
        cola->fin->siguiente = nuevo;
        cola->fin = nuevo;
    }
    cola->tamano++;
}

void eliminarTicket(tCola *cola) {
    if (cola->inicio == NULL) {
        printf("La cola está vacía. No hay tickets para eliminar.\n");
        return;
    }

    tNodo* nodoAEliminar = cola->inicio;
    cola->inicio = cola->inicio->siguiente;

    if (cola->inicio == NULL) {
        cola->fin = NULL;
    }

    free(nodoAEliminar);
    cola->tamano--;
}

void mostrarCola(tCola *cola) {
    tNodo* aux = cola->inicio;
    while (aux != NULL) {
        printf("%d %d %s %s\n", aux->ticket.codturno, aux->ticket.motivo, operaciones[aux->ticket.motivo - 1], aux->ticket.nombre);
        aux = aux->siguiente;
    }
}

void menu(tCola *cola){
    int opcion;
    do
    {
        printf("Ingrese Opcion:  \n");
        printf("1. Agregar Ticket\n");
        printf("2. Eliminar Ticket\n");
        printf("3. Mostrar Cola\n");
        printf("4. Numero de Transacciones \n");
        printf("5. Numero de Consultas\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
            {
                tTicket ticket;
                // Pedir datos del ticket al usuario
                printf("Ingrese código de turno: ");
                scanf("%d", &ticket.codturno);
                printf("Ingrese nombre: ");
                scanf("%s", ticket.nombre);
                printf("Ingrese motivo (1 para transacción, 2 para consulta): ");
                scanf("%d", &ticket.motivo);
                agregarTicket(cola, ticket);
                break;
            }
            case 2:
            eliminarTicket(cola);
            break;
            case 3:
            mostrarCola(cola);
            break;
            case 4:
            printf("Numero de Transacciones: %d\n", contarTransacciones(cola));
            break;
            case 5:
            printf("Numero de Consultas: %d\n", contarConsultas(cola));
            break;
        }

    } while (opcion != 0);
}

int main(){
    setlocale(LC_CTYPE, "es_ES.UTF-8");
    inicializarCola(&cola);
    menu(&cola);
    return 0;
}



