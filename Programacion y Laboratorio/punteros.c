#include <stdio.h>
#include <stdlib.h>

void intercambio(int* a, int* b);

int main(){
    int num = 5;
    int* puntero;

    puntero = &num;


    *puntero=6;

    printf("Dire de memoria: %d",puntero);
    printf("Que hay:%d",*puntero);
    printf("direccion: %d",&num);
    printf("num %d",num);

    int a=5;
    int b=12;

    intercambio(&a,&b);

    //FREE SOLO SE USA EN DIRS DE MEMORIA CREADAS CON MALLOC

    system("pause");
    system("cls");

    int *punterito = (int*)malloc(sizeof(int));

    printf("%x\n",punterito);
    *punterito=25;

    printf("%i",*punterito);

    return 0;
}


void intercambio(int* a, int* b){
    int x;
    x= *a;
    *a = *b;
    *b = x;
}