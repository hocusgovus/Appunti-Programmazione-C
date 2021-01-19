# Stringhe
Una stringa è un array di caratteri, viene quindi inizializzata come array di char.

`char stringa[] = "ciao";`

Ogni stringa ha la sua parte significativa (corrispondente alla dimensione logica) seguita da un char di valore "\0" (indice ASCII 0).
Questo carattere viene interpretato da C come fine della stringa, se ci sono altri char dopo "\0", definiti o nulli che siano, essi saranno ignorati. Questo permette di non utilizzare una variabile secondaria per tenere traccia della dimensione logica dell'array (come invece accade con gli array di int).

Il carattere terminatore "\0" viene inserito automaticamente da C al termine di una stringa, bisogna quindi porre particolare attenzione sulla dimensione dell'array/stringa.
Se vogliamo inserire la parola **ciao** in una stringa dobbiamo assicurarci che ci sia lo spazio per tutte le lettere E per il carattere terminatore, quindi bisognerà inizializzare l'array con dimensione 5.

`char stringa[5] = "ciao";`

Se invece mettessimo come dimensione 4 il compilatore andrebbe a sostituire autonomamente l'ultima lettera con il carattere terminatore.

Per poter leggere o scrivere le stringhe tramite scanf o printf si utilizza la particella %s.

```
//	Scrittura
char stringa[5] = "ciao";
printf("%s", stringa);

//	Lettura
char stringa[5];
scanf("%s", stringa);
```

> Notare che nello scanf normalmente mettiamo il & prima della variabile, ma con le stringhe questo si può omettere in quanto scrivere l'array senza una posizione passa l'indirizzo.

Nel caso dello scanf, C scrive automaticamente il carattere terminatore quando trova un input a cui non corrisponde un carattere (es. spazio o invio), quindi inserendo dopo lo scanf una frase come **ciao a tutti** nella stringa verrà salvata solo la parola **ciao**.

Per le stringhe C mette a disposizione la libreria `string.h` dove sono disponibili diverse funzioni per semplificare il lavoro sulle stringhe, di seguito si trovano alcune delle più comuni:

| Comando                        | Descrizione                                                                                                                                                                                             |
|--------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| strcpy(Destinazione, Sorgente) | Copia la stringa Sorgente sulla Destinazione sostituendola. (No, non puoi fare Destinazione = Sorgente in C)                                                                                            |
| strcat(s1, s2)                 | Concatena la stringa s2 in fondo ad s1                                                                                                                                                                  |
| strcmp(s1, s2)                 | Controlla se le stringhe sono uguali e può ritornare diversi valori: 0 se le stringhe sono uguali, >0 se s1 viene prima di s2 in ordine alfabetico, <0 se s2 viene prima di s1. (N.B. è case sensitive) |
| strlen(s1)                     | Restituisce la lunghezza di s1                                                                                                                                                                          |


