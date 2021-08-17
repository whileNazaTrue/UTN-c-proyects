#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Librerias/pila.h>

typedef struct { 
    char nombre[30]; 
    char genero; 
    int edad;
}persona; 

persona* copiarAmalloc(persona personas[], int validosGenero, int validos, char genAux);
int cuentaGenero(persona personas[],int validos, char *genAux);
int cargaEstatica(persona personas[]);
void ordSeleccion(persona personaGenero[], int validosGenero);
void mostrarEstruct(persona personas[], int validos);


int main(){
    int i = 0;
    char genAux;
    persona personas[30];
    int validos = cargaEstatica(personas);
    mostrarEstruct(personas,validos);
    int validosGenero = cuentaGenero(personas,validos, &genAux);
    printf("Hay %d,del genero ingresado\n",validosGenero);
    persona* personaGenero = copiarAmalloc(personas,validosGenero,validos,genAux);
    mostrarEstruct(personaGenero,validosGenero);

    //
    
    Pila pila1;
    Pila pila2;
    inicpila(&pila1);
    inicpila(&pila2);
    
}


int cargaEstatica(persona personas[]){
    int validos=0;
    printf("Cuantos vas a cargar?");
    scanf("%d",&validos);
    for (int i = 0; i < validos; i++)
    {
        printf("Nombre:\n");
        fflush(stdin);
        gets(personas[i].nombre);
        printf("Genero:\n");
        fflush(stdin);
        scanf("%c",&personas[i].genero);
        printf("Edad:\n");
        scanf("%d",&personas[i].edad);
    }
    return validos;
}

int cuentaGenero(persona personas[],int validos, char *genAux){
    int contador= 0;
    printf("Ingresa un genero");
    fflush(stdin);
    scanf("%c",genAux);
    for (int i = 0; i < validos; i++)
    {
        if (personas[i].genero == *genAux)
        {
            contador++;
        }
        
    }
    return contador;
}

persona* copiarAmalloc(persona personas[], int validosGenero, int validos, char genAux){

    persona* personasGenero = (persona*)malloc(sizeof(persona)*validosGenero+1);
    for (int i = 0; i < validos; i++)
    {
        if (personas[i].genero == genAux){
            strcpy(personasGenero[i].nombre,personas[i].nombre);
            personasGenero[i].genero = personas[i].genero;
            personasGenero[i].edad = personas[i].edad;
        }
    }
    
    return personasGenero;
}


void ordSeleccion(persona personaGenero[], int validosGenero){
    int i=0;
    int max=personaGenero[0].edad;
    for (int i = 0; i < validosGenero; i++)
    {
        for (int j=i+1; i < validosGenero; i++)
        {
            if (personaGenero[i].edad>personaGenero[j].edad)
            {
                max=personaGenero[i].edad;
                personaGenero[i].edad=personaGenero[j].edad;
                personaGenero[j].edad=max;
            }
            
        }
        
    }
    
}


void mostrarEstruct(persona personas[], int validos){
    for (int i = 0; i < validos; i++)
    {
        printf("Nombre: %s\n",personas[i].nombre);
        printf("Genero: %c\n",personas[i].genero);
        printf("Edad: %d\n",personas[i].edad);
        printf("=======================\n");
    }
    
    
}


void ordenarPila()