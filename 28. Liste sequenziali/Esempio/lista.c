#include<stdio.h>
#include "lista.h"

//	newList: inizializza nuova lista
void newList(Lista* list) {
	list->nElem = 0;
}

//	Size: ritorna la dimensione logica della lista (nElem)
int size(Lista list) {
	return list.nElem;
}

//	isEmpty: ritorna 1 se è vuota oppure 0 se non lo è
int isEmpty(Lista list) {
	if(list.nElem==0)
		return 1;
	return 0;
}

//	isFull: ritorna 1 se è piena oppure 0 se non lo è
int isFull(Lista list) {
	if(list.nElem==DIM)
		return 1;
	return 0;
}

//	contains: ritorna 1 se il valore passato è contenuto nella lista
int contains(int searchValue, Lista list) {
	for(int i=0; i<list.nElem; i++)
		if(list.dati[i]==searchValue)
			return 1;
	return 0;
}

//	add: aggiunge in coda il valore passato
//	Ritorna 0 se riesce oppure 1 se la lista è piena
int add(int addValue, Lista* list) {
	if(list->nElem == DIM)
		return 1;
	list->dati[list->nElem] = addValue;
	list->nElem++;
	return 0;
} 

//	remove: rimuove la prima occorrenza del valore passato dall'array
//	Ritorna 0 se riesce oppure 1 non viene trovato il valore
int removeValue(int removeValue, Lista* list) {
	for(int i=0; i<list->nElem; i++)
		if(list->dati[i]==removeValue) {
			//	Valore trovato, scalare quelli successivi indietro di 1
			for(int j=i; j<list->nElem; j++)
				list->dati[j] = list->dati[j+1];
			list->nElem--;
			return 0;
		}
	return 1;
}

//	clear: azzera la lista
void clear(Lista* list) {
	list->nElem = 0;
}

//	get: ritorna la posizione della prima occorrenza del valore passato
//	Ritorna -1 se non presente
int get(int searchValue, Lista list) {
	for(int i=0; i<list.nElem; i++)
		if(list.dati[i]==searchValue)
			return i;
	return -1;
}

//	set: salva il valore passato per primo nella poszione indicata come secondo valore, se possibile
//	Ritorna -1 se fallisce (Es: posizione > DIM oppure il valore della posizione è < di DIM ma superiore a nElem)
int set(int addValue, int position, Lista* list) {
	if(position>list->nElem)
		return -1;
	list->dati[position] = addValue;
	return 0;
}

//	print: stampa tutti i valori nella lista
void print(Lista list) {
	printf("[");
	for(int i=0; i<list.nElem-1; i++)
		printf("%d, ", list.dati[i]);
	printf("%d]", list.dati[list.nElem-1]);
}