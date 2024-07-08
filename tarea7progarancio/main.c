#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pun;
    char a [1000];
    int i, o;

    if ((pun = fopen("CLASE308.txt","wt"))==NULL)
        {
            printf("No puede abrir el fichero de salida.\n");
            exit(1);
        }

    printf("\nCuantas oraciones desea guardar?  ");
    scanf("%d",&o);
    getchar();

    printf("\nIngrese las oraciones que quiere guardar:\n");
    for(i=0; i<o; i++){
            fgets(a, sizeof(a), stdin);
            fputs(a,pun);
        }

        fclose(pun);

        pun = fopen("CLASE308.txt","rt");
        printf("\nTexto dentro del archivo:\n");

        while (fgets(a, sizeof(a), pun) != NULL) {
        printf("%s", a);
    }

        fclose (pun);
    return 0;
}
