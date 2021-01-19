#include <stdio.h>
#include <stdlib.h>
#include "listaPersone.h"

int main(int argc, char* argv[]) {
	//	Controllo argomenti
	if(argc != 2) {
		printf("Uso: %s persone.dat\nProgramma terminato.", argv[0]);
		exit(1);
	}

	//	Inizializzazione lista
	Lista listaListosa;
	inizializzaLista(&listaListosa);

	//	Importo le persone dal file dat
	FILE* file;
	if((file = fopen(argv[1], "rb")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma terminato.", argv[1]);
		exit(1);
	}
	Persona tmp;
	while(fread(&tmp, sizeof(Persona), 1, file) == 1)
		inserimentoOrdinato(tmp, &listaListosa);
	fclose(file);

	//	Stampo il risultato
	stampa(listaListosa);

	//	Cerco i nati entro un valore richiesto
	int a;
	printf("\nInserisci l'anno entro cui le persone devono essere nate: ");
	scanf("%d", &a);
	printf("Sono nate %d persone entro il %d.", natiEntro(listaListosa, a), a);

	return 0;
}