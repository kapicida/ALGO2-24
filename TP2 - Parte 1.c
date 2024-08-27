#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXCAR 100

typedef char tString[MAXCAR];

// Definición de la estructura tEncuestado
typedef struct {
    char codigosex;  // Código de sexo (F o M)
    int codigoedad;  // Código de rango de edad (01, 02, 03)
    tString nombre;  // Nombre del encuestado
    float Peso;      // Peso del encuestado en kg
    float Altura;    // Altura del encuestado en metros
    tString IMC;     // Clasificación del IMC
} tEncuestado;

// Definición de la estructura nodoEncuestado (Lista enlazada)
typedef struct nodoEncuestado {
    tEncuestado encuestado;                  // Información del encuestado
    struct nodoEncuestado *siguiente;  // Puntero al siguiente nodo de la lista
} tListaEncuestados;

tListaEncuestados *ListaEncuestados = NULL;

void inicializarLista(tListaEncuestados**);
bool listaVacia(tListaEncuestados*);
int mostrarCantidadEncuestados(tListaEncuestados*);
float PromedioPesoBajo(tListaEncuestados*);
void IngresarEncuestado(tListaEncuestados**);
void calcularIMC(tEncuestado*);
void listarSobrepeso(tListaEncuestados*);
void menu();

int main() {
    inicializarLista(&ListaEncuestados); // Inicializa ListaEncuestados a NULL
    menu();
    if (listaVacia(ListaEncuestados)) {
        printf("La Lista No Tiene Elementos\n");
    }
    return 0;
}

void menu() {
    int dato = 1;
    while (dato != 0) {
        printf("\n\n*** MENU ***\n");
        printf("1 - Muestra la cantidad total de encuestados\n");
        printf("2 - El promedio de pesos de las personas de peso bajo, que sean menores de 15 años\n");
        printf("3 - Ingresar Encuestado\n");
        printf("4 - Listar personas con sobrepeso\n");
        printf("0 - Salir\n");
        printf("Ingresar una opción 1 al 4\n");
        scanf("%d", &dato);
        switch (dato) {
            case 1:
                printf("La Cantidad de Encuestados es %d\n", mostrarCantidadEncuestados(ListaEncuestados));
                break;
            case 2:
                printf("El promedio de pesos de las personas de peso bajo es: %.2f\n", PromedioPesoBajo(ListaEncuestados));
                break;
            case 3:
                IngresarEncuestado(&ListaEncuestados);
                break;
            case 4:
                listarSobrepeso(ListaEncuestados);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    }
}

void inicializarLista(tListaEncuestados** pLista) {
    *pLista = NULL;
    printf("Lista inicializada!\n");
}

bool listaVacia(tListaEncuestados* pLista) {
    return (pLista == NULL);
}

int mostrarCantidadEncuestados(tListaEncuestados* pLista) {
    if (listaVacia(pLista)) {
        printf("La lista está vacía.\n");
        return 0;
    } else {
        tListaEncuestados* listaaux = pLista;
        int Acumulador = 0;
        while (listaaux != NULL) {
            Acumulador++;
            listaaux = listaaux->siguiente;
        }
        return Acumulador;
    }
}

void calcularIMC(tEncuestado* encuestado) {
    float imc = encuestado->Peso / pow(encuestado->Altura, 2);

    if (encuestado->codigosex == 'F') {
        if (imc < 20) {
            strcpy(encuestado->IMC, "Peso bajo");
        } else if (imc >= 20 && imc <= 25) {
            strcpy(encuestado->IMC, "Peso normal");
        } else {
            strcpy(encuestado->IMC, "Sobrepeso");
        }
    } else {  // Masculino
        if (imc < 19) {
            strcpy(encuestado->IMC, "Peso bajo");
        } else if (imc >= 19 && imc <= 24) {
            strcpy(encuestado->IMC, "Peso normal");
        } else {
            strcpy(encuestado->IMC, "Sobrepeso");
        }
    }
}

float PromedioPesoBajo(tListaEncuestados* pLista) {
    if (listaVacia(pLista)) {
        printf("La lista está vacía.\n");
        return 0;
    }

    tListaEncuestados* listaaux = pLista;
    int Acumulador = 0;
    int i = 0;
    float PromedioPesoBajo = 0;

    while (listaaux != NULL) {
        if (listaaux->encuestado.codigoedad == 1) {  // Verifica si la edad es menor de 15 (01)
            if (strcmp(listaaux->encuestado.IMC, "Peso bajo") == 0) {
                i++;
                Acumulador += listaaux->encuestado.Peso;
            }
        }
        listaaux = listaaux->siguiente;
    }

    if (i > 0) {
        PromedioPesoBajo = (float) Acumulador / i;
    } else {
        PromedioPesoBajo = 0;  // No se encontraron casos que cumplan con la condición
    }

    return PromedioPesoBajo;
}

void listarSobrepeso(tListaEncuestados* pLista) {
    if (listaVacia(pLista)) {
        printf("La lista está vacía.\n");
        return;
    }

    tListaEncuestados* listaaux = pLista;

    printf("\nPersonas con Sobrepeso:\n");
    while (listaaux != NULL) {
        if (strcmp(listaaux->encuestado.IMC, "Sobrepeso") == 0) {
            printf("Nombre: %s, Sexo: %c, Edad: %d, Peso: %.2f, Altura: %.2f, IMC: %s\n",
                   listaaux->encuestado.nombre, listaaux->encuestado.codigosex,
                   listaaux->encuestado.codigoedad, listaaux->encuestado.Peso,
                   listaaux->encuestado.Altura, listaaux->encuestado.IMC);
        }
        listaaux = listaaux->siguiente;
    }
}

void IngresarEncuestado(tListaEncuestados** pLista) {
    tEncuestado nuevoEncuestado;
    printf("Ingrese el nombre del encuestado: ");
    scanf("%s", nuevoEncuestado.nombre);
    printf("Ingrese el código de sexo (M/F): ");
    scanf(" %c", &nuevoEncuestado.codigosex);
    printf("Ingrese el rango de edad (01: < 15 años, 02: 15-30 años, 03: > 30 años): ");
    scanf("%d", &nuevoEncuestado.codigoedad);
    printf("Ingrese el peso del encuestado en kilogramos: ");
    scanf("%f", &nuevoEncuestado.Peso);
    printf("Ingrese la altura del encuestado en metros: ");
    scanf("%f", &nuevoEncuestado.Altura);

    calcularIMC(&nuevoEncuestado);

    tListaEncuestados* nuevoNodo = (tListaEncuestados*) malloc(sizeof(tListaEncuestados));
    nuevoNodo->encuestado = nuevoEncuestado;
    nuevoNodo->siguiente = NULL;

    if (*pLista == NULL) {
        *pLista = nuevoNodo;
    } else {
        tListaEncuestados* actual = *pLista;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

