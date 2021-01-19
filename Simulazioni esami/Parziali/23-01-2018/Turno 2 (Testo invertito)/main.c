#include <stdio.h>
#include <stdlib.h>
#include "listaCaratteri.h"

int main(int argc, char* argv[]) {
	//	Controllo argomenti
	if(argc != 2) {
		printf("Uso: %s testo.txt\nProgramma terminato.", argv[0]);
		exit(1);
	}

	//	Inizializzazione lista
	Lista listaListosa;
	inizializzaLista(&listaListosa);

	//	Leggo il testo e lo stampo
	FILE* file;
	if((file = fopen(argv[1], "r")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma terminato.", argv[1]);
		exit(1);
	}
	char tmp;
	while(fscanf(file, "%c", &tmp) != EOF)
		inserimentoTesta(tmp, &listaListosa);
	fclose(file);
	stampa(listaListosa);
	
	//	Richiedo all'utente quanti caratteri mostrare
	int nCaratteri;
	printf("\n\nInserisci quanti caratteri finali mostrare: ");
	scanf("%d", &nCaratteri);
	stampaUltimi(listaListosa, nCaratteri);

	return 0;
}