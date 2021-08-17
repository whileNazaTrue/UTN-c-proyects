#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Librerias/pila.h>

typedef struct { 
    char nombre[30]; 
    char genero; 
    int edad;
}persona; 


//

typedef struct { 
    int matricula; 
    char nombre[30]; 
} Alumno; 

typedef struct { 
    int codigo; 
    char nombreMat[20];
} Materia ; 

typedef struct { 
    int matricula; 
    int codigo; 
    int nota; 
} Nota; 




persona* copiarAmalloc(persona personas[], int validosGenero, int validos, char genAux);
int cuentaGenero(persona personas[],int validos, char *genAux);
int cargaEstatica(persona personas[]);
void ordSeleccion(persona personaGenero[], int validosGenero);
void mostrarEstruct(persona personas[], int validos);
void cargarMateria(Materia mats[]);
void agregarAlumno(Alumno alus[]);
int agregarNota(Nota notas[], Materia mats[], Alumno alus[]);
void imprimirAlumno(Alumno alus[], Nota notas[], Materia mats[]);



int main(){
    /*
    int i = 0;
    char genAux;
    persona personas[30];
    int validos = cargaEstatica(personas);
    mostrarEstruct(personas,validos);
    int validosGenero = cuentaGenero(personas,validos, &genAux);
    printf("Hay %d,del genero ingresado\n",validosGenero);
    persona* personaGenero = copiarAmalloc(personas,validosGenero,validos,genAux);
    mostrarEstruct(personaGenero,validosGenero);

    //
    
    Pila pila1;
    Pila pila2;
    inicpila(&pila1);
    inicpila(&pila2);
    
    //
    */
    Alumno alus[20]; // para almacenar los datos de los 20 alumnos. 
    Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias. 
    Nota notas[100]; // para almacenar todas las notas de los alumnos. 

    cargarMateria(mats);
    agregarAlumno(alus);
    int bandera = agregarNota(notas,mats,alus);
    if (bandera==1)
    {
        printf("Carga exitosa\n");
    }
    else{
        printf("ERROR!\n");
        exit(1);
    }
    
    imprimirAlumno(alus,notas,mats);

}


int cargaEstatica(persona personas[]){
    int validos=0;
    printf("Cuantos vas a cargar?");
    scanf("%d",&validos);
    for (int i = 0; i < validos; i++)
    {
        printf("Nombre:\n");
        fflush(stdin);
        gets(personas[i].nombre);
        printf("Genero:\n");
        fflush(stdin);
        scanf("%c",&personas[i].genero);
        printf("Edad:\n");
        scanf("%d",&personas[i].edad);
    }
    return validos;
}

int cuentaGenero(persona personas[],int validos, char *genAux){
    int contador= 0;
    printf("Ingresa un genero");
    fflush(stdin);
    scanf("%c",genAux);
    for (int i = 0; i < validos; i++)
    {
        if (personas[i].genero == *genAux)
        {
            contador++;
        }
        
    }
    return contador;
}

persona* copiarAmalloc(persona personas[], int validosGenero, int validos, char genAux){

    persona* personasGenero = (persona*)malloc(sizeof(persona)*validosGenero+1);
    for (int i = 0; i < validos; i++)
    {
        if (personas[i].genero == genAux){
            strcpy(personasGenero[i].nombre,personas[i].nombre);
            personasGenero[i].genero = personas[i].genero;
            personasGenero[i].edad = personas[i].edad;
        }
    }
    
    return personasGenero;
}


void ordSeleccion(persona personaGenero[], int validosGenero){
    int i=0;
    int max=personaGenero[0].edad;
    for (int i = 0; i < validosGenero; i++)
    {
        for (int j=i+1; i < validosGenero; i++)
        {
            if (personaGenero[i].edad>personaGenero[j].edad)
            {
                max=personaGenero[i].edad;
                personaGenero[i].edad=personaGenero[j].edad;
                personaGenero[j].edad=max;
            }
            
        }
        
    }
    
}


void mostrarEstruct(persona personas[], int validos){
    for (int i = 0; i < validos; i++)
    {
        printf("Nombre: %s\n",personas[i].nombre);
        printf("Genero: %c\n",personas[i].genero);
        printf("Edad: %d\n",personas[i].edad);
        printf("=======================\n");
    }
    
    
}


void ordenarInsercion(persona personas[], int validos){
    int pos = 0;
    for (int i = 0; i < validos; i++)
    {
        pos = i;
        int aux = personas[i].edad;
        while (pos >0 && personas[pos-1].edad>aux)
        {
            personas[pos].edad=personas[pos-1].edad;
            pos--;
        }
        personas[pos].edad=aux;
    }
    
}


void eliminarElemento(persona personas[], int validos){
    int pos;
    int flag=0;
    char nombreAux[30];
    printf("Ingrese el nombre del que vamos a borrar");
    fflush(stdin);
    gets(nombreAux);
    for (int i = 0; i < validos; i++)
    {
        if (strcmp(nombreAux,personas[i].nombre)==0)
        {
            flag=1;
            pos=i;
            break;
        }
        
    }
    if (flag==1)
    {
        for (int i = 0; i < validos; i++)
        {
            strcpy(personas[i].nombre,personas[i+1].nombre);
        }
        
    }
}



void cargarMateria(Materia mats[]){
    for (int i = 0; i < 3; i++)
    {
        printf("Codigo de la materia:\n");
        scanf("%d",&mats[i].codigo);
        printf("Nombre de la materia:\n");
        fflush(stdin);
        gets(mats[i].nombreMat);
    }
    
}


void agregarAlumno(Alumno alus[]){
    for (int i = 0; i < 3; i++)
    {
        printf("Matricula del alumno: \n");
        scanf("%d",&alus[i].matricula);
        printf("Nombre del alumno:\n");
        fflush(stdin);
        gets(alus[i].nombre);
    }
    
}

int agregarNota(Nota notas[], Materia mats[], Alumno alus[]){
    int matriculaAux;
    int codigoAux;
    
    printf("Ingrese la matricula del alumno");
    scanf("%d",&matriculaAux);
    printf("Ingresa el codigo de la materia");
    scanf("%d",&codigoAux);
    for (int i = 0; i < 3; i++)
    {
        if (matriculaAux == alus[i].matricula && codigoAux == mats[i].codigo)
        {
                    printf("Ingrese la nota");
                    scanf("%d",&notas[i].nota);
                    notas[i].codigo=mats[i].codigo;
                    notas[i].matricula=alus[i].matricula;
                    return 1;
                }
                else{
                    return 0;
                }
            }   
        }


void imprimirAlumno(Alumno alus[], Nota notas[], Materia mats[]){
    for (int i = 0; i < 3; i++)
    {
        printf("Nombre: %s\n",alus[i].nombre);
        printf("Matricula: %d\n",alus[i].matricula);
        if (notas[i].matricula == alus[i].matricula);
        {
            printf("Codigo: %d\n",notas[i].codigo);
            if (notas[i].codigo == mats[i].codigo)
            {
                printf("Nombre de la materia: %s\n",mats[i].nombreMat);
                printf("Nota: %d\n",notas[i].nota);
            }
            
        }
        printf("====================\n");
    }
    
}