#include <stdio.h>

typedef struct
{
int x;
int y;

}coordenada;
void asigna(coordenada* coord, int a, int b); // asigna las coordenadas a la estructura
void mueve(coordenada* coord,int a,int b); // avanza coordenada un valor x1 e y1.
int compararCoordenadas(coordenada coord,coordenada coordComp); //compara con otra coordenada y devuelve 0
// si son idénticas, -1 si coordenada de la izq está mas cerca del origen, o 1 en caso contrario.