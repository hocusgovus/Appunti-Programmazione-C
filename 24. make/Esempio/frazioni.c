#include "frazioni.h"

//	Costruttore
Frazione creaFrazione(int num, int den) {
	Frazione out;
	out.numeratore = num;
	out.denominatore = den;
	return out;
}

//	Getters
int getNumeratore(Frazione in) {
	return in.numeratore;
}
int getDenominatore(Frazione in) {
	return in.denominatore;
}

//	Metodi
float getRisultatoFrazionato(Frazione in) {
	return (float)getNumeratore(in) / (float)getDenominatore(in);
}