#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Circulo.h"

int main(){
    Circulo circulardo;

    asignar(&circulardo,3);


    float areaCirculo = area(circulardo);
    printf("El area es %f\n",areaCirculo);
    float perimetroCirculo = perimetro(circulardo);
    printf("El perimetro es %f\n",perimetroCirculo);
    return 0;
}