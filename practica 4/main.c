#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <string.h>

/*Escriba un programa que permita crear una lista de palabras y que,
a continuación, pida dos palabras y sustituya la primera por la segunda en la lista.*/

struct lista {
char palabra [20];
struct lista *sigue;
}*inicio,*nuevo,*aux;


void verlista (struct lista *);
void liblista(struct lista*);
int tamano = sizeof(struct lista);

int main()
{
char a [20];
char b [20];
char c [20];
inicio = NULL;
do{
printf("Ingrese palabras hasta el punto \n");
        scanf("%s",a);
        if (strcmp(a, ".") != 0)
	{
	nuevo=(struct lista*)malloc(sizeof(struct lista));
	strcpy(nuevo->palabra, a);
	if ((inicio==NULL)||(strcmp(nuevo->palabra, inicio->palabra) <= 0))
            {
			nuevo->sigue=inicio;
			inicio=nuevo;
			}
	else
	{
	aux=inicio;
    // aux->sigue!=NULL

	while((aux->sigue) && (strcmp(nuevo->palabra, (aux->sigue)->palabra) >= 0))
			aux=aux->sigue;
	nuevo->sigue=aux->sigue;
	aux->sigue=nuevo;
	}
	verlista(inicio);
	}
	} while( strcmp(a, ".") != 0);
printf("\n\n");
verlista(inicio);


printf("\nIngrese la palabra a reemplazar: ");
scanf("%s",b);
printf("\nIngrese la nueva palabra: ");
scanf("%s",c);

aux=inicio;
do{
if(strcmp(aux->palabra, b)==0){
    strcpy(aux->palabra, c);
} else aux=aux->sigue;
} while (aux!= NULL);

printf("\n\n");
verlista(inicio);

liblista(inicio);
getch();


return(0);
}


void verlista (struct lista *inicio)
{
struct lista* recorre;
recorre=inicio;
printf("---------");
while (recorre)
	{
	printf("%s - ",recorre->palabra);
	recorre=recorre->sigue;
	}
printf("\n");
//getch();
}

void liblista (struct lista* inicio)
{
struct lista *aux;
//printf("\nMemoria  disponible  %u \n",coreleft());
while (inicio)
	{
	aux=inicio;
	inicio=inicio->sigue;
	free(aux);
	}
//printf("\nMemoria disponible tras eliminar la lista %u",coreleft());
getch();
}


