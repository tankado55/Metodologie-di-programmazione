# Soluzione prova in itinere 2016-04-22

## Esercizio 1

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
	try{
	A* a2 = new A(2); 
	try{
		job1(a1, a2);
		A* a3 = new A(3);
		try{
			job2(a1, a3); 	
			delete a3;
		}catch (...){
			delete a3;
			throw;
		}
		delete a2; 
		delete a1;
	} catch (...) {
		delete a2;
		throw;
	}	
	} catch (...) {
		delete a1;
		throw;
	}
}
```