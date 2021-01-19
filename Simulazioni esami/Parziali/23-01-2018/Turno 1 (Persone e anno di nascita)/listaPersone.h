//	Definizioni strutture
typedef struct {
	char nome[30];
	int anno;
} Persona;

typedef struct nodo {
	Persona dato;
	struct nodo* next;
} Nodo;

typedef Nodo* Lista;


//	Metodi
void inizializzaLista(Lista*);
void inserimentoOrdinato(Persona, Lista*);
void stampa(Lista);
int natiEntro(Lista, int);