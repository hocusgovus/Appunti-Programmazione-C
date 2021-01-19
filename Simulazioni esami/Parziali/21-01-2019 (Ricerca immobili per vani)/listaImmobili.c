#include <stdio.h>
#include <stdlib.h>
#include "listaImmobili.h"

void inizializzaLista(Lista* pList) {
	*pList = NULL;
}

void inserimentoTesta(Immobile add, Lista* pList) {
	Nodo* new = (Nodo*) malloc(sizeof(Nodo));
	new->dato = add;
	new->next = *pList;
	*pList = new;
}

void inserimentoOrdinato(Immobile add, Lista* pList) {
	while(*pList != NULL && add.distanza > (*pList)->dato.distanza)
		pList = &(*pList)->next;
	inserimentoTesta(add, pList);
}

void stampa(Lista list) {
	while(list != NULL) {
		printf("%s %d %.3f\n", list->dato.indirizzo, list->dato.vani, list->dato.distanza);
		list = list->next;
	}
}

int precede(Immobile casina1, Immobile casina2) {
	if(casina1.vani > casina2.vani)
		return 1;
	else if(casina1.vani == casina2.vani && casina1.distanza < casina2.distanza)
		return 1;
	return 0;
}

void inserimentoOrdinatoVani(Immobile add, Lista* pList) {
	while(*pList != NULL && !(precede(add, (*pList)->dato))) {
		pList = &(*pList)->next;
	}
	inserimentoTesta(add, pList);
}

void cercaImmobili(int nVani, Lista input, Lista* output) {
	while(input != NULL) {
		if(input->dato.vani >= nVani) {
			inserimentoOrdinatoVani(input->dato, output);
		}
		input = input->next;
	}
}

void salvaLista(Lista list, char fileName[]) {
	FILE* file;
	if((file = fopen(fileName, "w")) == NULL) {
		printf("Errore nell'apertura di %s\nProgramma terminato.", fileName);
		exit(1);
	}

	while(list != NULL) {
		fprintf(file, "%s %d %.3f\n", list->dato.indirizzo, list->dato.vani, list->dato.distanza);
		list = list->next;
	}
	fclose(file);
}