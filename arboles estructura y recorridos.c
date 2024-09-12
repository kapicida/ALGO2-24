#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[50];

typedef struct {
    int codigo;
    tString descripcion;
} tDatos;

typedef struct nodoArbol {
    tDatos datos;
    struct nodoArbol * hijoIzquierdo;
    struct nodoArbol * hijoDerecho;
} tArbol;

bool arbolVacio(tArbol * arbol) {
    return arbol == NULL;
}

tArbol* crearNodo(int codigo, const char* descripcion) {
    tArbol* nuevoNodo = (tArbol*)malloc(sizeof(tArbol));
    if (nuevoNodo) {
        nuevoNodo->datos.codigo = codigo;
        strncpy(nuevoNodo->datos.descripcion, descripcion, sizeof(nuevoNodo->datos.descripcion) - 1);
        nuevoNodo->datos.descripcion[sizeof(nuevoNodo->datos.descripcion) - 1] = '\0';
        nuevoNodo->hijoIzquierdo = NULL;
        nuevoNodo->hijoDerecho = NULL;
    }
    return nuevoNodo;
}

void insertar(tArbol** pArbol, int codigo, const char* descripcion) {
    if (*pArbol == NULL) {
        *pArbol = crearNodo(codigo, descripcion);
    } else {
        if (codigo < (*pArbol)->datos.codigo) {
            insertar(&(*pArbol)->hijoIzquierdo, codigo, descripcion);
        } else {
            insertar(&(*pArbol)->hijoDerecho, codigo, descripcion);
        }
    }
}

void recorrerEnPreorden(tArbol * pArbol) {
    if (!arbolVacio(pArbol)) {
        // R
        printf("%d - %s\n", pArbol->datos.codigo, pArbol->datos.descripcion);
        // I
        recorrerEnPreorden(pArbol->hijoIzquierdo);
        // D
        recorrerEnPreorden(pArbol->hijoDerecho);
    }
}

void recorrerEnInorden(tArbol * pArbol) {
    if (!arbolVacio(pArbol)) {
        // I
        recorrerEnInorden(pArbol->hijoIzquierdo);
        // R
        printf("%d - %s\n", pArbol->datos.codigo, pArbol->datos.descripcion);
        // D
        recorrerEnInorden(pArbol->hijoDerecho);
    }
}

void recorrerEnPostorden(tArbol * pArbol) {
    if (!arbolVacio(pArbol)) {
        // I
        recorrerEnPostorden(pArbol->hijoIzquierdo);
        // D
        recorrerEnPostorden(pArbol->hijoDerecho);
        // R
        printf("%d - %s\n", pArbol->datos.codigo, pArbol->datos.descripcion);
    }
}

bool buscarElemento(tArbol * pArbol, int pCodigo) {
    if (arbolVacio(pArbol)) {
        return false;
    } else if (pCodigo > pArbol->datos.codigo) {
        return buscarElemento(pArbol->hijoDerecho, pCodigo);
    } else if (pCodigo < pArbol->datos.codigo) {
        return buscarElemento(pArbol->hijoIzquierdo, pCodigo);
    } else {
        return true;
    }
}

// Función principal
int main() {
    tArbol* arbol = NULL;

    // Insertar datos en el árbol
    insertar(&arbol, 410, "Raiz");
    insertar(&arbol, 314, "IzqRaiz");
    insertar(&arbol, 432, "DerRaiz");
    insertar(&arbol, 537, "DerDerRaiz");
    insertar(&arbol, 843, "DerDerDerRaiz");
    insertar(&arbol, 51, "IzqIzqRaiz");
    insertar(&arbol, 129, "IzqIzqDerRaiz");

    // Recorridos
    printf("Recorrido en Preorden:\n");
    recorrerEnPreorden(arbol);
    printf("\n");

    printf("Recorrido en Inorden:\n");
    recorrerEnInorden(arbol);
    printf("\n");

    printf("Recorrido en Postorden:\n");
    recorrerEnPostorden(arbol);
    printf("\n");

    // Liberar memoria (opcional)
    // Aquí podrías implementar una función para liberar la memoria del árbol

    return 0;
}
//410 314 51 129 432 537 843 Este es preorden
//51 129 314 410 432 537 843 inorden
//129 51 314 843 537 432 410 postorden
//PRE Raiz Izq Derecha
//IN Izq Raiz Derecha
//POST IZQ DER RAIZ