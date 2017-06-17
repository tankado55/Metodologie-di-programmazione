# Prova 2005_02_22

## Esercizio 1

* **1** C = {1,2} U = {2} M = {2}
* **2** C = {1,2} U = {1,2} M = {1} `void<const char*>(const char* t)`
Fannno entrambe type decay da puntatore ad array, si da preferenza alle funzioni non templatiche.
* **3** C = {1,2} U = {2} M = {2}
* **4** C = {1,3} U = {3} M = {3} Ci sarebbe la 4 ma no perchè la 3 è più specifica.
* **5** C = {1,4} U = {4} M = {4}
* **6** C = {1,5} U = {5} M = {5}
* **7** C = {1,4} U = {4} M = {4}
* **8** C = {1,6} U = {6} M = {6}
* **9** C = {7} U = {7} M = {7}
* **10** C = {7,8} U = {7,8} M = {8}
* **11** C = {7} U = {7} M = {7}
* **12** C = {7,8} U = {7,8} M = {}  Ambigua


## Esercizio 2

* Constructor ZooAnimal
* Constructor Endangered
* Constructor Bear
* Constructor Raccon
* Constructor Panda  
* Panda::print
* Bear::print
* Panda::print //perchè quella di ZooAnimal è virtual
* Endangered::print

## Esercizio 3

Esercizio 3:
Le variabili static non sono associate agli oggetti di una classe, quindi bisogna ripetere le dichiarazioni fuori dalle classi in modo che vengano instanziate e potranno essere utilizzate anche senza che nessun oggetto venga istanziato.

Occorre ripetere le dichiarazioni delle variabili static fuori dalle dichiarazioni delle classi perchè le variabili static non sono associate agli oggetti della classe:

```c++
// File costante.cc
double
Costante::pi = 3.1415;
double
Costante::e = 2.72;

//file angolo.cc
double
Angolo::retto = Costante::pi / 2;
double
Angolo::piatto = Costante::pi;
double
Angolo::giro = Costante::pi * 2;
```