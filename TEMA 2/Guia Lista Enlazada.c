#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCAR 5

typedef char tString[MAXCAR];

typedef struct{
	int codigo;
	tString nombre;
	tString descripcion;
}tColor;

typedef struct nodoColor {
	tColor color;
	struct nodoColor * siguiente;
}tListaColores;

void inicializarLista();
bool listaVacia(tListaColores *);
void insertarColor(tColor);
void insertarPrimerColor(tColor);
void insertarColorAdelante(tColor);

void eliminarPrimerColor();

void mostrarColores(tListaColores *);

void insertaColorEnPos(int, tColor);
void eliminarColorDePos(int);

tColor ingresarColor();
void menu();

tListaColores * listaColores;

int main() {
	
	tColor auxColor;
		
	inicializarLista();
	menu();
	/*//auxColor.codigo=1;
	//strcpy(auxColor.nombre,"Rojo");
	
	//insertarColor(ingresarColor());
	
	auxColor=ingresarColor();
	insertarColor(auxColor);
	
	auxColor.codigo=2;
	strcpy(auxColor.nombre,"Azul");
		
	insertarColor(auxColor);
	
	auxColor.codigo=3;
	strcpy(auxColor.nombre,"Verde");
		
	insertarColor(auxColor);
	
	mostrarColores(listaColores);
	
	eliminarPrimerColor();
	
	mostrarColores(listaColores);
	*/
	
	return 0;
}

tColor ingresarColor(){
	tColor auxColorIngresado;
	
	printf("\ningrese el id");
	scanf("%d",&auxColorIngresado.codigo);
	
	printf("\ningrese el nombre");	
	scanf("%s",&auxColorIngresado.nombre);
	
	return auxColorIngresado;
}

void inicializarLista() {
	listaColores = NULL;
	printf("Lista de colores inicializada!\n");
}

bool listaVacia(tListaColores * pListaColores) {
	return (pListaColores == NULL);
}

void insertarColor(tColor pColor) {
	if(listaVacia(listaColores)){
		insertarPrimerColor(pColor);
	}else{
		insertarColorAdelante(pColor);
	}
}

void insertarPrimerColor(tColor pColor) {
	tListaColores * nuevoColor;
	nuevoColor = (tListaColores *) malloc(sizeof(tListaColores));
	
	nuevoColor->color = pColor;

	nuevoColor->siguiente = NULL;
	
	listaColores = nuevoColor;
	
	printf("\nPrimer color insertado: %s", pColor.nombre);
}


void insertarColorAdelante(tColor pColor) {
	tListaColores * nuevoColor;
	nuevoColor = (tListaColores *) malloc(sizeof(tListaColores));
	
	nuevoColor->color = pColor;
		
	nuevoColor->siguiente = listaColores;
	
	listaColores = nuevoColor;
	
	printf("\nColor insertado: %s", pColor.nombre);
}

void eliminarPrimerColor() {
	if(listaVacia(listaColores)){
		printf("No hay colores para quitar de la lista!\n");
	}else{
		
		/* Almacenar el nodo a suprimir en una variable auxiliar */		
		tListaColores * colorSuprimir = listaColores;
		
		/* Romper el enlace al primer elemento */
		listaColores = listaColores->siguiente;
		
		/* Imprimir un mensaje representativo */
		printf("\nColor quitado: %s", colorSuprimir->color.nombre);
		
		/* Liberar la memoria del nodo suprimido */
		free(colorSuprimir);		
		colorSuprimir = NULL;		
	}
}


void mostrarColores(tListaColores * pListaColores) {
	if(listaVacia(pListaColores)){
		printf("No hay colores para mostrar en la lista!\n");
	}else{
		
		tListaColores * listaAux = pListaColores;
		
		printf("\n *** Lista de colores ***\n");
		while(listaAux != NULL){
			printf("%d-%s | ", listaAux->color.codigo, listaAux->color.nombre);
			listaAux = listaAux->siguiente;
		}	
	}
}

void menu(){
     int dato;
	 int posicion;
	 while(dato != 6){
	 	printf("\n\n*** MENU ***\n");
	 	printf("1-Insertar color \n");
	 	printf("2-Eliminar color\n");
	 	printf("3-Mostar lista colore: \n");	 	
	 	printf("4-Insertar en pos \n");	 	
	 	printf("5-Eliminar en pos \n");
	 	printf("6-Salir\n");
	 	printf("Ingresar una opcion 1 al 6\n");
	 	scanf("%d", &dato);
	 	switch(dato){
	 		case 1:
	 			insertarColor(ingresarColor());
	 			break;
			case 2:
			 	eliminarPrimerColor();
			 	break;
			case 3:
			 	mostrarColores(listaColores); 
			 	break;
			case 4:
		 		printf("\n Ingrese posicion: ");
				scanf("%d", &posicion);
				insertaColorEnPos(posicion, ingresarColor());
				break;
			case 5:
				printf("\n Ingrese posicion: ");
				scanf("%d", &posicion);
		 		eliminarColorDePos(posicion);
		 		break;
			case 6:
			 	printf("\ncerrando programa\n");
			 	break;
		 }
	 }	
}

void insertaColorEnPos(int posicion, tColor pColor) {
	/* Se debe utilizar una lista auxiliar (aux) */
	tListaColores * listaAux = listaColores;
	
	/* 	Avanzar hasta el nodo anterior a la posici�n 
		donde se quiere insertar */
	int i;
	for(i = 1; i < posicion-1; i++) {
		listaAux = listaAux->siguiente;
	}
	
	/* Reservar memoria para el nodo que se va a insertar */
	tListaColores * nuevoNodo = (tListaColores *) malloc(sizeof(tListaColores));
	
	/* Asignar valor a la componente del dato */
	nuevoNodo->color = pColor;
	
	/* Actualizaci�n de punteros */
	
	/* Actualizar componente puntero del nuevo nodo */
	nuevoNodo->siguiente = listaAux->siguiente;
		
	/* Actualizar componente puntero del nodo auxiliar */
	listaAux->siguiente = nuevoNodo;
	
	printf("\nColor insertado en la posicion %d: %s", 
				posicion, pColor.nombre);
}
}

void eliminarColorDePos(int posicion) {
	/* Se debe utilizar una lista auxiliar (aux) */
	tListaColores * listaAux = listaColores;
	
	/* 	Avanzar hasta el nodo anterior a la posici�n 
		donde se quiere quitar */
	int i;
	for(i = 1; i < posicion-1; i++) {
		listaAux = listaAux->siguiente;
	}
	
	/* Resguardar el nodo a suprimir */
	tListaColores * colorSuprimir = listaAux->siguiente;
	
	/* 	Actualizar el puntero siguiente del nodo anterior 
		al que se va a quitar */
	listaAux->siguiente = colorSuprimir->siguiente;
	
	printf("\nColor quitado de la posicion %d: %s", 
			posicion,
			colorSuprimir->color.nombre);
	
	/* Liberar la memoria del puntero color a suprimir */	
	free(colorSuprimir);
	colorSuprimir = NULL;
}

