#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    int *punta, *puntb, *puntc;   //puntero es una variable que guarda la posicion de memoria en hexadecimal
                        // siempre apuntan a el primer elemento ¿porque se declara int si siempre es igual el puntero?
    punta = &a;
    puntb = &b;
    puntc = &c;

    printf("Ingrese dos numeros pls:\n");
    scanf("%d", punta);
    scanf("%d", puntb);   //asterisco es donde estoy apuntando es decir puntb apunta a b

    *puntc = *punta + *puntb;

    printf("Resultado: %d\n", *puntc);

    short int i, j, arre[5];
    short int *p, *k, *r;
    p=arre;  //p=&arre[0] punta al primer elemento

    for (i=0; i<5;i++){
        printf("\nElemento %d en (Posicion %p): ", i+1, p);
        scanf ("%d",p++);
        //p = &arre[i];  intento fallido jaja
    }

    for (i=0; i<5;i++)
        printf("\nElemento o. N %d en (Posicion %p): %d", i+1, p, arre[i]);
 //   for (i=4; i>=0;i--)   se puede usar el nomarl y usar punteros
    p--; //vuelvo al 5to...

    for(i=0; i<5; i++)
    {
        printf("\nElemento valor %d pos %p",*p,p);
        p--;
    }

    return 0;
}
