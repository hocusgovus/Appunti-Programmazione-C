#include <stdio.h>
#include <stdlib.h>
#include "listaCani.h"

void inizializzaLista(Lista* list) {
	*list = NULL;
}

void inserimentoTesta(Cane add, Lista* plist) {
	Nodo* new = (Nodo*) malloc(sizeof(Nodo));
	new->dato = add;
	new->next = *plist;
	*plist = new;
}

void aggiorna(Vaccino dog, Lista* plist) {
	//	Ricerca cane con numero chip
	while(*plist != NULL && (*plist)->dato.chip != dog.chip)
		plist = &(*plist)->next;

	//	Cane non presente, aggiungo in testa
	if(*plist == NULL) {
		Cane add;
		add.chip = dog.chip;
		add.cimurro = 0;
		add.epatite = 0;
		add.parvovirosi = 0;
		inserimentoTesta(add, plist);
	}

	switch(dog.vaccino) {
		case 'C': (*plist)->dato.cimurro = 1; break;
		case 'E': (*plist)->dato.epatite = 1; break;
		case 'P': (*plist)->dato.parvovirosi = 1; break;
	}
}

void stampa(Lista list) {
	while(list != NULL) {
		printf("%d: ", list->dato.chip);
		if(!list->dato.cimurro)
			printf("Cimurro ");
		if(!list->dato.epatite)
			printf("Epatite ");
		if(!list->dato.parvovirosi)
			printf("Parvovirosi");
		printf("\n");
		list = list->next;
	}
}

//	FUNZIONI PER ORDINAMENTO
int precede(Cane dog1, Cane dog2) {
	int nVacciniDog1 = dog1.cimurro + dog1.epatite + dog1.parvovirosi;
	int nVacciniDog2 = dog2.cimurro + dog2.epatite + dog2.parvovirosi;

	//	Se il numero di vaccini del primo cane è maggiore allora lo deve precedere
	if(nVacciniDog1 > nVacciniDog2) {
		return 1;
	}
	else if(nVacciniDog1 == nVacciniDog2) {
		//	Se il numero del primo cane è minore allora lo deve precedere (ordine crescente)
		if(dog1.chip < dog2.chip)
			return 1;
	}

	//	Se nessuna delle condizioni sopra è valida allora non deve precedere
	return 0;
}

void inserimentoOrdinato(Cane dog, Lista* plist) {
	while(*plist != NULL && !(precede(dog, (*plist)->dato)))
		plist = &(*plist)->next;
	inserimentoTesta(dog, plist);
}

void esportaVaccini(Lista list, char fileName[]) {
	//	Apro il file
	FILE* file;
	if((file = fopen(fileName, "w")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma terminato.", fileName);
		exit(1);
	}

	//	Creo una lista ordinata
	Lista listaOrdinata;
	inizializzaLista(&listaOrdinata);
	while(list != NULL) {
		inserimentoOrdinato(list->dato, &listaOrdinata);
		list = list->next;
	}

	//	Stampo i dati nel file
	while(listaOrdinata != NULL) {
		int nVaccini = listaOrdinata->dato.cimurro + listaOrdinata->dato.epatite + listaOrdinata->dato.parvovirosi;
		fprintf(file, "Cane %d con %d vaccini\n", listaOrdinata->dato.chip, nVaccini);
		listaOrdinata = listaOrdinata->next;
	}
	fclose(file);
}