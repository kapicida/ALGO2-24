/*/1. Crear un  tipo  de  dato  tListaProductos  para un  nodo  que  permita  almacenar  los  siguientes datos  de  un 
producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo, 
y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos 
del primer nodo almacenado /*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXCAR 50

typedef char tString[MAXCAR];

typedef struct{
	int codigo;
	tString nombre;
	tString descripcion;
}tProducto;

typedef struct nodoProducto {
	tProducto producto;
	struct nodoProducto * siguiente;
}tListaProducto;
