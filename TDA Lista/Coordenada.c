#include "Coordenada.h"

void asigna(coordenada* coord, int a, int b){
    printf("Ingrese la coordenada X");
    scanf("%d",&a);
    printf("Ingrese la coordenada Y");
    scanf("%d",&b);
    coord->x= a;
    coord->y= b;
}

void mueve(coordenada* coord, int a, int b){
    printf("Cuantos valores en x desea mover?");
    scanf("%d",&a);
    printf("Cuantos valores en y desea mover");
    scanf("%d",&b);
    coord->x = coord->x + a;
    coord->y = coord->y + b;
}

int compararCoordenadas(coordenada coord, coordenada coord2){
    if (coord.x == coord2.x && coord.y == coord2.y)
    {
        return 0;
    }
    else{
        return -1;
    }
}