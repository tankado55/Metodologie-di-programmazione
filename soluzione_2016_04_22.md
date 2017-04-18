# Soluzione prova in itinere 2016-04-22

## Esercizio 1

A
C= {2,3}, U= {2,3}, M={2}

B
C= {2,3}, U= {2,3}, M={2}

C
C= {2,3}, U= {3}, M={3}

D
C= {2,3}, U= {3}, M={3} // errore di compilazione, invalid conversion da const char* a char*

E
C= {1}, U= {1}, M={1} //match perfetto???

F
C= {5,8}, U= {8}, M={8}  //vede la 5 per l'ADL

G
C= {8}, U= {}, M={}  //nessuna utilizzabile

H
C= {7}, U= {7}, M={7}

## Esercizio 2

(a) Conversione standard

(b) Corrispondenza  esatta

(c) Nessuna conversione implicita (serve un cast)

(d) Conversione standard (da 0 si può convertire a qualunque tipo puntatore)

(e) Conversione definita dall'utente (anche se si tratta di libreria standard)

(f) Promozione

(g) Conversione standard

(h)

(i) Corrispondenza esatta

(j) Nessuna conversione impicita (uguale a c) (non si può trasformare un intero a puntatore)

## Esercizio 3

```c++
struct Matrix { 
	// ... 
	size_type num_rows()const; 
	size_type num_cols()const; 
	value_type& get(size_type row, size_type col); 
	value_type& get(size_type row, size_type col) const; //ne serve uno che consente la modifica e uno const
	Matrix operator-() const; 
	Matrix& operator+=(const Matrix& y); 
	Matrix operator+(const Matrix& y) const; 
	void print(ostrem& os) const; 
	// ... 
	};
```

## Esercizio 6

```c++
void foo() { 
  A* a1 = new A(1); 
  try{   //protettore a1
    A* a2 = new A(2); 
    try{   //protettore a2
      job1(a1, a2);
      A* a3 = new A(3);
      try{   //protettore a3
	job2(a1, a3); 	
	delete a3;
      }catch (...){
	delete a3;
	throw;
      }  //fine protettore a3
      delete a2; 
      delete a1;
    } catch (...) {
      delete a2;
      throw;
    }   //fine protettore di a2
  } catch (...) {
    delete a1;
    throw;
  }   //fine protettore di a3
}
```