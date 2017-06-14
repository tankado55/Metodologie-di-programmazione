# Soluzione prova 2005-02-01

## Esercizio 4

Nel codice originale viene violato l'open-close principle, che afferma che il codice dovrebbe essere aperto alle estensioni ma chiuso alle modifiche, infatti, in seguito all'introduzione di un ulteriore tipo di scheda prepagata sarà necessario modificare la classe Scheda_Prepagata.

```c++
// File Scheda_Prepagata.hh

#include <string>

class Scheda_Prepagata {
public:
  virtual std::string tipo_scheda() const = 0;
  virtual void addebita_chiamata(const Chiamata& call) = 0;

  virtual ~Scheda_prepagata () {}
};


// File paga_di_piu.hh

#include "Scheda_Prepagata.hh"

class Paga_di_piu : public Scheda_Prepagata {
private:
  virtual void fai_la_cosa_giusta_1(const Chiamata& call);

public:
  std::string tipo_scheda() const {
    return "Paga_di_piu";
  }
  void addebita_chiamata(const Chiamata& call) {
    fai_la_cosa_giusta_1(call);
  }
}
```

