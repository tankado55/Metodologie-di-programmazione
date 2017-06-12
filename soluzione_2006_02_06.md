# Soluzione prova 2006_02_06

## Esercizio 1


**(a)** C= {4}, U = {4}, M= {4}

Per il this non é un match perfetto perché la funzione vorrebbe un tipo base qualificato const.
Quindi é una corrispondenza esatta
per il secondo argomento abbiamo un match perfetto.


**(b)** C= {7}, U= {7}, M={7} // errore di compilazione perché é privata.

match perfetto per this e match perfetto per il secondo argomento.

**(c)** C= {4}, U= {4}, M={4}

pb é di tipo base per il compilatore
quindi é uguale alla chiamata a.

**(d)**
C= {7}, U= {nessuna}, M={non esiste} //nessuna utilizzabile,
é illegittimo levare il const.

**(e)**
C= {1,2}, U= {1,2}, M={1}

this:
1: match perfetto.
2: conversione di qualificazione per il const

secondo argomento
1: promozione
2: conversione standard

terzo argomento
1: promozione
2:	conversione standard


**(f)**
C= {1,2,5}, U= {1,2,5}, M={5}
this
match
conversione (non sará mai la vincente quindi non la guardo piu)
match

secondo argomento
match

match

terzo

**(g)**
C= {1,2}, U= {1,2}, M={nessuna} // errore: ambigua

**(h)**
C= {1,2,5}, U= {2}, M={2}

**(i)**
C= {1,2,5}, U= {2}, M={2}

**(j)**
C= {3}, U= {}, M={} // nessuna utilizzabile

**(k)**
C= {6}, U= {6}, M={6}

## Esercizio 2
## Esercizio 3
## Esercizio 4
## Esercizio 5

```c++
template <typename Iter1, typename Iter2, typename BinPred>

find_first_of(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, BinPred comp) {
  for (Iter1 i = first1; i != last1; ++i) {
    for (Iter2 j = first2; j != last2; ++j) {
      if (comp(*i, *j))
	return i;
    }
  }
  return last1;
}
```

###### Indicare, motivando la risposta, la più ampia categoria di iteratori utilizzabile per ognuna delle due sequenze di input.

Per la prima sequenza, la più ampia categoria utilizzabile è quella degli input iterators in quanto abbiamo bisogno di scorrere la sequenza una sola volta e solo in una direzione, per la seconda sequenza, la più ampia categoria è quella dei forward iterators perchè bisogna leggere più volte la sequenza, con questa categoria gli iteratori non vengono invalidati dopo averli letti, mentre con gli input iterators sarebbero stati invalidati dopo la prima lettura.


## Esercizio 6
