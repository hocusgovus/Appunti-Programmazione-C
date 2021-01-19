# Controllo di versione
La cartella contenente i file sorgenti di un progetto viene spesso modificata nel tempo per aggiungere funzionalità o correggere errori, ma in certi casi può essere necessario dover tornare a una versione precedente del programma.  
Come possiamo fare per tenere traccia di tutte le versioni? Possiamo creare una copia della cartella ogni volta che cambiamo versione ma questo risulta scomodo non solo perchè è un processo manuale, ma anche perchè se si lavora in gruppo diventa difficile tenere traccia di ogni copia.

Per nostra fortuna esistono i sistemi di controllo di versione, programmi che permettono di archiviare ed eventualmente recuperare tutte le versioni della nostra cartella in un repository, permettendo quindi il confronto con le versioni precedenti e un ripristino a una versione precedente (rollback).

Esistono diversi programmi per il controllo di versione, ma il più utilizzato è sicuramente **Git**, creato da Linus Torvalds (creatore anche di Linux).

Git è multipiattaforma e, oltre a gestire i repository locali, permette di gestire dei repository remoti su altri computer e di sincronizzarli con quelli locali, utile in ambiente di lavoro. Esistono inoltre diversi siti che permettono di hostare la propria repository in rete, per consentire anche ad altri utenti di vederla e di contribuire al codice: il più conosciuto è sicuramente **GitHub** ma ne esistono altri, come per esempio **BitBucket** e **GitLab** (si, spesso fanno il gioco di parole con git, prendeteci l’abitudine).

Quando si effettuano delle modifiche a un progetto git lo noterà e ci permetterà di vedere i file che abbiamo modificato tramite il comando `git status`. Quando saremo sicuri che il codice funzioni e che le modifiche siano pronte possiamo salvarle effettuando un **commit**: un commit possiamo definirlo come un “checkpoint” dove vengono salvate le modifiche apportate da quello precedente, per ogni commit possiamo anche annotare una breve descrizione per indicare cosa abbiamo modificato.

Esistono alcuni programmi che permettono di interagire con git tramite una GUI, come per esempio **GitHub Desktop** oppure **VSCode** stesso che permette di usare i comandi principali (aprendo una cartella con all’interno un repository git comparirà il menù git sulla sinistra per effettuare dei commit velocemente), ma git in sé è un programma che si utilizza tramite CLI.

Di seguito trovate alcuni dei comandi più comuni di git.

| Comando                | Descrizione                                                                                                                                                                                 |
|------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| git init               | Crea un nuovo repository nella cartella corrente                                                                                                                                            |
| git status             | Mostra lo stato della repo (per esempio quali file sono stati modificati)                                                                                                                   |
| git clone url          | Crea un clone della repository remota nella cartella attuale (Es: con git clone https://github.com/lbrmrc/Programmazione2020 si crea una copia locale del repository degli esempi del corso |
| git pull               | Aggiorna il repository locale all’ultima versione di quello remoto                                                                                                                          |
| git log                | Mostra tutti i commit fatti alla repository                                                                                                                                                 |
| git checkout id-commit | Indicando l’ID del commit che ci interessa, questo comando riporta la cartella di lavoro allo stato corrispondente a quel commit                                                            |
| git push               | Carica sul repository remoto le modifiche effettuate a quello locale                                                                                                                        |