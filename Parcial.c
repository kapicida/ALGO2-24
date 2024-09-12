typedef char tString[50];

typedef struct{
    int ID;
    tString Proyecto;
    int Contri;
}tDatos;

typedef struct tNodo{
    tDatos datos;
    struct tNodo * hijoizq;
    struct tNodo * hijoder;
}tArbol;

tArbol * arbol;

