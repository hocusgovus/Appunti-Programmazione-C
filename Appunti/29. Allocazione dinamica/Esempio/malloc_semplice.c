#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//	Creazione puntatore e allocazione memoria
	int *pa;
	pa = (int *)malloc(sizeof(int));

	//	Assegnazione valore e stampa
	*pa = 5;
	printf("%d", *pa);

	//	Libero la memoria
	free(pa);

	return 0;
}