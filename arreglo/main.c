#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arre[10];
    int vocal = 0;
    int consonante = 0;
    int i;

    //20 caracteres ingresados por teclado y mostrarlos al inverso de su ingreso
    for(i=0;i<10;i++){
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c",&arre[i]);

    if(arre[i]==97 || arre[i]==101 || arre[i]==105 || arre[i]==111 || arre[i]==117 || arre[i]== 65 || arre[i]==69 || arre[i]==73 || arre[i]==79 || arre[i]==85){
      vocal++;
    } else consonante++;
    }

    printf("\nCantidad de vocales: %d.\nCantidad de consonantes: %d",vocal,consonante);

    printf("\nArreglo antes de la conversion:");
    for(i=0;i<10;i++){
    printf("%c, ", arre[i]);
    }

        for(i=0;i<10;i++){
    if (arre[i]>=97 && arre[i]<=122);
        arre[i]=arre[i]-(32);

    if (arre[i]>=65 && arre[i]<=90);
        arre[i]= arre[i]+(32);
    }

    printf("\nArreglo despues de la conversion:");
           for(i=0;i<10;i++){
    printf("%c, ", arre[i]);
           }


    //errores comunes: poner un ; despues del if y olvidar de cerrar el []
        // ejemplo de punto de encuentro de fisica con el ciclo for


    return 0;
}
