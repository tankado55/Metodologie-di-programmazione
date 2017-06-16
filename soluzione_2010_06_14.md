# Prova 2010-06-14

## Esercizio 3

Nel codice originale, viene violato l'open-close principle che afferma che le entità software  (classi, moduli, funzioni, ecc.) dovrebbero essere aperte alle estensioni ma chiuse alle modifiche. Infatti, nel caso in cui si volesse aggiungere un nuovo tipo di espressioni bisognerebbe modificare il sorgente.

Questa soluzione rispetta l'OPC ma non è in grado di garantire l'estendibilità dell'insieme di operazioni supportate dalla classe Expr.

```c++
class Expr {
public:
  virtual const std::string& kind() const = 0;
  virtual void print() const = 0;
  virtual double eval(const Var_Bindings& vb) const = 0;

  virtual ~Expr() {}
};

class VAR : public Expr {
private:
  const std::string& tipo ("VAR");
  
public:
  const std::string& kind() const {
    return tipo;
  }
  void print() const {
    print(name());
  }
  double eval(const Var_Bindings& vb) const {
    return vb[name()];
  }
};

class CONST : public Expr{
  private:
  const std::string& tipo ("CONST");
  
public:
  const std::string& kind() const {
    return tipo;
  }
  void print() const {
    print(value());
  }
  double eval(const Var_Bindings& vb) const {
    return value();
  }
};

//da fare la stessa cosa con tutti gli altri Kind
```

