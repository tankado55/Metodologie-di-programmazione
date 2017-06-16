# 6 Tipi e dichiarazioni

Gli **interi** possono essere implicitamente convertiti in valori **bool** e viceversa.

Un puntatore può essere convertito implicitamente in un  **bool** (nullptr=false).

Il fatto che un **char** sia considerato signed o unsigned dipende dall'implementazione.
I 3 tipi char sono distinti, quindi non è possibile mescolare puntatori a tipi char diversi (niente conversioni implicite).
Le variabili dei 3 tipi char possono essere liberamente assegnate reciprocamente.

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

Una variabile locale **static** consente alla funzione di conservare informazioni tra le chiamate senza introdurre una variabile globale soggetta ad accesso e possibile corruzione da parte di altre funzioni.

### 12.2.1 Argomenti riferimento

Le funzioni che modificano argomenti chiamata per riferimento possono rendere di difficile lettura i programmi, l'argomento può essere dichiarat **const** per indicare che il riferimento è utilizzato solo per motivi di efficienza.

Dichiarando **const** un argomento **puntatore** si indica al lettore che il valore di un oggetto a cui punta tale argomento non è modificato dalla funzione.

Il passaggio per riferimento è un passaggio **lvalue**, se si vuole passare per rvalue: &&. L'uso più ovvio dei riferimento rvalue è la definizione dei costruttori di spostamento e assegnamenti di spostamento.

Regole empiriche per scegliere tra i vari modi:
1. Usare passaggio per valore per piccoli oggetti.
2. Usare passaggio per riferimento **const** per passare grandi valori che non bisogna modificare.
3. Restituire un risulltato come valore **return** anzichè modificare un oggetto attraverso un orgomento.
4. Usare riferimenti rvalue per implementare spostamento e inoltro (23.5.2.1).
5. Passare un puntatore se "nessun oggetto" è un alternativa valida. 