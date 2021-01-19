typedef struct Frazione {
	int numeratore;
	int denominatore;
} Frazione;

Frazione creaFrazione(int, int);
int getNumeratore(Frazione);
int getDenominatore(Frazione);
float getRisultatoFrazionato(Frazione);