#include <stdio.h>
#include "frazioni.h"

int main() {
	int num, den;

	printf("Inserisci il numeratore: ");
	scanf("%d", &num);
	printf("Inserisci il denominatore: ");
	scanf("%d", &den);

	Frazione fraz = creaFrazione(num, den);
	printf("Numero frazionato = %f\n", getRisultatoFrazionato(fraz));
	return 0;
}