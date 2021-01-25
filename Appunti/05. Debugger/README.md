# Debugger
Durante la scrittura di un programma può capitare che si creino degli errori nella programmazione (anche detti bug), questi possono essere di due tipi: **errori di sintassi** che impediscono la compilazione del programma, oppure **errori logici**, che invece permettono al programma di compilare ma che hanno effetti imprevisti o indesiderati sul programma finale; generalmente si nota la presenza di errori logici quando il programma restituisce un output diverso da quello che ci si aspetta.

In generale gli output imprevisti, cioè la manifestazione di bug visibili agli utenti, sono originati da stati imprevisti della macchina astratta. In altre parole, se c’è un bug la sequenza di stati della macchina astratta sarà diversa da quella che si aspetta il programmatore. Esaminando gli stati della macchina astratta, il programmatore può individuare il primo che si discosta dalla sequenza prevista, e concentrarsi sulle parti del codice che l’hanno generato.

Individuare e correggere i bug è un’attività complessa, che impiega buona parte del tempo dei programmatori, ma per questo compito ci viene in aiuto il debugger. Il debugger è un programma che consente di eseguire in modo controllato un altro programma, esaminando lo stato della macchina astratta e facilitando la ricerca delle cause di malfunzionamento (bug).

Funzionalità tipiche di un debugger:

- Valutazione di espressioni;
- Esecuzione passo-passo (stepping);
- Interruzione in punti predefiniti (breakpoint);
- Interruzione in caso di modifica del valore di determinate variabili (watchpoint).

Il debugger per i programmi in C più comune è GDB. Anch'esso nasce su riga di comando ma è stato implementato su diversi IDE o Text editor, tra cui il nostro VSCode. Infatti, tramite la combinazione di tasti CTRL + SHIFT + D oppure tramite l’apposito tasto sulla sinistra, è possibile accedere alla finestra di debug di VSCode che consente di utilizzare i principali comandi di GDB direttamente dall’editor.

Per i più temerari che vogliono provare l'ebbrezza di debuggare su riga di comando lascio alcuni dei comandi più comuni di GDB:

| Comando             | Descrizione                                                                                                                                |
|---------------------|--------------------------------------------------------------------------------------------------------------------------------------------|
| gdb a.out           | Apre il debugger e carica il file a.out, a questo punto il debugger sarà in attesa dei comandi                                             |
| file a.out          | Carica il file a.out, si usa quando si è aperto gdb senza specificare il file in precedenza                                               |
| run                 | Avvia il programma                                                                                                                         |
| list                | Visualizza le 10 righe di codice attorno a quella che verrà eseguita                                                                       |
| list numero_riga    | Visualizza le 10 righe di codice attorno a numero_riga                                                                                     |
| break nomeFunzione | Imposta un breakpoint all’inizio della funzione nomeFunzione (quindi l’esecuzione verrà interrotta prima di nomeFunzione)                |
| break numero_riga   | Imposta un breakpoint alla riga numero_riga                                                                                                |
| if condizione       | L’esecuzione si interrompe quando la condizione inserita è vera (Es: `b 25 if i == 5` interrompe l’esecuzione alla riga 25 se i == 5 è vero) |
| info breakpoints    | Mostra i breakpoints impostati numerandoli                                                                                                 |
| delete breakpoint n | Elimina il breakpoint numero n                                                                                                             |
| continue            | Continua l’esecuzione fino interrota fino al prossimo breakpoint                                                                           |
| step                | Esegue una singola istruzione (eventualmente entrando nel codice delle funzioni chiamate)                                                  |
| next                | Esegue una singola istruzione (completando in un passo unico un’eventuale chiamata di funzione)                                            |
| print espressione   | Mostra il valore di espressione, può essere il nome di una variabile o una espressione                                                     |
| info locals         | Mostra nome e valore di tutte le variabili locali                                                                                          |
| watch espressione   | Interrompe l’esecuzione ogni volta che l’espressione cambia                                                                                |