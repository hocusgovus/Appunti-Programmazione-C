# Progetti multifile
Nel linguaggio C (e non solo) è possibile suddividere un programma in multipli file sorgente ognuno contenente diverse funzioni. Questo può rivelarsi utile in diversi ambiti:

- Per poter suddividere un programma con molte righe di codice in più file, in modo da poterlo mantere più facilmente;
- Per utilizzare librerie già scritte da noi o altre persone senza dover fare copia-incolla delle funzioni che ci servono nel nostro codice;
- Per suddividere il lavoro in team, in modo tale che ciascuno possa compilare separatamente il suo codice;
- Per eventualmente vendere il nostro codice senza fornire il sorgente, possiamo per esempio fornire al cliente un file già compilato della nostra libreria, a lui basta avere questo file e una buona documentazione sulle funzioni implementate senza dover vedere il sorgente.

Questi file che andiamo a importare si chiamano solitamente moduli, ma come fa il sistema a capire cosa bisogna unire?  
Quello che noi normalmente chiamiamo compilazione in realtà comprende sia la compilazione che il linking: per prima cosa il compilatore effettua la conversione di ogni file sorgente del progetto in più file detti oggetti (viene creato un file oggetto per ogni file sorgente), successivamente il linker unisce tutti questi file oggetto e le eventuali funzioni di libreria che abbiamo invocato (come per esempio i printf) in un unico file eseguibile, questo ultimo procedimento è appunto detto linking.

![Schema linker](https://github.com/leonard0g/Appunti-Programmazione-C/raw/master/23.%20Progetti%20multifile/Immagini/Schema%20linker.jpeg)

Per far si che il compilatore e il linker capiscano cosa unire non basta mettere il file contenente il main e i vari moduli nella stessa cartella, ci sono alcuni accorgimenti da fare.  
Se per esempio creiamo un file chiamato **f.c**

```
int f(int n) {
	return n*2;
}
```

e un file **main.c**

```
int main() {
	int y = f(3);
}
```

e proviamo a compilare il file main.c il compilatore darà errore, questo perchè appunto non sa minimamente cosa sia la funzione **f** e si creano due problemi:

1. Non sa se la chiamata è corretta, quindi se i paramentri passati sono validi e non riesce a creare il record di attivazione
2. Non sa dove comincia la funzione **f**

> NB: Per quanto riguarda il secondo problema non è il compilatore a indicare qual'è l'indirizzo dove si trova la funzione **f**, ma questo lo indica il linker di cui abbiamo parlato in precedenza


## Problema 1: Dichiarazione di funzione
Per costruire il record di attivazione il compilatore deve sapere quanti sono i paramentri richiesti dalla funzione e di che tipo sono, inoltre deve sapere di che tipo è il valore di ritorno per, eventualmente, effettuare delle conversioni implicite (per esempio se il valore di ritorno è int e noi lo assegnamo a una variabile float).  
Per risolvere questo primo problema si dichiara nel file **main.c** l'interfaccia della funzione che ci serve.

La dichiarazione (anche chiamata prototipo) di una funzione è costituita dalla sola interfaccia senza il corpo (che viene sostituito con un ;).

`
<dichiarazione-di-funzione> ::= <tipoValore> <nome>(<parametri>);
`

Esempio:

```
//	DEFINIZIONE DELLA FUNZIONE (nel file f.c)
int f(int n) {
	return n*2;
}

//	DICHIARAZIONE DELLA FUNZIONE (nel file main.c)
int f(int);
```

Grazie alla dichiarazione il compilatore sarà in grado di creare il record di attivazione, in questo modo riuscirà a compilare il programma e a generare il file oggetto senza problemi.

> NB: Il compilatore riesce a generare il file oggetto del file **main.c** pur non sapendo che cosa fa la funzione **f**, questo perchè, come detto in precedenza, è compito del linker unire questi file oggetto e indicare a che indirizzo si trova la funzione **f**.

Nel caso il nostro programma avesse un unico file come abbiamo fatto fino ad ora non è necessario scrivere la dichiarazione di funzione, questo perchè la definizione vale anche come dichiarazione, ma non viceversa (perchè appunto manca il corpo della funzione).

---

Vediamo allora i file **main.c** e **f.c** usati in precedenza come esempio con le giuste modifiche apportare.

**f.c** rimane invariato:

```
int f(int n) {
	return n*2;
}
```

mentre nel **main.c** viene aggiunta la dichiarazione **prima** della chiamata:

```
int f(int);	//Dichiarazione

int main() {
	int y = f(3);		//Chiamata
}
```

## Problema 2: Linking dei file oggetto

Come detto in precedenza noi fino ad ora abbiamo inteso con compilazione sia il processo di compilazione in se che il processo di linking, infatti se provassimo a compilare il file **main.c** come abbiamo sempre fatto (con il comando `gcc main.c` ottenendo direttamente il file eseguibile **a.out**) ci sarà mostrato un errore simile a `linker command failed`.  
Questo perchè la prima fase di compilazione va a buon fine, ma la seconda fase di linking fallisce perchè il linker non sa dove trovare la funzione **f**, si torna quindi al problema n. 2 di cui abbiamo parlato in precedenza e che tratteremo ora.

Per effettuare il linking correttamente dobbiamo appunto spezzare il processo di compilazione in 2 parti: convertire tutti i file sorgente in file oggetto e successivamente passare tutti i file oggetto al linker.

Il processo di conversione dei file sorgente in file oggetto è molto semplice, ci basterà invocare gcc con il parametro **-c**. In questo modo gcc creerà un file chiamato come il file di input ma con estensione .o, questo è il nostro file oggetto.  
(Esempio: invocando `gcc -c main.c` otterremo il file oggetto del file main, ovvero **main.o**)

> NB: Questo file non è un eseguibile, è si compilato ma non è eseguibile finchè non passa per il linker

Dopo aver ottenuto i file oggetto per ogni file sorgente che ci serve dobbiamo farli passare per il linker.  
Il linker di C nei sistemi UNIX si chiama **ld**, ma passando tutti i file oggetto a **gcc** e specificando un nome per il file di output dopo il paramentro -o sarà gcc ad invocare il linker ld con i paramentri necessari, useremo quindi questo metodo.  
Avviando `gcc main.o f.o -o ./programma` otterremo finalmente il nostro programma eseguibile.

> NB: Il linker può dare errore se una funzione chiamata non viene definita o se viene definita più volte.  
Poniamo caso che definiamo due funzioni chiamate entrambe **f** sia nel file **main.c** che in **f.c**, la fase di compilazione dei file oggetto andrà a buon fine ma il linker darà errore perchè non sa a quale fare riferimento.

## Header file
La dichiarazione delle funzioni può diventare molto lunga se ne abbiamo implementate molte, e doverle dichiarare ogni volta che decidiamo di usare quel modulo può diventare complesso e uno spreco di tempo. Per questo vengono in nostro aiuto gli header file (file di intestazione).  
L'header file di un modulo contiene tutte le dichiarazioni delle funzioni definite nel modulo stesso, questo è utile appunto per evitare di doverle trascrivere ogni volta, specialmente se vendiamo il nostro codice a un cliente.

Per utilizarre questo header file basterà specificare di usarlo tramite la direttiva **#include**. Questa è una direttiva del preprocessore, il quale ha il compito di sostituire testualmente le direttive con i contenuti dei file indicati (questo avviene anche quando includiamo le librerie standard come la **stdio.h**).  
La direttiva **#include** ha due formati con cui può essere implementata:

 - `#include <libreria.h>` include l’header di una libreria di sistema, il sistema sa già dove trovarlo;
 - `#include "libreria.h"` include un header scritto da noi, occorre indicare dove reperirlo.

Il file header di una libreria/modulo ha estensione **.h** e ha (per convenzione) il nome uguale al file **.c** di cui fornisce le dichiarazioni, quindi c’è un file **.h** per ogni file **.c** dell’applicazione (escluso, eventualmente, il file che contiene il **main()**).

Per dare un esempio pratico proviamo a implementare un header file nell'esempio precedente con **main.c** e **f.c**. Riprendiamo con i file in questo stato:

**f.c**

```
int f(int n) {
	return n*2;
}
```

**main.c**

```
int f(int);	//Dichiarazione

int main() {
	int y = f(3);		//Chiamata
}
```
Ora provvediamo a creare il file di intestazione per il modulo **f.c**: come detto in precedenza lo chiameremo come il file .c semplicemente cambinado estensione, quindi **f.h**.

```
int f(int);
```

A questo punto possiamo modificare il file **main.c** rimuovendo la dichiarazione di funzione e aggiungendo la direttiva **#include**.

```
#include "f.h"

int main() {
	int y = f(3);		//Chiamata
}
```
E la creazione dell'header è terminata, non è un procedimento complesso ma ci semplifica decisamente la vita e rende il file più pulito.

Per assicurarci che il preprocessore trovi il file **f.h** dobbiamo posizionarlo nella stessa cartella dove si trovano anche **f.c** e **main.c**, altrimenti dovremo specificare tra le parentesi il percorso completo dell'header file.

> NB: Se per esempio creassimo una funzione dentro **f.c** che chiamiamo solo nelle altre funzioni nello stesso file e non vogliamo che sia utilizzata dagli altri utenti, ci basterà non scrivere la sua dichiarazione nell'header file

> NB: Creare il file di intestazione non signifa che ora basta usare **gcc main.c** per compilare, dobbiamo comunque seguire il procedimento spiegato nella parte del linker. Il file header evita solo di dover trascrivere le dichiarazioni ogni volta.