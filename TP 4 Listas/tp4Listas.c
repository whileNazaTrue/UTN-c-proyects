#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nombre[20];
    int edad;
}persona;

typedef struct nodo{
    persona p;
    struct nodo * sig;
}nodo;

int main(){
    persona p;
    nodo * lista = NULL;
    lista->sig = crearNodo(p);
    return 0;
}


nodo* crearNodo(persona p)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->p = p;
    nuevo->sig= NULL; //por defecto el nuevo nodo apuntará a NULL
    return nuevo;
}

void insertarAlPrincipio(nodo** lista, persona p)
{
    nodo* nuevo= crearNodo(p);
    nuevo->sig=*lista;
    *lista=nuevo;
}


void insertarAlFinal(nodo** lista, persona p)
{
    nodo* nuevo=crearNodo(p);
    nodo* seg;
    if (*lista == NULL)
        {
            *lista = nuevo;
        }
    else
        {
            seg = *lista;
            while (seg->sig != NULL)
            {
                seg=seg->sig;
            }
        seg->sig=nuevo;
    }
}


void mostrarPersona(nodo * aux){
    printf("Nombre: %s\n",aux->p.nombre);
    printf("Edad: %d\n",aux->p.edad);


}
void mostrarLista(nodo * lista){
    while (lista != NULL)
    {
        mostrarPersona(lista);
        lista = lista->sig;
    }
    
}
