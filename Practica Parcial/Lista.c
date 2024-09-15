#include <stdio.h>
#include <stdbool.h>

typedef char tString[50];

typedef struct{
    int nroturno;
    int tipo;
    tString fecha;
    tString nombre;
    tString apellido;
}tDatos;

typedef struct nodo{
    tDatos datos;
    struct nodo * siguiente;
}tLista;

tLista* listaturnos;

bool listaVacia(tLista* pLista) {
    return (pLista == NULL);
}

void EliminarTurnoEnPos(int Pos,tLista ** pLista){
    tLista * auxlista = *pLista;

    int i;
    for(i=1;i<Pos-1;i++){
        auxlista = auxlista->siguiente;
    }
    tLista * NodoASuprimir = auxlista->siguiente;
    auxlista->siguiente = NodoASuprimir->siguiente;
    printf("\nTurno quitado de la posicion %d: %s", 
			Pos,
			NodoASuprimir->datos.nombre);
	
	free(NodoASuprimir);
	NodoASuprimir = NULL;
}

void InsertarTurnoEnPos(int Pos, tLista **pLista, tDatos pDatos) {
    tLista *NuevoNodo = (tLista *)malloc(sizeof(tLista));
    NuevoNodo->datos = pDatos;

    // Caso especial: insertar en la primera posición
    if(Pos == 1) {
        NuevoNodo->siguiente = *pLista;
        *pLista = NuevoNodo;
        printf("\nTurno insertado en la posición %d: %s\n", Pos, pDatos.nombre);
        return;
    }

    // Recorrer la lista hasta el nodo anterior a la posición de inserción
    tLista *auxlista = *pLista;
    int i;
    for (i = 1; i < Pos - 1 && auxlista != NULL; i++) {
        auxlista = auxlista->siguiente;
    }

    if (auxlista == NULL) {
        printf("Posición inválida para insertar.\n");
        free(NuevoNodo);
        return;
    }

    NuevoNodo->siguiente = auxlista->siguiente;
    auxlista->siguiente = NuevoNodo;
    printf("\nTurno insertado en la posición %d: %s\n", Pos, pDatos.nombre);
}

void MostrarLista(tLista * pLista){
    if(listaVacia(pLista)){
        printf("No hay Turnos para Mostrar \n");
    }
    else{
        tLista * auxlista = pLista;
        printf(" \t Lista Turnos \n");
        while(auxlista != NULL){
            printf("%d\n",auxlista->datos.nroturno);
            auxlista = auxlista -> siguiente;
        }
    }
}

tDatos ingresarTurno(){
	tDatos auxTurno;
	
	printf("\nIngrese el id: ");
	scanf("%d",&auxTurno.nroturno);
	
	printf("\nIngrese el nombre: ");	
	scanf("%s",&auxTurno.nombre);
	
	return auxTurno;
}

void IngresarEnLista(tLista* *pLista,tDatos pDatos){
    if(listaVacia(pLista)){
        IngresarPrimero(&pLista,pDatos);
    }
    else{
        IngresarDelante(&pLista,pDatos);
    }
}

void IngresarPrimero(tLista ** pLista,tDatos pDatos){
    tLista * nuevoNodo;
    nuevoNodo = (tLista *)malloc(sizeof(tLista));

    nuevoNodo->datos=pDatos;
    nuevoNodo->siguiente=NULL;

    *pLista = nuevoNodo;
    printf("Primer Turno Insertado - Paciente: %d, %s\n",pDatos.nroturno,pDatos.nombre);
}

void IngresarDelante(tLista ** pLista,tDatos pDatos){
    tLista * nuevoNodo;
    nuevoNodo = (tLista *)malloc(sizeof(tLista));

    nuevoNodo->datos=pDatos;
    nuevoNodo->siguiente=pLista;

    *pLista = nuevoNodo;
    printf("Turno Insertado - Paciente: %d, %s\n",pDatos.nroturno,pDatos.nombre);
}

void eliminarPrimerTurno(tLista**pLista){
    if(listaVacia(pLista)){
        printf("No hay Turnos para Eliminar");
    }
    else{
        tLista * NodoASuprimir = pLista;

        (*pLista) = (*pLista)->siguiente;

        printf("\nTurno quitado: %s", NodoASuprimir->datos.nombre);
        free(NodoASuprimir);
        NodoASuprimir=NULL;
    }
}

int main() {
    tLista *listaturnos = NULL; // Inicializar la lista como vacía
    tDatos nuevoTurno;
    int opcion, pos;

    do {
        printf("\n\n--- Menu de Turnos ---\n");
        printf("1. Insertar Turno\n");
        printf("2. Eliminar Turno en Posición\n");
        printf("3. Mostrar Lista de Turnos\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Insertar un nuevo turno en la lista
                nuevoTurno = ingresarTurno();
                if (listaVacia(listaturnos)) {
                    IngresarPrimero(&listaturnos, nuevoTurno);
                } else {
                    printf("Ingrese la posición en la que desea insertar el turno: ");
                    scanf("%d", &pos);
                    InsertarTurnoEnPos(pos, &listaturnos, nuevoTurno);
                }
                break;

            case 2:
                // Eliminar un turno en una posición
                if (listaVacia(listaturnos)) {
                    printf("No hay turnos para eliminar.\n");
                } else {
                    printf("Ingrese la posición del turno a eliminar: ");
                    scanf("%d", &pos);
                    EliminarTurnoEnPos(pos, &listaturnos);
                }
                break;

            case 3:
                // Mostrar todos los turnos
                MostrarLista(listaturnos);
                break;

            case 4:
                // Salir del programa
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}