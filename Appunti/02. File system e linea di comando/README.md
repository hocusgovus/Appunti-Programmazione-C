# File system e linea di comando
Un file è una sequenza di dati omogenei a cui è associato un nome, queste sequenze di dati vengono memorizzate in maniera differente a seconda del supporto di memorizzazione (per esempio un BluRay utilizza un laser, mentre un disco a stato solido dei chip di memorizzazione), ma il file system rende queste differenze trasparenti all’utente e alle applicazioni: il file system indica quindi il meccanismo con il quale i file vengono posizionati e organizzate sulle memorie.

Esistono diversi file system a seconda dell’utilizzo, i più comuni sono:

- **FAT32**, adattamento del vecchio file system FAT per i sistemi a 32bit, introdotto nel 1996 da Microsoft è uno dei più utilizzati, nonostante il suo limite di 4GB di dimensione massima per ogni file, vista la sua vasta compatibilità;
- **NTFS**, file system utilizzato dai sistemi operativi Microsoft;
- **ext***, attualmente alla versione 4 (quindi chiamato ext4) è un file system diffuso nell’ambiente Linux;
- **HFS+**, file system utilizzato sui sistemi Macintosh fino a qualche anno fa, poi sostituito nel 2016 da **APFS**.

Negli ambienti UNIX/Linux (quelli trattati da questo corso d’esame) ci sono alcune regole da seguire nella scrittura di un percorso, in particolare:

- Nei nomi dei file è proibito il carattere / (slash), in quanto viene usato come separatore delle cartelle;
- Quando nel nome di un file si vuole inserire un carattere speciale (per esempio uno spazio) bisognerà precedere il carattere con un \ (backslash), questo avviene solo quando si vuole manipolare il file da riga di comando (Es: **file di testo.txt** deve essere inserito come **file\ di\ testo.txt**);
- I file il cui nome inizia con un punto sono convenzionalmente nascosti.

Ad ogni file è normalmente associata una estensione, essa indica che tipologia di dati contiene questo file ed è indicata dopo l’ultimo punto nel nome del file (Es: un file chiamato **nome.del.file.txt** ha estensione **.txt** e ci indica che è un file di testo).
In ambienti UNIX/Linux i file eseguibili (codice macchina) non hanno estensione, mentre in Windows hanno estensione **.exe**.

Un computer, contando anche i file di sistema, arriva a contenere anche milioni di file, è quindi impensabile tenerli tutti insieme in un unico contenitore. Per questo esistono le cartelle, che sono sottogruppi di file o di altre cartelle.

Es: Andando al livello più basso (anche conosciuto come radice o root) di un file system dove è stato installato Windows si possono trovare tre cartelle principali:

- **Windows**, dove si trovano i file di sistema;
- **Program Files**, dove si trovano tutti i programmi installati sul PC;
- **Utenti**, dove si trovano tutti i file degli utenti, tra cui questo file (a meno che tu non abbia un sistema Linux o che lo stia leggendo dal browser).

---

I programmi scritti in linguaggio C, a meno che non siano state implementate librerie secondarie, utilizzano un'interfaccia a riga di comando (anche conosciuta come **CLI**, Command Line Interface), è quindi buona prassi avere una breve infarinatura su di essa.

Questo approccio nasce dalla modalità di interazione con i calcolatori di generazioni precedenti a quelli odierni: con essi infatti non si aveva a disposizione una interfaccia grafica a finestre con la possibilità di usare un mouse (conosciuta come **GUI**, Graphical User Interface), l’unico modo di interagire con essi era proprio una riga di comando nella quale inserire i comandi che il calcolatore andrà ad eseguire.  
Siccome la prima GUI è comparsa nel 1980 circa e il linguaggio C è stato creato nel 1972 si utilizza una interfaccia CLI per il linguaggio C (sono state poi create librerie per implementare delle interfacce GUI nei programmi in C, ma non le andremo a trattare in questo corso).

Nei sistemi operativi odierni si può ottenere una interfaccia di tipo CLI per mezzo di programmi che permettono all'utente di interagire digitando opportuni comandi su un emulatore di terminale testuale, questi programmi sono chiamati **shell**.

Esistono diversi tipi di shell a seconda del sistema operativo: in ambiente Linux la più comune è la **bash** in quanto è quella che arriva preinstallata su quasi tutte le distribuzioni, esistono anche altre shell come **zsh** o **csh** ma sono tutte molto simili tra loro; in ambiente Windows invece sono disponibili il **cmd** (anche conosciuto come prompt dei comandi) e la **PowerShell**.

Di seguito ci sono alcuni dei comandi più usati nelle shell Linux:

| Comando              | Descrizione                                                                                                                                                                                                              |
|----------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ls                   | Elenca tutti i file e cartelle presenti nella cartella dove ci troviamo                                                                                                                                                  |
| mkdir Nuova_cartella | Crea una nuova cartella chiamata Nuova_cartella                                                                                                                                                                          |
| rmdir Nuova_cartella | Cancella la cartella chiamata Nuova_cartella se vuota                                                                                                                                                                    |
| cd Nuova_cartella    | Ci spostiamo dentro la cartella chiamata Nuova_cartella                                                                                                                                                                  |
| man ls               | Mostra la guida per il comando ls, compresi eventuali parametri da passare per cambiare l’output (Funziona con qualsiasi comando, quindi se non sapete a cosa serve un comando che avete visto potete scoprirlo con man) |

> NB: Su Windows alcuni comandi comandi sono diversi, per esempio ls in realtà è dir