#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generar una agenda de personas


typedef struct persona
{
    char nombreyApellido[30];
    char telefono[20];
    char direccion[30];
    char ciudad[20];
}persona;



int main(){
    persona p;
    strcpy(p.nombreyApellido,"juan carlos");


    return 0;
}