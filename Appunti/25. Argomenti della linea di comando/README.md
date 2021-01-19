# Argomenti della linea di comando
Fino ad ora abbiamo considerato il main di un progetto come la funzione che viene eseguita quando viene avviato il programma e, a differenza delle altre funzioni che abbiamo scritto, l'abbiamo sempre definita senza dei parametri che gli vengono passati.

In realta al main possono essere passati due parametri, un numero intero e un array di stringhe, ma cosa contengono questi due parametri?

Probabilmente non ci abbiamo mai fatto caso, ma quando interagiamo con il computer tramite la riga di comando spesso, oltre ad avviare un programma, gli indichiamo anche qualcos'altro: per esempio quando vogliamo creare una nuova cartella invochiamo il comando **mkdir** al quale andiamo a indicare anche il nome della cartella da creare (Es: `mkdir Esercizi`), oppure quando andiamo a compilare un programma invochiamo il comando **gcc** al quale passiamo il nome del file da compilare (Es: `gcc main.c`).

Questi valori che passiamo ai programmi sono chiamati **Argomenti**, e sono quelli che il sistema operativo passa alla funzione main quando avviamo il programma.  
In particolare il valore intero indica quanti argomenti sono stati inseriti, questo ci serve a capire quanto è lungo l'array di stringhe (il quale contiene gli argomenti in sé) che viene passato come secondo parametro.  
I due parametri che vengono passati al main hanno due nomi convenzionali: **argc** (arg count) per il valore e **argv** (arg value) per l'array.

Nella cartella contenente questi appunti c'è anche una cartella Esempio dentro la quale troverete un file sorgente, questa è una semplice implementazione dei due parametri appena spiegati.

```
#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;

	for(i=0; i<argc; i++)
		printf("Argomento %d = %s\n", i, argv[i]);
}
```

Il codice in questione ci mostrerà tutti gli argomenti con cui il programma viene lanciato, proviamo per esempio ad avviarlo così `./a.out prova`.

```
Argomento 0 = ./a.out
Argomento 1 = prova
```

Come potete notare verrà passato al main almeno un argomento sempre, in quanto viene passato anche il nome del programma invocato.

## Ma a cosa serve implementare gli argomenti nel programma?
Domanda più che lecita, abbiamo già gli scanf quindi perchè usare gli argomenti per ottenere un valore in input?

Gli scanf sono comodi se il nostro programma deve avere molti valori in input, ma se l'unica cosa che richiede il nostro programma è per esempio il percorso di un file di testo da modificare può essere più comodo passare il percorso come argomento, proprio come facciamo con gcc.

`./programma file_di_testo.txt`

Questo approccio è più semplice di dover inserire il percorso tramite uno scanf, inoltre ci permette di sfruttare la funzione di autocompletamento dei percorsi del terminale premendo il tasto TAB.

> NB: Come con ogni singolo argomento passato a un programma dalla linea di comando ci sono alcuni accorgimenti da fare se vogliamo passare una stringa con uno spazio all'interno, questo perchè i programmi leggono lo spazio come "separatore" tra un argomento e un altro. L'unico modo per aggirare il problema è scrivere l'argomento tra virgolette (Es: `./programma "stringa con spazio"`) oppure forzare il carattere spazio con un backslash (Es: `./programma stringa\ con\ spazio`).


