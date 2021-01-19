# Numeri casuali
In C si possono generare numeri casuali tramite la funzione **rand()** presente nella `<stdlib.h>`, essa permette di generare numeri casuali interi compresi tra 0 e RAND_MAX, una costante intera che equivale almeno a 32767.

Sfruttando alcune espressioni è possibile decidere tra quali valori generare il numero:

- `rand() % 10` genera un numero compreso tra 0 e 9
- `min + rand() % (max - min + 1)` genera un numero compreso fra min e max

Oppure si possono generare dei valori double:

- `(double) rand() / RAND_MAX` genera un numero compreso tra 0.0 e 1.0
- `min + (double) rand() / RAND_MAX * (max - min)` genera un numero double compreso tra min e max

Queste espressioni possono eventualmente essere scritte come funzioni a cui passare il parametro min e max per semplificarne l'uso.

La sequenza di numeri casuali restituiti da rand() in un programma è in realtà una sequenza di numeri pseudo-casuali calcolati ognuno dal precedente, a partire da un numero detto **seed** (seme).  
Se non impostato, il seed è sempre 1, quindi esecuzioni diverse di uno stesso programma generano la stessa sequenza di numeri casuali!  
Si può impostare un altro seed utilizzando la funzione `srand(numero)`, ma la sequenza di numeri generati sarà sempre la stessa ad ogni avvio siccome usa un seed statico.

Per poter generare sequenze di numeri casuali sempre diverse ad ogni avvio del programma il consiglio è quello di impostare come seed un valore che cambia sempre: il tempo.  
La funzione time(NULL) in C ritorna il tempo trascorso dal 1 gennaio 1970 in secondi, quindi impostando questo valore di ritorno come seed ci permette di avere una sequenza di numeri sempre diversa.

```
srand(time(NULL));
int numeroCasuale = rand();
```