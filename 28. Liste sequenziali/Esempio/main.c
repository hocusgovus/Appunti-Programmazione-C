#include <stdio.h>
#include "lista.h"

int main(void) {
	Lista listaListosa;
	newList(&listaListosa);

	//	Inserimento e stampa
	for(int i=0; i<DIM; i++) {
		int in;

		printf("Inserisci il valore alla posizione %d: ", i);
		scanf("%d", &in);
		if(in<=0)
			break;
		add(in, &listaListosa);
	}
	printf("\nValori nella lista: ");
	print(listaListosa);
	printf("\nNella lista sono presenti %d elementi", size(listaListosa));

	//	Rimozione valore e stampa
	int valoreNemico;
	printf("\n\nInserisci il valore che desideri eliminare: ");
	scanf("%d", &valoreNemico);
	if(removeValue(valoreNemico, &listaListosa))
		printf("Valore non trovato!");
	else
		printf("Valore rimosso con successo!");
	printf("\nValori nella lista: ");
	print(listaListosa);
	printf("\nNella lista sono presenti %d elementi", size(listaListosa));
	
	return 0;
}