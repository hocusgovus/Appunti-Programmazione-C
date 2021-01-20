#include <stdio.h>
#include <stdlib.h>
#include "listaUtenti.h"

int main(int argc, char* argv[]) {
	//	Controllo argomenti
	if(argc != 3 && argc != 4) {
		printf("Uso: %s utenti.dat chiamate.txt (piani.dat)\nProgramma terminato.", argv[0]);
		exit(1);
	}

	//	Inizializza lista
	Lista listaListosa;
	inizializzaLista(&listaListosa);

	//	Importo i clienti dal file binario
	FILE* file;
	if((file = fopen(argv[1], "rb")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma termianto.", argv[1]);
		exit(1);
	}
	Cliente add;
	while(fread(&add,sizeof(Cliente), 1, file) == 1)
		inserisciCliente(add, &listaListosa);
	fclose(file);
	//stampaClienti(listaListosa);

	//	Se è presente un terzo argomento, importo i piani dal file
	Piano pianiPianosi[10];
	int nPiani = 0;
	if(argc == 4) {
		if((file = fopen(argv[3], "rb")) == NULL) {
			printf("Errore nell'apertura di %s\nProgramma termianto.", argv[3]);
			exit(1);
		}
		while(fread(&pianiPianosi[nPiani],sizeof(Piano), 1, file) == 1 && nPiani < 10)
			//printf("costoScattoRisposta = %f - durataScatto = %d - costoScatto = %f\n", pianiPianosi[nPiani].costoScattoRisposta, pianiPianosi[nPiani].durataScatto, pianiPianosi[nPiani].costoScatto);
			nPiani++;
		fclose(file);
	}

	//	Leggo il registro di chiamate
	if((file = fopen(argv[2], "r")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma termianto.", argv[2]);
		exit(1);
	}
	char numero[11];
	int tempo;
	while(fscanf(file,"%s %d\n", numero, &tempo) != EOF)
		switch(decrementaCredito(numero, tempo, pianiPianosi, nPiani, &listaListosa)) {
			case 1: printf("Cliente %s non trovato\n", numero); break;
			case 2: printf("Piano del cliente %s non valido\n", numero); break;
			default: break;
		}

	//	Stampo il credito dei clienti
	stampaClienti(listaListosa);

	return 0;
}