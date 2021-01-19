# Liste sequenziali
Una lista rappresenta una sequenza di elementi dello stesso tipo.

- `['a', 'b', 'c']` è una lista di caratteri 
- `[2, 5, 3]` è una lista di numeri interi
- `[[2, 3], [1], [], [7, 4]]` è una lista di liste di numeri interi

Per sequenza si intende un multi-insieme finito e ordinato, ma cosa significa in parole povere?

- **Multi-insieme:** è possibile che lo stesso elemento compaia più volte. [1, 2] e [2, 1, 2] sono entrambe liste valide (e diverse);
- **Finito:** in ogni momento la lista contiene un numero finito di elementi;
- **Ordinato:** due liste con gli stessi elementi che compaiono in ordine diverso sono diverse. Le liste [’a’, ’b’] e [’b’, ’a’] sono diverse.

Fino ad ora abbiamo visto una definizione matematica del concetto di lista, ma come può essere implementato questo nel linguaggio di programmazione? Vediamolo attraverso il tipo di dato astratto (ADT) Lista.

Dato un tipo di dato **T** che rappresenta un elemento della lista, nelle liste vengono implementate diverse operazioni. Quelle tipiche sono:

 - **Inizializzazione** di una lista vuota;
 - **Inserimento** in diversi modi di un elemento di tipo **T** a una lista di **T** (in testa, in coda o seguendo altri criteri come l’ordinamento);
 - **Eliminazione** di un elemento di tipo **T** da una lista di **T**;
 - **Svuotamento** di una lista da tutti gli elementi;
 - **Stampa** di tutti gli elementi;
 - **Ricerca** di un elemento di tipo **T** in una lista di **T**.

Inoltre sono presenti alcuni metodi che verificano

- se la lista è vuota, cioè non contiene elementi;
- se la lista è piena (la definizione astratta non lo consente, ma l’implementazione concreta può limitare la dimensione).

---

Le implementazioni delle liste possono essere di due tipi differenti:

- **Sequenziali:** in cui il successore di un elemento della lista è posto nell’area di memoria immediatamente seguente, tipicamente tramite array;
- **Collegate:** in cui il successore di un elemento della lista non è necessariamente nell'area di memoria seguente, ma si ottiene seguendo un collegamento.

Quelle collegate possono essere a loro volta implementate con due tipi di collegamenti diversi:

 - Tramite array (che non vedremo);
 - Tramite puntatori e allocazione/deallocazione dinamica (che vedremo nelle lezioni successive).

## Implementazione sequenziale
In una implementazione sequenziale delle liste in C sfruttiamo gli array. Gli elementi sono memorizzati in un vettore di dimensione massima `DIM` prefissata.

Il problema di questo approccio è che dobbiamo tenere traccia della dimensione logica dell'array, in quanto non sempre combacerà con la dimensione fisica. Le liste vengono quindi implementate tramite una struttura che contiene un 
valore **int** che rappresenta la dimensione logica dell'array e un array di tipo **T** che sarà la nostra lista effettiva.

```
typedef struct {
	int nElem;
	int dati[DIM];
} Lista;
```

Tramite questa implementazione, inserendo per esempio i valori 2, 5, 9 e 1 nella lista, essa sarà strutturata in questo modo:

![Schema lista sequenziale](https://github.com/leonard0g/Appunti-Programmazione-C/raw/master/28.%20Liste%20sequenziali/Immagini/Schema%20lista%20sequenziale.jpeg)

Nella cartella `Esempio` troverete una libreria dove sono state implementate le funzioni descritte in precedenza che potrete usare per capire meglio il concetto di lista. Può essere ampliata implementando una funzione di sorting.

L'implementazione delle liste in maniera sequenziale presenta però diversi problemi, più nello specifico:

- La dimensione massima è fissata, la lista non può crescere oltre il limite fisico dell'array;
- Anche una lista con pochi elementi occupa memoria quanto una lista della dimensione massima;
- Inserimento ed eliminazione effettuano molti accessi alla memoria, in quanto gli elementi successivi devono "scalare" a destra o a sinistra rispettivamente.

Per evitare questi problemi si preferisce l'utlizzo delle liste collegate, ma prima di poter parlare delle liste collegate dobbiamo capire come allocare dinamicamente un elemento in C: argomento che tratteremo nella prossima lezione. 