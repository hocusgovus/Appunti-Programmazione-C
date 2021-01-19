#define DIM 50

//	STRUTTURA
typedef struct {
	int nElem;
	int dati[DIM];
} Lista;

//	METODI
//	Stessi nomi dei metodi delle liste in Java
//	FONTE: https://www.journaldev.com/11444/java-list#java-list-methods
void newList(Lista*);
int size(Lista);
int isEmpty(Lista);
int isFull(Lista);
int contains(int, Lista);
int add(int, Lista*);
int removeValue(int, Lista*);
void clear(Lista*);
int get(int, Lista);
int set(int, int, Lista*);
void print(Lista);