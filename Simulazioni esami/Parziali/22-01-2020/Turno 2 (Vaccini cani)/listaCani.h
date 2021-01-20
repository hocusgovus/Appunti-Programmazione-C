//	Definizioni strutture
typedef struct {
	int chip;
	char vaccino;
} Vaccino;

typedef struct {
	int chip;
	int cimurro;
	int epatite;
	int parvovirosi;
} Cane;

typedef struct nodo {
	Cane dato;
	struct nodo* next;
} Nodo;

typedef Nodo* Lista;

//	Metodi
void inizializzaLista(Lista*);
void aggiorna(Vaccino, Lista*);
void stampa(Lista);
void esportaVaccini(Lista, char[]);