#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct lista
 {
    char nombre [20];
    int edad;
    char ciudad [20];
    struct lista *sigue;
 }datos,*inicio,*nuevo;

 void cargarlista_arch(struct lista** inicio);
 void verlista (struct lista *inicio);

int main()
{
    FILE* ptr;
    char c;
    if((ptr = fopen ("gente.txt", "wt"))==NULL){
        printf("No se pudo abrir el fichero de salida. \n");
        exit(1);
    }
        do{

        printf("\nIngrese sus datos:\n");
        printf("Nombre: ");
        scanf("%s", datos.nombre);
        fputs(datos.nombre, ptr);
        fputs("\n",ptr);

        printf("Edad: ");
        scanf("%d", &datos.edad);
        fprintf(ptr, "%d\n", datos.edad);

        printf("\Ciudad: ");
        scanf("%s", datos.ciudad);
        fputs(datos.ciudad, ptr);
        fputs("\n",ptr);

        printf("\nIngresar otro dato? s/n  ");
        getchar();
        c=getchar();
        } while ( c=='s');

        fclose(ptr);

 struct lista* inicio = NULL;
    cargarlista_arch(&inicio); // Pasar una referencia al inicio de la lista

    // Mostrar los datos cargados en la lista
    struct lista* current = inicio;
    while (current != NULL) {
        printf("Nombre: %s\nEdad: %d\nCiudad: %s\n\n", current->nombre, current->edad, current->ciudad);
        current = current->sigue;


    }
system("type gente.txt");
    return 0;
}

void cargarlista_arch(struct lista** inicio) {
 	FILE *ptrf;
    if((ptrf= fopen("gente.txt","rt"))==NULL){  //si da 0 va a tirar un error//
        printf("\nNo se pudo abrir el fichero de salida. \n");
        exit(1);
    }

	struct lista *aux;
    char nombre1 [20];
    int edad1;
    char ciudad1 [20];

    while (fscanf(ptrf, "%19s %3d %19s", nombre1, &edad1, ciudad1) == 3) {
        aux=malloc(sizeof(struct lista));
        strcpy(aux->nombre,nombre1);
        aux->edad = edad1;
        strcpy(aux->ciudad,ciudad1);

        aux->sigue=*inicio;
        *inicio=aux;
    }

    printf("\nArchivo cargado!\n");
    fclose (ptrf);
    return;
}

void verlista (struct lista *inicio)
{
    struct lista  *recorre;
    recorre=inicio; // pone recorre al ppio
    if(recorre)  // SI LA LISTA NO ESTA VACIA
    {
        printf("\n");
        while (recorre)  // MIENTRAS RECORRE APUNTE A UN NODO
        {
            printf("Nombre: %s\nEdad: %d\nCiudad: %s\n\n", recorre->nombre, recorre->edad, recorre->ciudad);
            recorre=recorre->sigue;
        }
        printf("\n");
    }
}

