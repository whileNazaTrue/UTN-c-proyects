#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Circulo.h"

int main(){
    Circulo circulardo;

    asignar(&circulardo,3);


    float areaCirculo = area(circulardo);
    printf("El area es %f",areaCirculo);
    float perimetroCirculo = perimetro(circulardo);
    printf("El perimetro es %f",perimetroCirculo);
    return 0;
}