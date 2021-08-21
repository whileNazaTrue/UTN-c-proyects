#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int pedirFactorial();
long calculoFactorial(long numero);
int pedirBasePotencia();
int pedirExponentePotencia();
double calculoPotencia(int base, int exponente);
void cargarArreglo(int arreglo[], int validos);
int recorrerArreglo(int arreglo[], int validos);
int arregloCapicua(int arregloUno[], int v, int n);
int recorrerArregloDerecho(int arreglo[], int validos, int contador);
int sumarElementosArreglo(int arregloUno[], int elementosArreglo);
int menorElemento(int arregloUno[],int elementosArreglo, int menor);
void cargarArchivo(int arregloDos[]);
void leerArchivo();
int menorArchivoRecursivo(int registros, int menor);

int main(){
    /*
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
    printf("=======\n");
    recorrerArreglo(arreglo,validos);
    */
    int elementosArreglo = 6;

    int arregloUno[7]= {3,36,9,33,38,172,11};//Este es capicua
    int arregloDos[6]= {15,2,5,3,2,6}; //No es capicua
    printf("El arreglo %s es capicua.\n", (arregloCapicua(arregloUno,elementosArreglo,elementosArreglo))?"":"no");
    printf("%d es el resultado de la suma\n",sumarElementosArreglo(arregloUno,elementosArreglo));
    printf("%d es el menor\n",menorElemento(arregloUno,elementosArreglo,arregloUno[0]));
    cargarArchivo(arregloDos);
    leerArchivo();
    printf("=================\n");
    printf("El menor del archivo es %d",menorArchivoRecursivo(0,0));

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

// Ver si un arreglo es capicua

int arregloCapicua(int arregloUno[], int v, int n){
    if (n==0)
    {
        return 1;
    }else{
        if (arregloUno[v-n] == arregloUno[n]){
            return arregloCapicua(arregloUno,v,n);
        }else{
            return 0;
        }

        
    }
    

}
//int chequeoCapicua(int arregloUno[], int elementosArreglo){}

// Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma

int sumarElementosArreglo(int arregloUno[], int elementosArreglo){
    if (elementosArreglo == 0)
    {
        return 0;
    }else{
        return sumarElementosArreglo(arregloUno,elementosArreglo-1)+arregloUno[elementosArreglo-1];
    }
    
}

//  Buscar el menor elemento de un arreglo en forma recursiva. 

int menorElemento(int arregloUno[],int elementosArreglo, int menor){
    if (elementosArreglo==-1)
    {
        return menor;
    }
    else{
        if (arregloUno[elementosArreglo] < menor)
        {
            menor = arregloUno[elementosArreglo];
        }
        return menorElemento(arregloUno,elementosArreglo-1,menor);
    }
}

void cargarArchivo(int arregloDos[]){
    FILE * archi;
    archi = fopen("archivo.dat","wb");
    if (archi != NULL)
    {
        for (int i = 0; i < 7; i++)
            {
                fwrite(&arregloDos[i],sizeof(int),1,archi);
            }
    fclose(archi);
    }
    
}

void leerArchivo(){
    int aux;
    FILE * archi;
    archi = fopen("archivo.dat","rb");
    if (archi != NULL)
    {
        while (fread(&aux,sizeof(int),1,archi)> 0)
            {
                printf("*********\n");
                printf("%d\n",aux);
            }
    fclose(archi);
    }
    
}

int menorArchivoRecursivo(int registros,int menor)
{
    if(registros == -1)
    {
        return menor;
    }
    else
    {
        int aux;//Genero un variable auxiliar para leer un archivo
        FILE *archi = fopen("archivo.dat","rb");//Abro el archivo
        fseek(archi,sizeof(int)*registros,SEEK_SET);//Cuando se iteraciona movemos el curso al elemto que queremos comparar
        fread(&aux,sizeof(int),1,archi);
        if(registros==0)//si el registro es cero menor no tiene ningun valor asiganado
        {
            menor=aux;
        } 
        else
        {
            if(aux < menor)//comparacion
            {
                menor=aux;
            }
        }
        if(feof(archi))//Si llego al final del archivo
        {
            registros=-2;//para que? para cuando realice la iteriacion retorne menos -1 cuando termine de leer 
            // el archivo y generar la condicion de corte
        }
        fclose(archi);
        return menorArchivoRecursivo(registros+1,menor);//para comparar todos los registros del archivooo
    }
}