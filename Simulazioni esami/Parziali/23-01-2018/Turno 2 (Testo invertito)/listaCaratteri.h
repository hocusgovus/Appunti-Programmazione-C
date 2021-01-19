//	Definizioni strutture
typedef struct nodo {
	char carattere;
	struct nodo* next;
} Nodo;

typedef Nodo* Lista;


//	Metodi
void inizializzaLista(Lista*);
void inserimentoTesta(char, Lista*);
void stampa(Lista);
void stampaUltimi(Lista, int);