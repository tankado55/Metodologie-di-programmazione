# Esercizio 1


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
