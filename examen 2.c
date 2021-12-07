/*
    Escriba un programa en C que dada la siguiente declaración de estructuras:
    typedef struct {
        char nombre[40];
        char pais[25];
    }DatosPersonales;
    typedef struct{
        DatosPersonales datos;
        char deporte[30];
        int numMedallas;
    }Deportista;
    1. Realice una función que lea de un archivo de TEXTO la información de los deportistas.
    2. Realice una función que reciba los deportistas leídos y calcule e imprima el número de medallas por
    deporte.
    Nota: Dentro del código existe un arreglo que contiene los nombres de todos los deportes que existen en el archivo.
        char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};
*/

#include <stdio.h>
#include <string.h>

typedef struct {

    char nombre[40];
    char pais[25];

}DatosPersonales;

typedef struct{
    DatosPersonales datos;
    char deporte[30];
    int numMedallas;

}Deportista;

void leerArchivo(FILE arch, Deportista *dep);
void calculaMedallas(Deportista dep, char *dep, int *med[6]);

int main()
{
    FILE *archivo;
    Deportista deportistas[10];
    Deportista deportistas2[10];
    // Puede cambiar la declaración de este arreglo a donde lo considere necesario
    char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};

    int deport;
    int cerrado;
    int medallas[6];
    
    archivo = fopen("examen.txt", "w"); //Si el archivo no existe y lo intento abrir con r, me regresa null

    printf("¿Cuántos deportistas quieres insertar?: ");
    scanf("%d", &deport);

    for(int i = 1; i <= deport; i++)
    {
        printf("Dame el nombre del deportista número %d: ", i);
        scanf("%s", deportistas[i].datos.nombre);

        printf("Dame su país: ");
        scanf("%s", deportistas[i].datos.pais);

        printf("Dame su deporte: ");
        scanf("%s", deportistas[i].deporte);

        printf("¿Cuántas medallas gano?: ");
        scanf("%d", deportistas[i].numMedallas);

        fprintf(archivo, "%s %s %s %d\n", deportistas[i].datos.nombre, deportistas[i].datos.pais,deportistas[i].deporte, deportistas[i].numMedallas);
    }
    cerrado = fclose(archivo);

    archivo = fopen("examen.txt", "r"); //Si el archivo no existe y lo intento abrir con r, me regresa null

    for(int i = 1; i <= deport; i++)
    {
      leerArchivo(archivo, *deportistas2, deport);
      calculaMedallas(deportistas2, deporte[6][30], &medallas);
    }

    cerrado = fclose(archivo);

     if(cerrado == EOF) //fclose regresa EOF cuando no se puede cerrar correctamente 
    {
        printf("El archivo no se cerró bien");
    }

    return 0;
}

void leerArchivo(FILE arch, Deportista *dep)
{
    int pudoLeer;

    do
   {
       fscanf(arch, "%s", dep->datos.nombre);
       fscanf(arch, "%s", dep->datos.pais);
       fscanf(arch, "%s", dep->deporte);
       pudoleer = fscanf(arch, "%d", dep->numMedallas);

   }while(pudoleer != EOF);
}

void calculaMedallas(Deportista dep, char dep[6][30], int *med[6])
{
    for(int i = 0; i <= 6; i++)
    {
       if(strcpy(dep.deporte, char[i][30]))
       {
        *med[i] = 0;
        *med[i] = medallas[i] + dep.numMedallas;
       } 
    }
}