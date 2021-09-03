#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIR "archivo.dat"

typedef struct nodo{
    int dato;
    struct nodo* sig;
}nodo;

void cargarArchivo();
nodo * crearNodo(int dato);
void insertarDatosFinal(nodo ** lista, nodo* dato);
void pasarDatos(nodo **lista);
void leerLista(nodo * lista);


int main(){
    srand(time(NULL));
    cargarArchivo();
    
    nodo * lista = NULL;
    pasarDatos(&lista);
    leerLista(lista);
    return 0;
}


void cargarArchivo(){
    
    FILE * archi;
    archi = fopen(DIR,"wb");
    int validos;
    printf("Cuantos datos queres cargar?\n");
    scanf("%d",&validos);
    if (archi != NULL)
    {
        for (int i = 0; i < validos; i++)
        {
            int numRand = rand()%50;
            fwrite(&numRand,sizeof(int),1,archi);
        }
    fclose(archi);
    }
    else{
        printf("ERROR!\n");
    }

}

nodo * crearNodo(int dato){
    nodo * nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}


void insertarDatosFinal(nodo ** lista, nodo* dato){
    nodo * aux = *lista;

    if (*lista == NULL)
    {
        *lista = dato;
    }
    else{
        while (aux->sig != NULL)
        {
            aux =aux->sig;
        }
        aux->sig = dato;
    }
}

void pasarDatos(nodo **lista){
    nodo * aux = NULL;
    int dato;
    FILE * archi;
    archi = fopen(DIR,"rb");
    if (archi != NULL)
    {
        while (fread(&dato,sizeof(int),1,archi)> 0)
        {
            aux = crearNodo(dato);
            insertarDatosFinal(lista,aux);
        }
        
    }
    
}

void leerLista(nodo * lista){
    printf("\tElementos de la lista: \n");
    while (lista != NULL)
    {
        printf("\t%d",lista->dato);
        lista = lista->sig;
    }
    
}


void eliminarNodoCabeza(nodo ** lista, int dato){
    nodo * aux;
    nodo * act;
    nodo * ant;
    while (lista != NULL)
    {
        if ((*lista)->dato == dato) //Esta en cabezera
        {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        }
        else{
            ant = *lista;
            act = (*lista)->sig;
            while (act != NULL && act->dato != dato)
            {
                ant = act;
                act = act->sig;
            }
            if (act != NULL)
            {
                ant->sig = act->sig;
                free(act);
            }
            
        }
        
    }
    
}


void eliminarNodoOrdenada(nodo ** lista, int dato){
    nodo * aux;
    nodo * act;
    nodo * ant;
    if (*lista != NULL && (*lista)->dato <= dato)
    {
        if ((*lista)->dato == dato)
        {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        }
        else{
            ant = *lista;
            act = (*lista)->sig;
            while (act != NULL && act->dato < dato)
            {
                ant = act;
                act = act->sig;
            }
            if (act != NULL && act->dato == dato)
            {
                ant->sig = act->sig;
                free(act);
            }
            
        }
    }
    
}