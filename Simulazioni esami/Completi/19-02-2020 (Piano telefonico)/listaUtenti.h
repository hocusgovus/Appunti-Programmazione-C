//	Definizioni strutture
typedef struct {
	float costoScattoRisposta;
	int durataScatto;
	float costoScatto;
} Piano;

typedef struct {
	char numero[11];
	char piano;
	float credito;
} Cliente;

typedef struct nodo {
	Cliente dato;
	struct nodo* next;
} Nodo;

typedef Nodo* Lista;


//	Metodi
void inizializzaLista(Lista*);
void inserisciCliente(Cliente, Lista*);
void stampaClienti(Lista);
int decrementaCredito(char[], int, Piano[], int, Lista*);