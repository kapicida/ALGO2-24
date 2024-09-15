#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char tString[50];

typedef struct{
	int nroturno;
	tString nombre;
	tString apellido;
	int consulta;
	tString horaconsulta;
}tDatos;

typedef struct nodo{
	tDatos datos;
	struct nodo * siguiente;
}tTurnos;

tTurnos * listaturnos;

void InicializarLista();
bool ListaVacia(tTurnos*);

tDatos CargarDatos();
void InsertarTurno(tDatos);
void InsertarK(tDatos, int);
void DatosCompleto();

void VisualizarConsulta(int);

int main(){
	InicializarLista();

	return 0;
}

void InicializarLista(){
	listaturnos = NULL;
	printf("Lista inicializada \n");
}

bool ListaVacia(tTurnos * pLista){
	return (pLista==NULL);
}


