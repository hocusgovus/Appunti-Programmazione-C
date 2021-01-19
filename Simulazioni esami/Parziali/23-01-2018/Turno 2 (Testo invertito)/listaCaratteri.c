#include <stdio.h>
#include <stdlib.h>
#include "listaCaratteri.h"

void inizializzaLista(Lista* pList) {
	*pList = NULL;
}

void inserimentoTesta(char add, Lista* pList) {
	Nodo* new = (Nodo*)malloc(sizeof(Nodo));
	new->carattere = add;
	new->next = *pList;
	*pList = new;
}

void stampa(Lista list) {
	while(list != NULL) {
		printf("%c", list->carattere);
		list = list->next;
	}
}

void stampaUltimi(Lista l, int n) {
	//	Creo una copia della lista per contare quanti caratteri contiene
	Lista l2 = l;
	int caratteriTotali = 0;
	while(l2 != NULL) {
		caratteriTotali++;
		l2 = l2->next;
	}

	int pos = 0;
	while(l != NULL) {
		if(!(caratteriTotali-n > pos)) {
			printf("%c", l->carattere);
		}
		pos++;
		l = l->next;
	}
}