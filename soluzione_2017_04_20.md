# Soluzione prova in itinere 2017-04-20

## Esercizio 1

## Esercizio 2

## Esercizio 3

###### Modifiche da fare:

1. const correctness:
* su chiavi accoppiate: mettere 3 const
* check_inv: const sul this
* codifica, decodifica e firma_digitale: primo argomento const e sul this
* chiave_pubblica: const sul this

2. Mettere private k_priv e k_pubbl.

3. Bisogna dichiarare static i metodi che non hanno bisogno di lavorare sul this:
genera_chiavi, (forse anche chiavi_accoppiate).




## Esercizio 4

**Gli oggetti vengono creati nell'ordine in cui sono stati dichiarati**

- costr. s1
- costr. s3
- costr. s2  (non è mai nato quindi non può morire)
- // anche ALL non è mai nato
- distr 3
- distr 1
- problema
- tutto bene

## Esercizio 5