#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int pedirFactorial();
long calculoFactorial(long numero);
int pedirBasePotencia();
int pedirExponentePotencia();
double calculoPotencia(int base, int exponente);
void cargarArreglo(int arreglo[], int validos);
int recorrerArreglo(int arreglo[], int validos);
int recorrerArregloDerecho(int arreglo[], int validos, int contador);

int main(){
    int validos = 10;
    srand(time(NULL));
    int numeroFactorial = pedirFactorial();

    for (int i = 0; i <= numeroFactorial; i++)
    {
        printf("===\n");
        printf("%ld\n",calculoFactorial(i));
    }

    int base = pedirBasePotencia();
    int exponente = pedirExponentePotencia();

    printf("%.3f\n",calculoPotencia(base,exponente));

    int arreglo[10];

    cargarArreglo(arreglo, validos);
    recorrerArregloDerecho(arreglo,validos,0);
    printf("=======");
    recorrerArreglo(arreglo,validos);
    return 0;
}

// Punto 1: Factorial


int pedirFactorial(){
    int numero;
    printf("Ingresa un num.\n");
    scanf("%d",&numero);
    return numero;
}

long calculoFactorial(long numeroFactorial){
    if (numeroFactorial <=1)
    {
        return 1;
    }
    else{
        return(numeroFactorial*calculoFactorial(numeroFactorial-1));
    }

}

//Punto 2: Calcular la potencia de forma recursiva


int pedirBasePotencia(){
    int base;
    printf("Ingresa la base\n");
    scanf("%d",&base);
    return base;
}

int pedirExponentePotencia(){
    int exponente;
    printf("Ingresa el exponente\n");
    scanf("%d",&exponente);
    return exponente;
}

double calculoPotencia(int base, int exponente){
    if (exponente == 0)
    {
        return 1;
    }
    else if (exponente <0)
    {
        return calculoPotencia(base,exponente+1) / base;
    }
    else{
        return base * calculoPotencia(base,exponente-1);
    }
    
}

void cargarArreglo(int arreglo[], int validos){
    for (int i = 0; i < validos; i++)
    {
        arreglo[i] = i;
    }
    

}

int recorrerArregloDerecho(int arreglo[], int validos, int contador){
    if (contador==validos)
    {
        return 0;
    }else{
        printf("|%d|\n",arreglo[contador]);
        return recorrerArregloDerecho(arreglo,validos,contador+1);
    }
    
}
// Arreglo recursivo invertido

int recorrerArreglo(int arreglo[], int validos){
    
    if (validos == 0){
        return 0;
    }else{
        printf("|%d|\n",arreglo[validos-1]);
        return recorrerArreglo(arreglo,validos-1);
    }
}