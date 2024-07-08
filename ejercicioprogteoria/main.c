#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    char numeros [N];
    float a;
    int i;
    printf("Ingrese %d digitos!\n", N);

    for(i=0; i<N; i++)
    {
        numeros[i]= getchar();
        if (numeros[i]< '.' || numeros[i]== '/' || numeros[i]>'9')
            return 0;
    }
        a=(numeros[0]-48)*100;
        a=a+((numeros[1]-48)*10);
        a=a+(numeros[2]-48);
        a=a+((numeros[3]-48)*0.1);
        a=a+((numeros[4]-48)*0.01);

        printf("Numero: %0.2f, el doble: %0.2f, el cuadrado: %0.2f",a, a*2, a*a);

    return a;
}
