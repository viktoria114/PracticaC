// implementar quicksort

#include <stdio.h>

// funcion para intercambiar dos elementos
void intercambio(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// particionar el vector usando el ultimo elemento como referencia
int particionado(int arr[], int posComienzo, int posFinal)
{
	// elegir la referencia
	int pivot = arr[posFinal];

    // posicion del valor mas pequeño e indicar
    // la posicion derecha de la referencia encontrada hasta ahora
	int i = (posComienzo - 1);

	for (int j = posComienzo; j <= posFinal - 1; j++) {

        // si el valor actual es mas pequeño que la referencia
		if (arr[j] < pivot) {

            //incrementar la posicion del valor mas pequeño
			i++;
            //en posicion de vector i(comienzo) intercambiar con posicion de vector j(i-1)
			intercambio(&arr[i], &arr[j]);
		}
	}
	intercambio(&arr[i + 1], &arr[posFinal]);
	return (i + 1);
}

void quickSort(int arr[], int posComienzo, int posFinal)
{
	if (posComienzo < posFinal) {

		int posInicio = particionado(arr, posComienzo, posFinal);

		// ordenar los valores previos
		// particionar y particionar de nuevo
		quickSort(arr, posComienzo, posInicio - 1);
		quickSort(arr, posInicio + 1, posFinal);
	}
}

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };  //ta
	int tamano_vector = sizeof(arr) / sizeof(arr[0]); //ta
    //alt: arr[x][n] -> x*n= size of arr

	quickSort(arr, 0, tamano_vector - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < tamano_vector; i++)
		printf("%d ", arr[i]);
	return 0;
}
