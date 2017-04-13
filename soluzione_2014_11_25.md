# Soluzione prova in itinere 2014-11-25

## Esercizio 1

A
C= {1,2}, U= {1,2}, M={1}

B
C= {8}, U= {8}, M={8}  (conversione standard da int a char)

C
C= {8,3,4}, U= {4}, M={4}  (si applica argument dependend lookup)

D
C= {3,4}, U= {3,4}, M={3}
(la 4 prima viene convertita in intero e poi usa la conversione dell'utente)

E
C= {}, U= {}, M={}  (nessuna funzione)

F
C= {5,6}, U= {5,6}, M={6}

G
C= {5,6}, U= {5,6}, M={5}

H
C= {9,10,7}, U= {7, 10}, M={7}  (si applica ADL)

Alla fine viene invocato il distruttore.

Studiare conversioni inplicite puntatori:
Il puntatore di una classe derivata può essere convertito implicitamente a un puntatore della classe base.

## Esercizio 2

```c++
// S.hh
struct S {};

//T.hh
#incluse "S.hh"
struct T {S s;};

//T.cc
#include "S.hh"
#include "T.hh"   //viene violata la ODR perhè la struttura S viene definita 2 volte.
T t;
S s;
```

Nell'unica unità di traduzione che abbiamo la struct S viene definita 2 volte, quindi avremo un errore di compilazione.