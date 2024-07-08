#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 100
int person = 0;
int Index = -1;

typedef struct Info
{
    char nombre [80];
    char direccion [80];
    char correo [80];
    char telefono [15];
}info;

   void busqueda(info *card)
{
	int i;
	char nombre[32] = {0};
	Index = -1;
	printf("#Por favor ingresar un nombre:");
	scanf("%s", nombre);

	for (i = 0; i < person; i++)
	{
		if (strcmp(card[i].nombre,nombre) == 0)
		{
			Index = i;
			break;
		}
	}
}

void buscar(info *card)
{
	busqueda(card);

	if ( Index == -1)
	{
		printf("#¡No se encontro a esa persona!# \n");
		sleep(1);
	}
	else
	{
		printf("\t#Nombre: %s\t#Direccion: %s\t#Correo electronico: %s\t#Telefono: %s", card[Index].nombre,card[Index].direccion ,card[Index].correo, card[Index].telefono);
		sleep(2);
	}}

void alta(info *card)
{
    char nombre [80] = {0};
    char direccion [80] = {0};
    char correo [80] = {0};
    char telefono [15] = {0};

    busqueda(card);
	if (Index != -1)
	{
		printf("\t\t¡El contacto ya existe! \n");
	}
	else
	{

    printf("\nIngrese el nombre del registro: ");
    scanf("%s", nombre);
    printf("Ingrese la direccion del registro: ");
    scanf("%s", direccion);
    printf("Ingrese el correo del registro: ");
    scanf("%s", correo);
    printf("Ingrese el telefono del registro: ");
    scanf("%s", telefono);

    strcpy(card[person].nombre,nombre);
        strcpy(card[person].direccion,direccion);
		strcpy(card[person].correo,correo);
		strcpy(card[person].telefono,telefono);
		person++;

    printf("\n#Usted ha realizado un registro de forma correcta!#\n\n");
}}

void baja (info *card){

	int i;
	char ch = '\0';

	busqueda(card);

	if (Index == -1)
	{
		printf("¡No se encontro a esa persona! \n");
		sleep(1);
	}
	else

    printf("\n#Nombre: %s",card[Index].nombre);
    printf("\n#Direccion: %s",card[Index].direccion );
    printf("\n#Correo electronico: %s",card[Index].correo);
    printf("\n#Telefono: %s\n",card[Index].telefono);
    printf("\nEsta seguro de eliminar este registro (s/n)? ");
    getchar();
		ch = getchar();

		if (ch == 's')
		{
			if (Index != -1)
			{
				for (i = Index; i < person; i++)
				{
					strcpy(card[i].nombre,card[i + 1].nombre);
					strcpy(card[i].direccion,card[i + 1].direccion);
					strcpy(card[i].correo,card[i + 1].correo);
					strcpy(card[i].telefono,card[i + 1].telefono);
                    printf("\n#Registro eliminado!#\n\n");
				}
			}
			person--;
		}
	}

void modificacion(info *card)
{
    char nombre [80] = {0};
    char direccion [80] = {0};
    char correo [80] = {0};
    char telefono [15] = {0};
	Index = -1;
	busqueda(card);

	if (Index != -1)
	{
		printf("\nIngrese el nuevo nombre del registro:");
		scanf("%s",nombre);
		printf("Ingrese la nueva direccion del registro:");
        scanf("%s", direccion);
 		printf("Ingrese el nuevo correo del registro: ");
		scanf("%s", correo);
        printf("Ingrese el nuevo telefono del registro: ");
        scanf("%s", telefono);
		strcpy(card[Index].nombre, nombre);
		strcpy(card[Index].direccion, direccion);
		strcpy(card[Index].correo, correo);
		strcpy(card[Index].telefono, telefono);
	}
	else
	{
		printf("\t\t ¡No se encontro a esa persona! \ n");
		sleep(3);
	}
 }

void ver(info *card)
{
	int i;
	for (i = 0; i < person; i++)
	{

    printf("\n#Nombre: %s",card[i].nombre);
    printf("\n#Direccion: %s",card[i].direccion);
    printf("\n#Correo electronico: %s",card[i].correo);
    printf("\n#Telefono: %s\n\n",card[i].telefono);
	}
}

int main()
{
	info card[SIZE] = {0};
	int opcion = 0;

    do {
        printf("    ¡Registro Telefonico!\n\n");
        printf("(1) Alta de un registro\n");
        printf("(2) Baja de un registro\n");
        printf("(3) Buscar un registro\n");
        printf("(4) Ver registro completo\n");
        printf("(5) Modificar un registro\n");
        printf("(6) Salir\n");
        printf("(o) Ingrese su opcion: ");
		scanf("%d", &opcion);


        switch(opcion) {
            case 1: printf("\n# Opcion %i: Alta de un registro #\n",opcion);
                    alta(card);
            break;
            case 2: printf("\n# Opcion %i: Baja de un registro #\n",opcion);
                    baja (card);
            break;
            case 3:printf("\n# Opcion %i: Buscar un registro #\n",opcion);
                    buscar (card);

            case 4: printf("\n# Opcion %i: Ver registro completo #\n",opcion);
                    ver (card);
            break;
            case 5: printf("\n# Opcion %i: Modificar un registro #\n",opcion);
                    modificacion(card);

            break;
            case 6: printf("\n# Opcion %i: Saliendo... #\n",opcion);
                    exit(0);
            break;
            default: printf("\nOpcion incorrecta >:(\n\n");
            sleep(1);
            break;
        }

    }
    while(opcion !=6);
return 0;}



