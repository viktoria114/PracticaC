#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a [20];
    char b [20];

    puts("Nombre?\n");
    gets(a); //solo acepta chars y es mas simple
    printf("\nApellido?\n");
    scanf("%s",b); //acepta todo tipo de datos pero hay que escpecificar
    printf("\nTe registraste como %s %s en el sistema!\n\n", a,b);
    system("pause");


    return 0;
}
