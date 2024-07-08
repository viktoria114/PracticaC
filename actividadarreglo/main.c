#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    char arre[N];
    char arrenuevo[N];
    int vocal = 0;
    int consonante = 0;
    int i;

    printf("Ingrese 20 letras: ");
        scanf("%s",arre);

    printf("\nArreglo antes de la conversion: ");
    for(i=0;i<N;i++){
    printf("%c, ", arre[i]);
    }

        for(i=0;i<N;i++){
    if (arre[i]>96 && arre[i]<123){
        arrenuevo[i]=arre[i]-32;

    } else arrenuevo[i]= arre[i]+32;
    }

    printf("\nArreglo despues de la conversion: ");
           for(i=0;i<N;i++){
    printf("%c, ", arrenuevo[i]);

    if(arre[i]==97 || arre[i]==101 || arre[i]==105 || arre[i]==111 || arre[i]==117 || arre[i]== 65 || arre[i]==69 || arre[i]==73 || arre[i]==79 || arre[i]==85){
      vocal++;
    } else consonante++;
    }

    printf("\nCantidad de vocales: %d.\nCantidad de consonantes: %d",vocal,consonante);

    return 0;
}
