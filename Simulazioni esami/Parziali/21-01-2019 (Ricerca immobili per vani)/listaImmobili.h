//	Definizioni strutture
typedef struct {
	char indirizzo[30];
	int vani;
	float distanza;
} Immobile;

typedef struct nodo {
	Immobile dato;
	struct nodo* next;
} Nodo;

typedef Nodo* Lista;

//	Metodi
void inizializzaLista(Lista*);
void inserimentoOrdinato(Immobile, Lista*);
void stampa(Lista);
void cercaImmobili(int, Lista, Lista*);
void salvaLista(Lista, char[]);