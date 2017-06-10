# Soluzione prova 2005-20-09

## Esercizio 1

## Esercizio 2

## Esercizio 3

## Esercizio 4

## Esercizio 5

Il codice non viene compilato per i segunti motivi:
* Funzione f:

Alla riga 1 e alla riga 2 la ``std::find`` restituisce un const_iterator in quanto l'oggetto v è const. Non si può inizializzare un iterator con un const_iterator.
Quindi gli oggetti i e i_end devono essere dei const_iterator.
Inoltre se la ``std::find`` non trova niente, restituisce l'ultimo iteratore, quindi bisogna fare un controllo: ``if (i != v.end() && i_end != v.end())``.

* funzione g:

Nella terza riga si prova a scrivere "cacao" nella prima posizione, ma se la sequenza fosse vuota, v.begin() e v.end() sarebbero uguali e quindi si tenterebbe di scrrivere una posizione oltre il limite dell'array, andando in segmentation fault.
Dopo l'inserimennto, alla riga 4,  ``i_end`` viene invalidato, inoltre, anche ``i`` potrebbe venire invalidato in caso di riallocazione del vector.

Codice corretto:

```c++
#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
typedef std::vector<std::string>::const_iterator const_iter;

void f(const vect& v) {
  const_iter i = std::find(v.begin(), v.end(), "cioccolato");
  const_iter i_end = std::find(v.begin(), v.end(), "menta");
  if (i != v.end() && i_end != v.end()){
    while (i != i_end) {
      std::cout << *i << std::endl;
      ++i;
    }
    else
      std::cout << "elementi non trovati";
  }
}

void g(vect& v) {
  iter i = v.begin();
  iter i_end = v.end();
  if (i != i_end)
    *i = "cacao";
  v.insert(i, "vaniglia");
  i = v.begin();     //li ricalcolo perchè potrebbero essere stati invalidati
  i_end = v.end();
  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}
```
###### Tips:
* controllare i const
* verificare che le sequenze non siano vuote e che non si scriva qualcosa nella end
* verificare che gli iteratori non vengano invalidati.


## Esercizio 6