#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
    int numE[N];
    int numN[N];
    char letrasM[N];
    float numRD[N];
    float numRC[N];
    int i;

    printf("\tMuchos arreglos aleatorios!\n");

    srand(time(NULL));
    for(i = 0; i<N ; i++)
    {
        numE[i]=-50+rand()%31;
        numN[i]=30+rand()%31;
        letrasM[i]=65+rand()%26;
        numRD[i]=(float) 100 + 0.1 * (rand()%501);
        numRC[i]=(float) -1 + 0.01* (rand()%101);

    }

    printf("\nArreglo1: ");
    for(i = 0; i<N ; i++) printf("%d, ",numE[i]);
    printf("\nArreglo2: ");
    for(i = 0; i<N ; i++) printf("%d, ",numN[i]);
    printf("\nArreglo3: ");
    for(i = 0; i<N ; i++) printf("%c, ",letrasM[i]);
    printf("\nArreglo4: ");
    for(i = 0; i<N ; i++) printf("%.1f, ",numRD[i]);
    printf("\nArreglo5: ");
    for(i = 0; i<N ; i++) printf("%.2f, ",numRC[i]);


    return 0;
}
