#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 6;
    int b;
    b = num - 2;

    printf("Hello como andan!\na es: %d\nnum es: %d\n", b, num);

    int a;
    printf("Ingrese un numero:  ");
    scanf("%d",&a);
    printf("El numero ingresado es %d\n", a);

    if (a>10) printf("El numero ingresado es mayor que 10 :)");


    return 0;
}
