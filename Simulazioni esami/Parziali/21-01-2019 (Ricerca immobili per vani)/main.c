#include <stdio.h>
#include <stdlib.h>
#include "listaImmobili.h"

int main(int argc, char* argv[]) {
	//	Controllo argomenti
	if(argc != 2) {
		printf("Uso: %s immobili.dat\nProgramma terminato.", argv[0]);
		exit(1);
	}

	//	Creazione lista
	Lista listaListosa;
	inizializzaLista(&listaListosa);

	//	Lettura degli immobili dal file
	FILE* file;
	if((file = fopen(argv[1], "rb")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma terminato.", argv[1]);
		exit(1);
	}
	Immobile tmp;
	while(fread(&tmp, sizeof(Immobile), 1, file) == 1)
		inserimentoOrdinato(tmp, &listaListosa);
	fclose(file);

	//	Stampo gli immobili
	stampa(listaListosa);

	//	Richiedo quanti vani cercare e salvo gli immobili in listaOrdinata
	Lista listaOrdinata;
	inizializzaLista(&listaOrdinata);
	int nVani;
	printf("\nQuanti vani devono avere gli immobili da salvare: ");
	scanf("%d", &nVani);
	cercaImmobili(nVani, listaListosa, &listaOrdinata);

	//	Esporto listaOrdinata in vani.txt
	salvaLista(listaOrdinata, "vani.txt");
	printf("Vani salvati in vani.txt\nProgramma terminato.");

	return 0;
}