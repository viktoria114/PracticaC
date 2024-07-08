#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
	FILE* prueba;  // puntero al descriptor del archivo
	prueba = fopen ( "prueba.txt", "w+" );
	if (prueba==0){   // o !prueba
        puts ("Error, no se abrio :(");
        return 1;
	}
	while (a!= '.'){
	a=getc(stdin); //stream input teclado
	putc (a,prueba);
	fflush (prueba);
	}
	fclose (prueba); //guardar y cerrar

	return 0;
}
