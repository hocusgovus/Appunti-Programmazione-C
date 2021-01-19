#include <stdio.h>
#include <stdlib.h>
#include "listaPersone.h"

void inizializzaLista(Lista* pList) {
	*pList = NULL;
}

void inserimentoTesta(Persona add, Lista* pList) {
	Nodo* new = (Nodo*)malloc(sizeof(Nodo));
	new->dato = add;
	new->next = *pList;
	*pList = new;
}

void inserimentoOrdinato(Persona add, Lista* pList) {
	while(*pList != NULL && add.anno > (*pList)->dato.anno)
		pList = &(*pList)->next;

	inserimentoTesta(add, pList);
}

void stampa(Lista list) {
	while(list != NULL) {
		printf("%s %d\n", list->dato.nome, list->dato.anno);
		list = list->next;
	}
}

int natiEntro(Lista l, int a) {
	int count = 0;

	while(l != NULL) {
		if(l->dato.anno <= a)
			count++;
		l = l->next;
	}
	return count;
}