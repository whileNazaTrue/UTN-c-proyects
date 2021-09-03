#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nombre[20];
    int edad;
}persona;

typedef struct nodoPersona{
    persona p;
    struct nodoPersona * siguiente;
}nodoPersona;


nodoPersona * inicLista(nodoPersona * lista);
nodoPersona * crearPersona(persona p);
nodoPersona * anadirPrincipio(nodoPersona * lista, nodoPersona * nuevoNodo);
void mostrarPersona(nodoPersona * aux);
void mostrarLista(nodoPersona * lista);
nodoPersona * ingresarDatos(nodoPersona * lista);
persona retornarPersona();


int main(){

    nodoPersona * lista = inicLista(lista);
    
    lista = ingresarDatos(lista);
    mostrarPersona(lista);
    

    
    return 0;
}


nodoPersona * inicLista(nodoPersona * lista){
    return lista = NULL;
}

nodoPersona * crearPersona(persona p){
    nodoPersona * persona1 = (nodoPersona*) malloc (sizeof(nodoPersona));

    persona1->p.edad = p.edad;
    strcpy(persona1->p.nombre,p.nombre);
    persona1->siguiente = NULL;

    return persona1;
}

nodoPersona * anadirPrincipio(nodoPersona * lista, nodoPersona * nuevoNodo){
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else{
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}


void mostrarPersona(nodoPersona * aux){
    printf("Nombre: %s\n",aux->p.nombre);
    printf("Edad: %d\n",aux->p.edad);


}
void mostrarLista(nodoPersona * lista){
    while (lista != NULL)
    {
        mostrarPersona(lista);
        lista = lista->siguiente;
    }
    
}


nodoPersona * ingresarDatos(nodoPersona * lista){
    nodoPersona * nuevo;
    persona p;
    char cont = 's';
    fflush(stdin);
    while (cont == 's')
    {
        p = retornarPersona();
        nuevo = crearPersona(p);
        lista = anadirPrincipio(lista,nuevo);

        printf("Continuas?\n");
        fflush(stdin);
        scanf("%c",&cont);
    }
    return lista;
}

persona retornarPersona(){
    persona p;
    printf("Nombre:\n");
    fflush(stdin);
    gets(p.nombre);
    printf("Edad:\n");
    scanf("%d",&p.edad);
    return p;
}