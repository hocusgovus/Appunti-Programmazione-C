# Make
Come detto nella lezione precedente, in caso di un progetto complesso è consigliato suddividere il sorgente in più file per poi effettuare il linking di tutto.  
Quando ci troviamo ad avere un progetto molto grande (parliamo di decine se non centinaia di file sorgenti) diventerà complicato tenere traccia di quali sono stati modificati e, di conseguenza, quali devono essere ricompilati ecc.

Per questo motivo vengono in nostro aiuto i **sistemi di build**, questi programmi diventano estremamente necessari in situazioni come quella descritta precedentemente. I sistemi di build sono programmi che automatizzano la compilazione di un progretto seguendo le indicazioni che andremo a fornire in un cosiddetto **file di progetto**.

Questo ci semplifica notevolmente la fase di compilazione e linking: basterà preparare un file di progetto, avviare la build e sarà il sistema di build a effettuare autonomamente tutti i comandi che abbiamo imparato nella lezione scorsa.  
Inoltre il sistema di build offre un enorme vantaggio: ricompila solo i file che sono stati modificati. Questo vantaggio non lo noteremo con progetti leggeri come quelli che stiamo facendo ora, ma in certi progetti grandi torna molto utile.

> Nota che aggiungo io personalmente e di cui non ha parlato minimamente il prof: quando anni fa compilavo le ROM di Android ogni prima compilazione ci impiegava almeno 1h e mezza/2h nonostante avessi un PC potente, però quando dovevo ricompilare perchè era uscito un aggiornamento ci impiegavo al massimo 30min, appunto perchè il sistema di build ricompilava solo i file modificati. Questo era solo un esempio che vi volevo portare a livello pratico per mostrare l'utilità di un sistema di build.

Esistono diversi sistemi di build a seconda del linguaggio. Per quanto riguarda C/C++ uno dei più usati è **Make**, molto diffuso in ambiente UNIX.

Come detto in precedenza i sistemi di build richiedono un file di progetto che, nel caso di Make, si chiama convenzionalmente **Makefile** e si trova nella stessa cartella dei file sorgente.
Il comando make esegue la costruzione del progetto secondo il contenuto del Makefile.

## Come creare il makefile
Il makefile si scrive con un semplice editor di testo come VSCode, ma segue una formattazione specifica:

```
<target>: <dipendeza1> ... <dipendenzaN>
	<comandoDiCompilazione>
```

- `<target>` indica il file che viene creato eseguendo questo target;
- `<dipendeza>` indica i file da cui dipende la creazione del target;
- `<comandoDiCompilazione>` è abbastanza autoesplicativo, ma ricordatevi che si scrive un carattere di tabulazione prima del comando.

A primo impatto può essere complicato da comprendere, ma vediamo un esempio pratico.  
Analizziamo la cartella **Esempio** in allegato con questi appunti: `main.c` contiene la funzione main dove vengono usate delle funzioni scritte in `frazioni.c` e in entrambi viene importato l'header `frazioni.h` per implementare la struttura.  
Per compilare correttamente il programma dobbiamo prima compilare i file sorgenti in file oggetto, poi usare il linker con i file oggetto. Vediamo quindi come questo è stato implementato nel Makefile:

```
programma: main.o frazioni.o
	gcc main.o frazioni.o -o ./programma

main.o: main.c frazioni.h
	gcc -c main.c

frazioni.o: frazioni.c frazioni.h
	gcc -c frazioni.c

```

 - `programma` è il target finale che effettua il linking usando i file oggetto, potete infatti notare che il target programma dipende dai file **main.o** e **frazioni.o**;
 - `main.o` è il target che compila il file oggetto del file main.c, infatti ha come dipendenze **main.c** e **frazioni.h** in quanto questo header viene importato;
 - `frazioni.o` è il target che compila il file oggetto del file frazioni.c, infatti ha come dipendenze **frazioni.c** e **frazioni.h** in quanto questo header viene importato.

Essenzialmente nel Makefile specifichiamo quali file oggetto ci servono, che file servono per crearli, che comando usare per compilarli, che nome avranno in output e infine come effettuare il linking finale.

A questo punto ci basterà lanciare il comando `make programma` all'interno della cartella Esempio. Se i file oggetto necessari per compilare il programma non sono presenti o sono stati modificati make provvederà a compilarli e infine effettuerà il linking, facendoci quindi ottenere il file eseguibile.

> NB: Solitamente nel Makefile si scrive il comando di compilazione finale per primo nonostante sia l'ultimo ad essere lanciato, questo perchè se invochiamo make senza alcun paramentro lui procede a buildare il primo target presente nel Makefile. Questo ci permette di avviare la build invocando solo il comando make.