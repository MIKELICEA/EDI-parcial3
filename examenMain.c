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
#include <stdlib.h>
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

int main()
{
    FILE *archivo;
    Deportista deportistas[3];
    // Puede cambiar la declaración de este arreglo a donde lo considere necesario
    char deporte[6][30] = {"Natacion", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};
    int cerrado;
    int medallas[6];
    char deport[6][30];
    int j = 1;
    int pudoleer;
    int nat = 0, atle = 0, cicli = 0, gim = 0, equi = 0, esgri = 0;


    archivo = fopen("examen.txt", "w"); //Si el archivo no existe y lo intento abrir con r, me regresa null

    for(int i = 1; i <= 3; i++)
    {
        printf("Dame el nombre del deportista número %d: ", i);
        scanf("%s", deportistas[i].datos.nombre);

        printf("Dame su país: ");
        scanf("%s", deportistas[i].datos.pais);

        printf("Dame su deporte Natacion, Atletismo, Ciclismo, Gimnasia, Equitacion, Esgrima: ");
        scanf("%s", deportistas[i].deporte);

        printf("¿Cuántas medallas gano?: ");
        scanf("%d", &deportistas[i].numMedallas);

        fprintf(archivo, "%s %s %s %d\n", deportistas[i].datos.nombre, deportistas[i].datos.pais,deportistas[i].deporte, deportistas[i].numMedallas);
    }

    cerrado = fclose(archivo);

    archivo = fopen("examen.txt", "r"); //Si el archivo no existe y lo intento abrir con r, me regresa null

    do
    {
        fscanf(archivo, "%s", deportistas[j].datos.nombre);
        fscanf(archivo, "%s", deportistas[j].datos.pais);
        fscanf(archivo, "%s", deportistas[j].deporte);
        pudoleer = fscanf(archivo, "%d", &deportistas[j].numMedallas);

        strcpy(deport[j],deportistas[j].deporte);
        medallas[j] = deportistas[j].numMedallas;

        j++;

   }while(pudoleer != EOF && j <= 3);

    cerrado = fclose(archivo);

    for(int i = 1; i <= 3; i++)
    {
        if(!strcmp("Natacion",deport[i]))
        {
            nat = nat + medallas[i];
        }else if (!strcmp("Atletismo",deport[i]))
        {
            atle = atle + medallas[i];
        }else if (!strcmp("Ciclismo",deport[i]))
        {
            cicli = cicli + medallas[i];
        }else if (!strcmp("Gimnasia",deport[i]))
        {
            gim = gim + medallas[i];
        }else if(!strcmp("Equitacion",deport[i]))
        {
            equi = equi + medallas[i];
        }else if (!strcmp("Esgrima",deport[i]))
        {
            esgri = esgri + medallas[i];
        }
    }

    printf("Las medallas por deporte son: \n");
    printf("Natacion: %d\n", nat);
    printf("Atletismo: %d\n", atle);
    printf("Ciclismo: %d\n", cicli);
    printf("Gimnasia: %d\n", gim);
    printf("Equitación: %d\n", equi);
    printf("Esgrima: %d\n", esgri);

     if(cerrado == EOF) //fclose regresa EOF cuando no se puede cerrar correctamente 
    {
        printf("El archivo no se cerró bien");
    }

    return 0;
}

