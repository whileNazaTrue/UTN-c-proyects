// LA RECURSION SIGUE LA REGLA DIVIDE Y CONQUISTA. SE ROMPE EL PROBLEMA EN PEQUEÑOS PEDACITOS QUE REPRESENTAN EL MISMO TIPO DE PROBLEMA //


//UNA FUNCION RECURSIVA ESTA DEFINIDA EN TERMINOS DE CASO BASE Y CASOS RECURSIVOS

// CASO BASE: Nos se llama  asi misma. Maneja un caso simple que debemos resolver sin tener que desarmar en problema en partes mas chicas. Se resuelve enseguida.

// Tiene dos componentes: Condicion que hace que la entrada sea mas pequeña Y Solucion trivial. Esto signfica "Si estamos en ella, que valor deberia devolver?". Estamos parados
//en la solucion.

//En resumen, que condicion hace que no se pueda reducir mas? Si estoy en esta posicion, que deberia devolver?


//CASO RECURSIVO

//TRES COMPONENTES

//Dividir el problema en tres pequeñas partes

//Invoca a la funcion con cada parte

//Combina la solucion de cada una en general para el problema

//POR EJEMPLO: 4*3!

//Esto es lo mismo que !4
#include <stdio.h>
#include <stdlib.h>

int main(){
    return 0;
}


//ENTONCES

//Iterativa:

int factorial(int n){
    int fact = 1;
    for (int i = 0; i <=n; i++)
    {
        fact=fact*i;
    }
    return fact;    
}

int factorial(int n){
    if (n==0){
        return 1;
    }
        else{
            return n*factorial(n-1);
        }
    }
