# Allocazione dinamica
In fase di programmazione possiamo riservare della memoria per i nostri programmi definendo variabili.

`int a;`

Scrivendo questa istruzione noi abbiamo a disposizione 4 byte di memoria per salvare il nostro numero intero, ma è la macchina astratta a decidere dove e per quanto questa varibile verrà mantenuta nella memoria.  
Questo può anche non essere un grosso problema quando si parla di un paio di varibili intere per un programma completo, ma quando iniziamo a trattare una grossa mole di dati è meglio prendere in considerazione anche il consumo della memoria, questo per non sprecarne e permettere anche ai meno dotati di memoria di poter usufruire del nostro programma.  
In sostanza il detto "Le dimensioni non contano, l'importante è saperlo usare" si può applicare anche allo spazio di memoria disponibile per il nostro programma.

Nel linguaggio C le varibili possono essere classificate a seconda di come vengono create:

- **Le varibili globali** sono quelle che vengono dichiarate fuori da qualsiasi funzione e quindi accessibili da qualsiasi parte del programma, queste sono salvate nel **Data segment** e hanno tempo di vita pari al tempo di vita del programma (esistono finchè il programma non termina);
- **Le variabili automatiche** (anche chiamate locali) sono quelle varibili che vengono passate a una funzione (parametri) oppure che vengono dichiarate all'interno di essa, queste sono salvate nello **Stack** e vengono eliminate quando la funzione termina;
- **Le variabili dinamiche** sono variabili speciali in quando lo sviluppatore ha il pieno controllo di esse, vengono salvate nello **Heap** e spetta allo sviluppatore decidere quando crearle e quando eliminarle.

![Schema memoria](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

> Per maggiori dettagli sull'uso della memoria da parte di un programma in C vi rimando all'[articolo di GeeksForGeeks](https://www.geeksforgeeks.org/memory-layout-of-c-program/) dal quale ho rubato lo schema qua sopra

Le variabili dinamiche consentono quindi allo sviluppatore di avere un maggior controllo su come allocare la memoria, ma quando ci servono?

Per quanto visto finora in C le variabili sono sempre definite staticamente, questo significa che la loro esistenza deve essere prevista e dichiarata a priori in fase di programmazione.  
Questo in particolare può diventare un vero problema per quanto riguarda le variabili di tipo array, in quanto specificare una dimensione costante può essere limitativo.

Creiamo per esempio un programma che vada a sommare i valori inseriti dall'utente e li stampi alla fine, noi non possiamo sapere in fase di programmazione quanti numeri voglia inserire l'utente e quindi abbiamo solo un modo per procedere: creare un array molto grande e dare per scontato che l'utente non arrivi a inserire un quantitativo tale di numeri.

Dichiarando quindi un array di interi con dimensione 1000 rende improbabile che l'utente lo vada a riempire, però l'array andrà a usare 4000 byte di memoria a prescindere anche se l'utente ha intenzione di inserire solo 5 numeri, questo perchè viene definito in maniera statica.  
Inoltre questi 4000 byte di memoria verranno occupati fino al termine del programma, che se svolge anche altre operazione può diventare davvero pesante.

Quello che le variabili dinamiche ci consentono di fare è di richiedere all'utente quanti valori ha intenzione di inserire, allocare **in fase di esecuzione** un array delle dimensioni indicate dall'utente, fare i nostri calcoli e poi liberare la memoria utilizzata da questo array per poi continuare con l'esecuzione.  
Questa tecnica viene anche definita come **allocazione di memoria "by need"**.

## Come allocare dinamicamente la memoria
Per allocare dinamicamente delle variabili usiamo una funzione chiamata `malloc` definita nella `stdlib.h`. A questa funzione deve essere passato come parametro la dimensione che si vuole allocare in byte, dopodichè malloc si occuperà di inoltrare questa richiesta al sistema operativo e ci restituirà l'indirizzo di memoria dell'area che abbiamo richiesto.   
Queste variabili non hanno un identificatore: per utilizzarle bisogna salvare l'indirizzo di memoria che ci viene ritornato dalla chiamata di malloc in un puntatore, sarà grazie ad esso che potremo salvare i dati.

> malloc può ritornare un valore NULL se per qualche motivo non è stato possibile allocare lo spazio richiesto, è opportuno quindi fare un controllo prima di usare la memoria fornita.


```
int *pa;
pa = (int *)malloc(sizeof(int));
*pa = 5;
printf("%d", *pa);
```

Seguendo questo codice andremo quindi a creare un puntatore e ad assegnare ad esso l'indirizzo di memoria che ci viene fornito da malloc, a questo punto lo possiamo trattare come abbiamo già visto con i puntatori. Ci sono però alcuni accorgimenti da fare:

- Gli indirizzi di memoria ritornati da malloc sono "senza tipo", per assegnarli a uno specifico puntatore occorre fare un cast esplicito come si può vedere dall'esempio (si può evitare ma il compilatore darà un warning);
- È consigliato usare la funzione `sizeof` quando dobbiamo indicare a malloc quanti byte allocare, essa ritorna la dimensione in byte del tipo di variabile passata ed è consigliato questo metodo perchè la dimensione di ogni tipo di variabile può variare a seconda del compilatore (solitamente sono sempre uguali ma non si sa mai).

malloc ci consente anche di allocare un array in memoria, ci basterà moltiplicare il valore del sizeof per quante caselle vogliamo allocare.

```
int *pa;
pa = (int *)malloc(5 * sizeof(int));
pa[0] = 2;
pa[2] = 7;
```

In questa maniera abbiamo allocato in memoria uno spazio di 5 * 4 byte che possiamo trattare come abbiamo sempre fatto con gli array, questo ci permette di risolvere il problema dell'inserimento discusso in precedenza (trovate l'implementazione completa nella cartella Esempio).

Anche in questo caso c'è una cosa molto importante da dire, gli array creati in questo modo **NON HANNO DELIMITAZIONI**. Se creiamo un array in C di dimensioni 5 come abbiamo sempre fatto e proviamo ad accedere alla posizione 12 il compilatore ci darà errore, questo con gli array dinamici non accade. Se creiamo un array dinamico di 5 posizioni (quindi allocando 5*4byte) e provassimo ad accedere alla posizione 12 il programma continua. Questo fenomeno è detto **overflow** ed è molto pericoloso, vi consiglio quuindi di fare particolare attenzione agli accessi che andate a fare nell'array.

Dopo aver utilizzato queste celle di memoria è necessario indicare manualmente di liberarle, questo viene fatto attraverso la funzione `free`. Ad essa deve essere passato come parametro l'indirizzo di memoria da liberare, si occuperà di inoltrare questa richiesta al sistema operativo e la memoria che abbiamo usato sarà svuotata. Per fare questo ci basterà passare alla funzione free il nostro puntatore.

```
int *pa;
pa = (int *)malloc(sizeof(int));
*pa = 5;
printf("%d", *pa);
free(pa);
```

Questa funzione può essere chiamata nel bel mezzo del programma, non per forza alla fine, questo ci permette di liberare la memoria che stavamo occupando per far spazio ad altri dati.

> free può essere chiamata sia durante la piena esecuzione del programma sia in fase di termine, ma deve essere assolutamente scritta. Le variabili dinamiche come già spiegato non sono come le variabili normali e non vengono svuotate quando il programma viene chiuso, deve essere il programmatore a farlo.