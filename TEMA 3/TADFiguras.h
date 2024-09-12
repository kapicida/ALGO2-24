#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAXC 50

typedef char tString[MAXC];

typedef struct{
    tString color;
    bool relleno;
} tFigura;

typedef struct{
    tFigura figura;
    float radio;
} tCirculo;

typedef struct{
    tFigura figura;
    float lado;
} tCuadrado;

typedef struct{
    tFigura figura;
    float base;
    float altura;
} tRectangulo;

void CalcularArea();
void CalcularAreaRectangulo(tRectangulo);
void CalcularAreaCuadrado(tCuadrado);
void CalcularAreaCirculo(tCirculo);
void DatosFigura(tFigura*);
void MostrarDatosFigura(tFigura);

void DatosFigura(tFigura *pFigura){
    printf("Ingrese Color de la Figura\n");
    scanf("%s", pFigura->color);

    int Relleno;
    printf("Esta Rellena la Figura (1 para Si, 2 para No):\n");
    scanf("%d",&Relleno);
    pFigura->relleno = (Relleno == 1);
}

void MostrarDatosFigura(tFigura pFigura){
    printf("Color: %s, Relleno: %s\n\n", pFigura.color, pFigura.relleno ? "Sí" : "No");
}

void CalcularAreaRectangulo(tRectangulo pRectangulo) {
    float area = pRectangulo.base * pRectangulo.altura;
    printf("\nEl área del rectángulo es %.2f m^2\n\n", area);
}

void CalcularAreaCuadrado(tCuadrado pCuadrado) {
    float area = pCuadrado.lado * pCuadrado.lado;
    printf("\nEl área del cuadrado es %.2f m^2\n\n", area);
}

void CalcularAreaCirculo(tCirculo pCirculo) {
    float area = M_PI * pow(pCirculo.radio, 2);
    printf("\nEl área del círculo es %.2f m^2\n\n", area);
}

void CalcularArea(){
    int opcion;
    do{
        printf("*** MENU ***\n");
        printf("Ingrese Opcion:\n");
        printf("1. Calcular Área Rectángulo\n");
        printf("2. Calcular Área Cuadrado\n");
        printf("3. Calcular Área Círculo\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
            tRectangulo rectangulo;
            DatosFigura(&rectangulo.figura);
            printf("Ingrese Base y Altura en (Metros):\n");
            scanf("%f %f",&rectangulo.base,&rectangulo.altura);
            CalcularAreaRectangulo(rectangulo);
            MostrarDatosFigura(rectangulo.figura);
            break;

            case 2:
            tCuadrado cuadrado;
            DatosFigura(&cuadrado.figura);
            printf("Ingrese Lado en (Metros):\n");
            scanf("%f",&cuadrado.lado);
            CalcularAreaCuadrado(cuadrado);
            MostrarDatosFigura(cuadrado.figura);
            break;       

            case 3:
            tCirculo circulo;
            DatosFigura(&circulo.figura);
            printf("Ingrese Radio en (Metros):\n");
            scanf("%f",&circulo.radio);
            CalcularAreaCirculo(circulo);
            MostrarDatosFigura(circulo.figura);
            break;

            case 4:
            printf("Saliendo del Programa...\n");
            break;

            default:
            printf("Opcion Invalida\n");
            break;
        }
    }
    while(opcion != 4);
}