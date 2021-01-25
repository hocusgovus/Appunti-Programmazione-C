# Variabili
Sono astrazioni di celle di memoria utilizzate nella programmazione ad alto livello. Esse permettono di salvare determinati tipi di dati e di dare ad essi dei nomi significativi (che quindi aiutano a leggere il programma), al posto che riferirsi alle celle di memoria stesse.

Esistono diversi tipi di variabili (int, float, char…) a seconda del dominio di dati che una essa può contenere, assieme alle operazioni che si possono svolgere su di essa. In base al tipo di una variabile il calcolatore determina la codifica utilizzata per trasporre il suo valore in linguaggio macchina e la decodifica utilizzata per mostrare la variabile in output.

In ogni linguaggio di programmazione è bene evitare nomi che contengono caratteri speciali e/o iniziano con numeri poichè, sebbene sintatticamente corretti, sono di difficile lettura da parte di programmatori e utenti, il nome di una variabile inoltre non può coincidere con quello di un comando. Nel caso di C, infine, i nomi di variabili e comandi sono case-sensitive: ciò significa che il linguaggio vede **a** ed **A** come lettere diverse.

### Esempio di definizione
`int a;  //int indica valori interi (numeri appartenenti a Z)​`

Per definizione si intende la creazione di una variabile. L’assegnazione, invece, è il “riempimento” di una variabile preesistente con un valore o un'espressione, calcolata dal programma, in base al suo tipo. In C, l’assegnamento è distruttivo, ovvero quando viene assegnato un nuovo valore ad una variabile, il precedente va perso e non è più recuperabile.

### Esempio di definizione
`a = 10;`

Per snellire il programma, definizione e assegnazione possono essere fatte nello stesso momento. Questo è possibile anche con più variabili dello stesso tipo.

`int a = 10, b = 5, c = 1;`

## Left Value, Right Value e operatori compatti
L’identificatore di una variabile, in una sola espressione, si può riferire sia al valore della cella che alla cella stessa.

```
int var = 10;​
var = var + 10;
```

Nella seconda riga, la **var** a sinistra dell’uguale indica la cella di memoria assegnata alla variabile var (Left Value), invece la **var** a destra dell’uguale indica il valore salvato in var (Right Value).  
Il compilatore vede l’istruzione sovrastante come: “Salva nella cella di memoria della variabile var (L. V.) un valore pari al suo contenuto attuale (R. V) incrementato di 10”.

Quando ad una variabile è assegnato il risultato di un’operazione a due termini in cui compare la variabile stessa, si possono utilizzare gli operatori di assegnamento compatti. Essi portano vantaggi soltanto nella scrittura e nella lettura del codice, il quale risulta più breve.

```
int a = 10, b = 5;
a += 4;  //equivale a: a = a + 4, ossia 14
b *= 3;  //equivale a: b = b * 3, ossia 15
```

Per incrementare o diminuire di 1 il valore di una variabile possono essere usati degli operatori ancora più compatti.

```
int a = 10, b = 5;​
a++;  //equivale a: a = a + 1 o a += 1, cioè 11
b--;  //equivale a: b = b - 1 o b -= 1, cioè 4
```

## Stampare e prendere in input variabili
Per stampare le variabili a schermo si può utilizzare la funzione printf.  
Per farlo si utilizzano appositi identificatori di formato all’interno del messaggio stampato (detto “stringa formato”). Terminata la stringa si elencano le variabili, separate da una virgola, ordinandole per come vanno stampate.

```
int a = 10;
printf(​ "La variabile a contiene il valore: %d", a);
//  %d indica valori interi in base decimale
```

Ogni identificatore comprende “%”, ed essi variano in base al tipo di dato che si deve dare in input o che necessita di essere stampato.

Gli stessi identificatori di formato sono usati analogamente nella funzione scanf, utilizzata per ottenere gli input da tastiera.  
scanf si può usare per assegnare un valore a qualsiasi tipo di variabile, a patto che essa sia già stata definita in precedenza. Non può essere utilizzato per inizializzare una variabile ed assegnare essa un valore in input nella stessa riga.

```
int a;​
scanf(​"%d", &a);
```
> Notate che nello scanf è necessario inserire la & prima del nome della variabile, scopriremo più avanti il motivo.