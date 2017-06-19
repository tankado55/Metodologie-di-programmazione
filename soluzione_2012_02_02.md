# Soluzione prova 2012_02_02

## Esercizio 3
* === 1 ===
* B::f(int)
* B::g(int)
* B::f(int)
* C::g(int)
* === 2 ===
* A::f(double)
* B::f(int)
* C::g(int)
* === 3 ===
* B::f(int)
* C::g(int)
* === 4 ===
* Destructor C::~C()
* Destructor B::~B()
* Destructor A::~A()
* Destructor B::~B()
* Destructor A::~A()



## Esercizio 4

Solo il distruttore è dichiarato virtual, ma non è opportuno in quanto l'utente accede tramite le due classi derivate.

In casi come questi non è opportuno usare l'ereditarietà, ma il contenimento:

```c++
class Protocol1 {
private:
	BasicProtocol bp;
public:
	Protocol1();
	~Protocol1();

	bool DoMsg1() {
	     bp.BasicMsgA();
	}
	bool DoMsg2() {
	     bp.BasicMsgB();
	}
	bool DoMsg3() {
	     bp.BasicMsgC();
	}
}
```