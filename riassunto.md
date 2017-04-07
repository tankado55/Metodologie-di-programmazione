# 12 Funzioni

### 12.1.6 Funzioni constexpr

Specificando una funzione **constexpr**, indichiamo la nostra volontà di poterla usare nelle espressioni costanti se le vengono passate come argometi delle espressioni costanti.
Per essere valutata in fase di compilazione, una funzione deve essere adeguatamente semplice:
* Non sono consentiti ne cicli, nè variabili locali.
* Non deve avere effetti collaterali.
* Consente la ricorsione e le espressioni condizionali.
Le regole per un costruttore **constexpr** sono differenti: è consentita soltanto la semplice inizializzazione dei membri.
Le definizioni in diverse unità di traduzione devono essere identiche.

### 12.1.8 Variabili locali

Una variabile locale **static** consente alla funzione di conservare informazioni tra le chiaate senza introdurre una variabile globale soggetta ad accesso e possibile corruzione da parte di altre funzioni.