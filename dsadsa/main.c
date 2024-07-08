
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 31

struct NODO
 {
    char dato;
    struct NODO *next;
 } ;

struct NODO_2
 {
    char nombre [N];
    struct NODO_2 *next;
 } ;

void liblista (struct NODO**); //LIBEARA LISTA
void verlista (struct NODO *); //imprecion de NODOs con carcateres de forma ORDENADA
void veratsil (struct NODO *); //imprecion de NODOs con carcateres al REVEZ
void verlista_n (struct NODO_2 *); //imprecion de NODOs con PALABRAS de forma ORDENADA
void verlistar (struct NODO*);// recursiva??
// archivo-lista para nodos con PALABRAS
void cargarlista_arch (struct NODO_2 **);
void guardalista_arch(struct NODO_2 *);
//inserciones
void nombrelista (struct NODO_2 **); //lista de nombre con incersion al principio
void inser_ordenada (struct NODO **);
void inser_inicio (struct NODO **);
void inser_final (struct NODO **);
void push (char c,struct NODO **);
struct NODO * pop (struct NODO **);

int main (){
    struct NODO *lista=NULL;
    return 0;
}

void liblista (struct NODO **lista) //LIBEARA LISTA
{
struct NODO *aux;
//printf(“\nMemoria  disponible  %u \n”,coreleft());
    while (*lista)
	{
	    aux=(*lista);
	    (*lista)=(*lista)->next;
	    free(aux);
	}
    puts("\n \n ***LISTA LIBERADA*** \n");
//printf(“\nMemoria disponible tras eliminar la lista %u”,coreleft());
}

void verlista (struct NODO *lista){ //imprecion de NODOs con carcateres de forma ORDENADA
    struct NODO* recorre;
    recorre=lista;

    if (recorre){
        printf("->");
        while (recorre){
	        printf("%c->",recorre->dato);
            recorre=recorre->next;
	    }
        printf("->NULL\n");
    }
    else{
        printf("---------***LISTA VACIA***----------\n");
    }
//getch();
    return;
}

void veratsil(struct NODO *lista){ //imprecion de NODOs con carcateres al REVEZ
    struct NODO* recorre;
    recorre=lista;
    if(recorre==NULL) printf("NULL");
    else{
    printatsil(recorre->next); printf("<-%c",recorre->dato);
    }
return;
}

void verlista_n (struct NODO_2 *lista) //imprecion de NODOs con PALABRAS
{
    struct NODO_2  *recorre;
    recorre=lista; // pone recorre al ppio
    if(recorre)  // SI LA LISTA NO ESTA VACIA
    {
        printf("\n");
        while (recorre)  // MIENTRAS RECORRE APUNTE A UN NODO
        {
            puts(recorre->nombre);
            recorre=recorre->next;
        }
        printf("\n");
    }
}

void verlistar (struct NODO*recorre)  // recursiva??
{
	printf("\n");
	if (recorre)
	{
		verlista(recorre->next);
		printf("%c", recorre->dato); //IMPRIME EN LA FORMA QUE INGRESO

	}
}
//---------------------------------------
void cargarlista_arch (struct NODO_2 **lista){ //Archivo-->Lista - Crea un lista con los elementos que hay en un Archivo

	FILE *ptrf;
    if((ptrf= fopen("Parcial_2.txt","rt"))==NULL){  //si da 0 va a tirar un error//
        printf("\n \n No se pudo abrir el fichero de salida. \n");
        exit(1);
    }

	struct NODO_2 *aux;
	char palabra[N];
    while (!feof(ptrf))
    {
        fscanf(ptrf,"%s",palabra); //pasa los del archivo a palabra
        aux=malloc(sizeof(struct NODO));
        strcpy(aux->nombre,palabra);
        aux->next=*lista;
        *lista=aux;
    }

    printf("\n \n ***ARCHIVO CARGADO A LA LISTA*** \n");
    fclose (ptrf);
    return;
}

void guardalista_arch(struct NODO_2 *lista)  //Lista-->Archivo
{
    FILE *ptrf;
    if( (ptrf = fopen( "Parcial_2.txt", "wt" )) == NULL ) //wt escritura texto (sobrescribe) - at añadir texto (no sobrescribe)
        printf("No pude abrir el archivo \n" );

    struct NODO_2  *recorre;
    recorre=lista; // pone recorre al ppio
    if(recorre)  // SI LA LISTA NO ESTA VACIA
    {

        while (recorre)  // MIENTRAS RECORRE APUNTE A UN NODO
        {
            fputs(recorre->nombre,ptrf);
            fputs("\n",ptrf);
            recorre=recorre->next;
        }
        printf("\n");
    }
    fclose(ptrf);
}
//---------------------------------------
void nombrelista (struct NODO_2 **lista){ //lista de nombre con incersion al principio

    char nombre_s[N];
    struct NODO_2 *nuevo, *aux;
    do
    {
        printf("Ingrese palabras sale con FIN \n");
        scanf("%s", nombre_s);
        if (strcmp(nombre_s, "FIN") != 0)
        {
            nuevo=malloc(sizeof(struct NODO_2));
            strcpy(nuevo->nombre, nombre_s);
            nuevo->next=lista;
            lista=nuevo;
        }
    }while( strcmp(nombre_s, "FIN") != 0);

    aux=lista;
    printf("lista-->");
    while(aux){
        printf("%s-->",aux->nombre);
        aux=aux->next;
    }
puts("NULL");
return;
}

void inser_ordenada (struct NODO **lista){
    char a;
    struct NODO *nuevo, *aux, *recorre;

    printf ("¡¡Bien venido a la lista ordenad!! \n-Precione cualquier letra MINUSCULA para anadir a la lista \n-Precione cualquier MAYUSCULA para eliminar su minuscula de la lista \n-Precione '.' para liberar la lista y salir \n\n");
     while ((a=getch())!='.'){
        if (a >= 'a' && a <= 'z'){
            nuevo=(struct NODO*)malloc(sizeof(struct NODO));
            nuevo->dato=a;
            if (((*lista)==NULL)||(nuevo->dato)<=((*lista)->dato)){
                nuevo->next=lista;
                lista=nuevo;
			}
            else{
                aux=lista;
                while((aux->next) && ((nuevo->dato>=(aux->next)->dato))) aux=aux->next;
                nuevo->next=aux->next;
                aux->next=nuevo;
            }
        }
        else if (a >= 'A' && a <= 'Z' && (*lista)!=NULL){
            a = a + 32;
            if ((*lista) != NULL && ((*lista)->dato) == a){
                aux = lista;
                (*lista) = (*lista)->next;

                free(aux);
            }
            else {
                recorre = (*lista);
                while (recorre->next != NULL && (recorre->next)->dato != a) recorre = recorre->next;
                if(recorre->next == NULL){
                }
                else if ((recorre->next)->dato == a){
                    aux = recorre->next;
                    recorre->next = (recorre->next)->next;
                    free(aux);
                }
            }


	}

	verlista(lista);

}
	return ;
}

void inser_inicio (struct NODO **lista){
        struct NODO *aux=lista;
        char c;

        while((c=getchar())!='\n'){
            aux=(struct NODO*)malloc(sizeof(struct NODO));
            aux->dato=c;
            aux->next=(*lista);
            (*lista)=aux;
            verlista(*lista);
        }

        /*aux=lista;
        printf("lista-->");
        while(aux){
            printf("%c-->",aux->dato);
            aux=aux->next;
        }
        puts("NULL");*/
        return;

}

void inser_final (struct NODO **lista){
   struct NODO *aux=lista, *recorre;
    char c;
    while((c=getchar())!='\n'){
        aux=(struct NODO*)malloc(sizeof(struct NODO));
        aux->dato=c;
        aux->next=NULL;
        if (*lista==NULL){
            (*lista)=aux;
        }
        else{
            recorre=(*lista);
            while(recorre->next!=NULL){
                recorre=recorre->next;
            }
            recorre->next=aux;
        }
        verlista(*lista);
    }
}

void push(char c,struct NODO** lista) { //insercion al final desde main
    struct NODO * nuevo;
    nuevo=(struct NODO*)malloc(sizeof(struct NODO));
    nuevo->dato=c;
    nuevo->next=*lista;
    *lista=nuevo;
}

struct NODO * pop (struct NODO**l){ //eliminacion desde main
    struct NODO * aux=*l;
    if(aux) (*l)=(*l)->next;
    else puts("\nNo hay nodo");
    return aux;
} // aux=pop(lista); free (aux);
