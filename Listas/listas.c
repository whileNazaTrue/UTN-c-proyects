#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo* sig;
}nodo;

nodo * crearNodo(int dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}


int main(){
    nodo * lista = NULL;
    nodo * nuevo;
    lista = crearNodo(3);
    nuevo = crearNodo(7);
    lista->sig = nuevo;
    lista->sig->sig = crearNodo(8);

    printf("%d",lista->dato);


    nodo * laux = lista;
    while (laux != NULL){
        printf("%d",laux->dato);
        laux = laux->sig;
    }


    return 0;
}