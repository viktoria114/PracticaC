#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LISTA SIMPLE CON INSERCION EN EL PPIO y eliminación al final*/
struct lista
{
    char palabra [20];  //dato a guardar en la lista
    struct lista *sigue; // campo de enlace al siguiente nodo
}*inicio,*nuevo;


void verlista (struct lista *);
void liblista(struct lista*);
void listainversa(struct lista *inicio);

int main()
{
    char palabra[20];  //string donde almacenaremos cada palabra nueva
    inicio = NULL;

    FILE* ptr;
    ptr = fopen("LavanderHaze.txt","r");  //abrir el archivo en modo lectura

        if (ptr == NULL) {
        printf("Error al abrir el archivo");  //si no se abre: error
        return 1;
    }

    while(fscanf(ptr, "%19s ", palabra) == 1)  //leemos el archivo desde el puntero, y almacenamos strings de hasta 19 caracteres en palabra. verificamos si es igual a uno
    { // ya que la funcion devuelve la cantidad de palabras con exito leidas. si es una palabra, la guardamos en un nodo.
        nuevo = (struct lista *)malloc(sizeof(struct lista));
        if (nuevo == NULL)
        {
            printf("Error al asignar memoria");
            return 1;
        }
        strcpy(nuevo->palabra, palabra);
        nuevo->sigue = inicio;
        inicio = nuevo;
    }

    fclose(ptr);
    verlista(inicio);
    printf("\n Ahora correctamente: \n\n");
    listainversa(inicio);
    liblista(inicio);
}

void verlista(struct lista *inicio)
{
    struct lista *aux = inicio;
    while (aux != NULL)
    {
        printf("%s ", aux->palabra);
        aux = aux->sigue;
    }
    printf("\n\n");
}
void liblista(struct lista *inicio)
{
    struct lista *aux;
    while (inicio != NULL)
    {
        aux = inicio;
        inicio = inicio->sigue;
        free(aux);
    }
}

void listainversa(struct lista *inicio)
{
    if (inicio == NULL)
        return; // La lista está vacía, no hay nada que imprimir.
    // Usamos recursión para imprimir la lista en orden inverso.
    listainversa(inicio->sigue);
    printf("%s ", inicio->palabra);
}
