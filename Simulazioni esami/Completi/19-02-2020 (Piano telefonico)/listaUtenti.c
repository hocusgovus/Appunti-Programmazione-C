#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

void inizializzaLista(Lista* pList) {
	*pList = NULL;
}

void inserimentoTesta(Cliente add, Lista* pList) {
	Nodo* new = (Nodo*)malloc(sizeof(Nodo));
	if(new == NULL) {
		printf("Errore di allocazione di memoria\nProgramma terminato.");
		exit(2);
	}
	new->dato = add;
	new->next = *pList;
	*pList = new;
}

void inserisciCliente(Cliente add, Lista* pList) {
	while(*pList != NULL && strcmp(add.numero, (*pList)->dato.numero) > 0)
		pList = &(*pList)->next;
	inserimentoTesta(add, pList);
}

void stampaClienti(Lista list) {
	while(list != NULL) {
		printf("%s %.2f\n", list->dato.numero, list->dato.credito);
		list = list->next;
	}
}

int decrementaCredito(char numero[11], int tempo, Piano tariffe[], int nTariffe, Lista* pList) {
	while(*pList != NULL && strcmp(numero, (*pList)->dato.numero) != 0)
		pList = &(*pList)->next;
	//	Se il cliente non viene trovato ritorna 1
	if(*pList == NULL)
		return 1;

	//	Calcolo prezzo
	float costoChiamata = 0;

	
	//	È stato importato il file con i piani, uso quelli
	if(nTariffe > 0) {
		int pianoAttuale = (*pList)->dato.piano - 65;

		//	Se il numero di piano non è valido con quelli presenti allora esci
		if(pianoAttuale>nTariffe)
			return 2;

		//	Segue il formato del piano B
		if(tariffe[pianoAttuale].costoScattoRisposta == 0 && tariffe[pianoAttuale].durataScatto == 0)
			costoChiamata = tariffe[pianoAttuale].costoScatto / 60 * tempo;
		else
			//	Segue il formato del piano A
			costoChiamata = tariffe[pianoAttuale].costoScattoRisposta + tariffe[pianoAttuale].costoScatto * (tempo / tariffe[pianoAttuale].durataScatto + 1);

	}
	else {
		//	Se non sono stati importati dei piani, uso quelli di default
		switch((*pList)->dato.piano) {
			case 'A': costoChiamata = 0.15 + 0.08 * (tempo / 60 + 1); break;
			case 'B': costoChiamata = 0.12 / 60 * tempo; break;
			default: return 2;
		}
	}

	//	Arrotondo il costo per difetto
	costoChiamata = ((int)(costoChiamata * 100) / 100.0);
	(*pList)->dato.credito -= costoChiamata;

	return 0;
}