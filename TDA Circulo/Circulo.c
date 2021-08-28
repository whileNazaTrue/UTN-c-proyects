#include "Circulo.h"
#include <math.h>

#define pi 3.14159265359

void asignar(Circulo* circulo,float radio){
    circulo->radio = radio;
}

float area(Circulo circulo){
    float area;
    area = pow(circulo.radio,2) * pi;
    return area;
}

float perimetro(Circulo circulo){
    float perimetro;
    perimetro =2*pi*circulo.radio;
    return perimetro;
}