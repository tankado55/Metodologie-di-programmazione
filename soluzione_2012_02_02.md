# Soluzione prova 2012_02_02

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