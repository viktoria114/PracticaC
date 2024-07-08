#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1[20];
    int num2[20];
    char letras[20];
    float num3[20];
    float num4[20];
    int i;

    // Generar n�meros aleatorios entre -50 y -20 para el arreglo num1
    srand(time(NULL));
    for(i = 0; i < 20; i++) {
        num1[i] = (rand() % 31) - 50;
    }

    // Generar n�meros naturales aleatorios entre 30 y 60 para el arreglo num2
    for(i = 0; i < 20; i++) {
        num2[i] = (rand() % 31) + 30;
    }

    // Generar letras aleatorias may�sculas para el arreglo letras
    for(i = 0; i < 20; i++) {
        letras[i] = (rand() % 26) + 65;
    }

    // Generar n�meros reales aleatorios entre 100 y 150 con d�cimas para el arreglo num3
    for(i = 0; i < 20; i++) {
        num3[i] = ((float)rand()/(float)(RAND_MAX)) * 50 + 100;
    }

    // Generar n�meros reales aleatorios entre -1 y 0 con cent�simas para el arreglo num4
    for(i = 0; i < 20; i++) {
        num4[i] = ((float)rand()/(float)(RAND_MAX)) * 1 - 1;
    }

    // Imprimir cada arreglo
    printf("Arreglo num1:\n");
    for(i = 0; i < 20; i++) {
        printf("%d ", num1[i]);
    }
    printf("\n");

    printf("Arreglo num2:\n");
    for(i = 0; i < 20; i++) {
        printf("%d ", num2[i]);
    }
    printf("\n");

    printf("Arreglo letras:\n");
    for(i = 0; i < 20; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");

    printf("Arreglo num3:\n");
    for(i = 0; i < 20; i++) {
        printf("%.1f ", num3[i]);
    }
    printf("\n");

    printf("Arreglo num4:\n");
    for(i = 0; i < 20; i++) {
        printf("%.2f ", num4[i]);
    }
    printf("\n");

    return 0;
}
