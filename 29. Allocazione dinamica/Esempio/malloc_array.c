#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//	Richiedo la dimensione
	int dim;
	printf("Inserisci quanti valori vuoi sommare: ");
	scanf("%d", &dim);

	//	Creazione puntatore e allocazione memoria
	int *pa;
	pa = (int *) malloc(dim * sizeof(int));

	//	Assegnazione valore e somma
	int somma = 0;
	for(int i=0; i<dim; i++) {
		printf("Inserisi il valore n. %d: ", i+1);
		scanf("%d", &pa[i]);
		somma += pa[i];
	}

	//	Stampa valori e somma
	printf("\nValori inseriti: [");
	for(int i=0; i<dim-1; i++)
		printf("%d, ", pa[i]);
	printf("%d]", pa[dim-1]);
	printf("\nSomma: %d", somma);

	//	Libero la memoria
	free(pa);

	return 0;
}