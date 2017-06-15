# Soluzione prova 2005-20-09

## Esercizio 1

## Esercizio 2

## Esercizio 3

## Esercizio 4

```c++
// Interfaccia BSoft non modificabile

class BSoft {
private:
  // ...
public:
  void s1();
  void s2(const BSoft& y, int n);
  void s3(int n);
  // ...
};

// Interfaccia BWare non modificabile

class BWare {
private:
  // ...
public:
  void w1();
  void w2_1(const BWare& y);
  void w2_2(int n);
  void w3(int n);
  // ... ecc.
};

// classe astratta Biblio.hh

class Biblio {
public:
  virtual void f1() = 0;
  virtual void f2(const Biblio& y, int n) = 0;
  virtual void f3(int n) = 0;

  virtual ~Biblio() {}
};

// classe concreta BSoft_Adapter.hh

#include "BSoft.hh"
#include "Biblio.hh"

class BSoft_Adapter : public Biblio {
private:
  BSoft& bs
public:
  void f1() {
    bs.s1();
  }
  void f2(const Biblio& y, int n) {
    //qui bisogna controllare che y sia davvero un BSoft_Adapter, se non lo è lancerà un eccezione
    const BSoft_Adapter& bsy = dynamic_cast<const BSoft_Adapter&>(y);
    bs.f2(bsy.bs, n);
  }
  void f3(int n) {
    bs.w3(n);
  }
};

// classe concreta BWare_Adapter.hh

#include "BWare.hh"
#include "Biblio.hh"

class BWare_Adapter : public Biblio {
private:
  BWare& bw;
public:
  void f1() {
    bw.w1();
  }
  void f2(const Biblio& y, int n) {
    //qui bisogna controllare che y sia davvero un BWare_Adapter, se non lo è lancerà un eccezione
    const BWare_Adapter& bwy = dynamic_cast<const BWare_Adapter&>(y);
    bw.w2_1(bwy.bw);
    bw.w2_2(n);
  }
  void f3(int n) {
    bw.w3(n);
  }
};

// codice utente

#include "Biblio.hh"

void f(Biblio& x, const Biblio& y, int n) {
  if (n > 0)
    x.f3(n);
  else {
    x.f1();
    n = 5;
  }
  x.f2(y, n);
}
```

Viene violato il depency inversion principle perchè il codice utente (funzione f), nella versione iniziale, dipende dalle entità concrete di basso livello (BSoft e Bware), con la seconda versione del codice, invertendo le dipendenze, abbiamo fatto in modo che il codie utente dipendesse da un entità astratta (Biblio), in questo modo è possibile espandere il codice senza modificare quello precedentemete scritto. 


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