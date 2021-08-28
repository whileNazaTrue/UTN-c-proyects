#include <stdio.h>
#include <stdlib.h>
#include "Coordenada.h"


int main(){
    coordenada coordenadaPicante;
    coordenada coordenadaPeronista;

    asigna(&coordenadaPicante,3,5);
    printf("%d",coordenadaPicante.x);
    printf("\n");
    printf("%d",coordenadaPicante.y);
    printf("\n");

    asigna(&coordenadaPeronista,5,6);
    printf("%d",coordenadaPeronista.x);
    printf("\n");
    printf("%d",coordenadaPeronista.y);
    printf("\n");
    mueve(&coordenadaPeronista,5,5);
    printf("%d",coordenadaPeronista.x);
    printf("\n");
    printf("%d",coordenadaPeronista.y);
    printf("\n");
    printf("\n");
    printf("%d",coordenadaPicante.x);
    printf("\n");
    printf("%d",coordenadaPicante.y);
    printf("\n");
    
    int flag = compararCoordenadas(coordenadaPicante,coordenadaPeronista);
    if (flag == -1)
    {
        printf("SON DISTINTAS");
    }
    else{
        printf("Son iguales");
    }

    return 0;
}