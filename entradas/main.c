// venta de entradas <algo> concierto
// formato de entradas: <tipo de entrada, nombre de casa de venta, numero de ticket y/o id, asciento, hora y fecha>

/*
1_
crear evento
listar los disponibles
poder seleccionarlos
poder borrarlos
2_
vender asientos
comprobar si x asiento esta vendido o no
*/

//espacio de trabajo abajo

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define constante 100
#define max_eventos 5

typedef struct
{
    int tipo_entrada;
    int asiento;
    int hora_vta;
    int fecha_vta;
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];
}boleto;

typedef struct
{
    int numero;
    char nombre[constante];
}evento;

int total=0;    //no se que hará aun

//<retorno> <nombre variable> (<parametros>)
int numero_asientos(void);
void status(char a[]);
//evento manipulacion
evento menu_eventos(int a);
evento CrearEvento(int a, int b);
void ListarEvento(evento x[], int a);
int SeleccionarEvento(int a, int b);
//evento operativo
void menu_boletos(int a, int b, int c, int d, evento e[]);

int main(){
    printf("\t----------Bienvenido a VentaOnlineUwU!!----------");
    menu_eventos(numero_asientos());

    return 0;
}

int numero_asientos(void){
    int asientos;
    printf("\n Ingrese el numero de asientos de los cuales dispone para vender entradas: ");
    scanf("%d", &asientos);
    return asientos;
}

//escribir estatus de cierta parte del programa
void status(char a[]){
    printf("%s", a);
}
//selector de operaciones entre eventos
evento menu_eventos(int a){
    status("\n\t\tEventos: manipulacion\n");
    int asientos_total=a, seleccion=0;
    int opcion,total_eventos=0;
    evento un_evento[max_eventos];  //eventos disponibles

    while (opcion!=5)
    {
        printf("\nEventos disponibles %i de %i eventos, que desea realizar? ", total_eventos, max_eventos);

        printf("\n1. Crear evento\n");
        printf("2. Listar eventos\n");
        printf("3. Seleccionar un evento\n");
        printf("4. Modificar evento\n");
        printf("5. Apagar sistema\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

   	 	switch(opcion)
   	 	{
    		    case 1:
    		    un_evento[total_eventos]=CrearEvento(total_eventos, max_eventos);
    		    total_eventos++;            //se creó un evento
                    break;
     	  	 case 2:
                ListarEvento(un_evento, total_eventos);
                    break;
     	  	 case 3:
                ListarEvento(un_evento, total_eventos);
                seleccion=SeleccionarEvento(total_eventos, max_eventos);
                /*
                esta funcion requiere de:

                -evento seleccionado = (seleccion)
                -numero de asientos = (asientos_total)
                -numero de eventos creados = (total_eventos)
                -maximo de eventos que la empresa puede manejar = (max_eventos)
                -vector que contiene numero "id" y un nombre = un_evento
                */
                menu_boletos(seleccion, asientos_total, total_eventos, max_eventos, un_evento);     //se llevo a cabo la seleccion, continuar en menu_boletos()
                    break;
            case 4:


                break;
            case 5:
                break;
       		 default:
                printf("Opcion incorrecta\n");
                    break;
   	 	}
    }
}
evento CrearEvento(int a, int b){
    evento informacion;
    system("cls");
    printf("\nIngrese el nombre del evento %i: ", a+1);
    scanf("%s", informacion.nombre);
    //aqui numero=a+1 ya que se quiere mostrar opciones de 1 hasta max_eventos en lugar de 0 hasta max_eventos
    informacion.numero=(a+1);

    return informacion;
}
void ListarEvento(evento x[], int a){
    system("cls");
    printf("\nListado de eventos: ");
    for(int i=0;i<a;i++){
        printf("\n %i: %s", x[i].numero, x[i].nombre);
    }
    printf("\n");
}
int SeleccionarEvento(int a, int b){
    int seleccion;

    //verificar que el evento exista "no ser menor a cero o mayor a los eventos creados"
    do{
        printf("\nSeleccione un evento de %i/%i: ", a, b);
        scanf("%d", &seleccion);
        system("cls");

    }while(seleccion<0 || seleccion>a);
}

void menu_boletos(int a, int b, int c, int d, evento e[]){
    status("\n\t\tEventos: operativo\n");
    printf("\nSu seleccion fue el evento: [%i] Nombre: %s!\n", a, e[a-1].nombre);
    int opcion;
    evento evento_caracteristicas[max_eventos];
    //todo lo interno de un evento (ventas, tiempo, asientos disponibles, etc.)

    printf("\nTotal de entradas actuales %d \n", b);
    while (opcion!=4)
    {
        printf("\nVenta de Entradas! Que accion va a realizar?\n");

        printf("1. Vender un boleto\n");
        printf("2. Cancelar la venta de un boleto\n");
        printf("3. Listar boletos\n");
        printf("4. Volver\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        printf("\n*________________________________________________________________________________________________________*");

   	 	switch(opcion)
   	 	{
    		    case 1:
                //cargar();
                    break;
     	  	 case 2:
                //modificar();
                    break;
       		 case 3:
                //listarboletos();
                    break;
       		 case 4:
       		     system("cls");
                    break;
       		 default:
                printf("Opcion incorrecta\n");
                    break;
   	 	}
    }
}
boleto VenderBoletos(int a){
    printf("\n\n*******Ventas de Entrada*******");

    printf("\nIngrese el tipo de entrada");
    scanf("%s", entrada[total].tipo_entrada);
    entrada[total].id=total+1;

    printf("\nIngrese el numero de asiento del boleto [%d]: ", entrada[total].id);
    scanf("%d", entrada[total].asiento);

    printf("\nIngrese el precio del boleto [%d]: ", entrada[total].id);
    scanf("%f", &entrada[total].precio);

   // printf("\nIngrese el nombre del Evento");
   // scanf("%s", entrada[total].evento);

    boleto.evento = e[a-1];

    print("\nIngrese el nombre de Casa de Venta");
    scanf("%s", entrada[total].nombre_casa_venta);

    total++;

}*/



