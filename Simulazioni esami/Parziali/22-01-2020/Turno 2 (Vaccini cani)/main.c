#include <stdio.h>
#include <stdlib.h>
#include "listaCani.h"

int main(int argc, char* argv []) {
	//	Controllo argomenti
	if(argc != 2) {
		printf("Uso: %s vaccini.dat\nProgramma terminato.", argv[0]);
		exit(1);
	}

	//	Crea lista
	Lista listaListosa;
	inizializzaLista(&listaListosa);

	//	Importa cani
	FILE* file;
	if((file = fopen(argv[1], "rb")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma terminato.", argv[1]);
		exit(1);
	}
	Vaccino tmp;
	while(fread(&tmp, sizeof(Vaccino), 1, file) == 1)
		aggiorna(tmp, &listaListosa);
	fclose(file);

	//	Stampa
	stampa(listaListosa);

	//	Salvo tutti i cani in un file di testo
	esportaVaccini(listaListosa, "vaccinati.txt");

	return 0;
}