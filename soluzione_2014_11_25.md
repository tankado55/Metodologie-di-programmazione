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

Nell'unica unità di traduzione che avremo la struct S viene definita 2 volte, quindi avremo un errore di compilazione.

## Esercizio 3

```c++
#include <cassert>
class C { 
public: 
	bool check_inv() const { // Codice che implementa il controllo di invariante. 
	}

	C(int a, int b) { 
		// Implementazione del costruttore. 	
		assert (check_inv())
	}

	void foo(C& y) { 
		assert (check_inv() && y.chek_inv())
		// Codice che implementa il metodo foo. 
		assert (check_inv() && y.chek_inv())
	}

	void bar(const C& y) { 
		assert (check_inv() && y.chek_inv())
		// Codice che implementa il metodo bar. 
		assert (check_inv())
	}

	void ying(const C& y) { 
		assert (check_inv() && y.chek_inv())
		// Codice che implementa il metodo ying. 
		assert (check_inv())
	}

	void yang(const C& y) const { 
		assert (check_inv() && y.chek_inv())
		// Codice che implementa il metodo yang. 
	}

	~C() { 
		assert (check_inv())
		// Codice che implementa il distruttore. 
	}

	static void zen(int i, double d) { 
		//qui non bisogna controllarle perchè è static e non ha il this	
		// Codice che implementa il metodo zen. 
	}
// ... altro codice ...
}; // class C
```
## Esercizio 5

Il problema nasce se qualcosa va storto dopo l'acquisizione delle risorse
"(A* a1 = new A(1) ecc.);" e prima del loro rilascio (delete), in quanto un
eccezione potrebbe far si che si esca in modo eccezionale dalla funzione senza che
vengano rilasciate le risorse.

### Soluzione 1:

```c++
void foo() {
  A* a1 = new A(1);
  try {   // protettore di a1
    A* a2 = new A(2);
    try {  // protettore di a2
      job1(a1, a2);
      delete a2;
    }
    catch (...){
      delete a2;
      throw;
    }
    A* a3 = new A(3);
    try{  // protettore di a3
      job2(a1, a3);
      job3(a3);
      delete a3;
    }
    catch (...){
      delete a3;
      throw;
    }
    delete a1;
  }
  catch (...){
    delete a1;
    throw;
  }
}
```
### Soluzione 2:
```c++
void foo() {
  RAII_A a1 (1);
  RAII_A a2 (2);
  {  
    job1(a1.get(), a2.get());
  }     //parentesi per permettere di richiamare il distruttore
  RAII_A a3 (3);
  job2(a1.get(), a3.get());
  job3(a3.get());
}

// dichiarazione classe RAII_A
class RAII_A{
private:
  A* p;

public:
  RAII_A (int);

  ~RAII_A ();

  A* get ();
};

//definizione classe RAII_A

RAII_A::RAII_A (int n1) {  //costruttore
  p= new A(n1);
}

RAII_A::~RAII_A (){
  delete p;
}

A* RAII_A::get () {
  return p;
}
```