# Soluzione 2006_02_27

## Esercizio 3

```c++
// file FaxModem.hh  // NON MODIFICABILE

class FaxModem_AllStars {
private:
  // ...
public:
  void fax_function_1();
  void fax_function_2(const char*);
  void fax_function_3(int);
  // ...
  void modem_function_1(const char*);
  void modem_function_2();
  void modem_function_3(unsigned int);
  // ...  
};
/*_________________________________________________*/


// File Fax.hh  // Classe astratta

class Fax {
private:
  // ...
public:
  virtual void fax_function_1() = 0;
  virtual void fax_function_2(const char*) = 0;
  virtual void fax_function_3(int) = 0;
  
  virtual ~Fax() {}
};
/*_________________________________________________*/


// File Modem.hh  // Classe astratta

class Modem {
private:
  // ...
public:
  virtual void modem_function_1(const char*) = 0;
  virtual void modem_function_2() = 0;
  virtual void modem_function_3(unsigned int) = 0;
  
  virtual ~Modem() {}
};
/*_________________________________________________*/

// File FaxAdapter.hh

#include "Fax.hh"
#include "FaxModem.hh"            //inserire guardie
class FaxAdapter : public Fax {
private:
  FaxModem_AllStars* allstars;  
public:
  explicit FaxAdapter(FaxModem_AllStars& fmas) : allstars(&fmas) {}   //costruttore
                 // marchiato explicit per impedire un inizializzazione con copia (=)
  void fax_function_1() {
    allstars->fax_function_1();
  }
  void fax_function_2(const char& c) {
    allstars->fax_function_2(c);
  }
  void fax_function_3(int i) {
    allstars->fax_function_3(i);
  }
};
/*_________________________________________________*/

// File ModemAdapter.hh

#include "Modem.hh"
#include "FaxModem.hh"         //inserire guardie
class ModemAdapter : public Modem {
private:
  FaxModem_AllStars* allstars;
public:
  explicit ModemAdapter(FaxModem_AllStars& fmas) : allstars(&fmas) {}  //costruttore
  
  void modem_function_1(const char& c) {
    allstars->modem_function_1(c);
  }
  void modem_function_2() {
    allstars->modem_function_2();
  }
  void modem_function_3(unsigned int ui) {
    allstars->modem_function_3(ui);
  }
};
/*_________________________________________________*/

// File FaxModemAdapter.hh

#include "Modem.hh"
#include "Fax.hh"
#include "FaxModem.hh"

class FaxModemAdapter : public Fax, public Modem {
private:
  FaxModem_AllStars* allstars;
public:
  explicit FaxModemAdapter(FaxModem_AllStars& fmas) : allstars(&fmas) {}

  void fax_function_1() {
    allstars->fax_function_1();
  }
  void fax_function_2(const char& c) {
    allstars->fax_function_2(c);
  }
  void fax_function_3(int i) {
    allstars->fax_function_3(i);
  }
  void modem_function_1(const char& c) {
    allstars->modem_function_1(c);
  }
  void modem_function_2() {
    allstars->modem_function_2();
  }
  void modem_function_3(unsigned int ui) {
    allstars->modem_function_3(ui);
  }
}


/*_________________________________________________*/

// File User.cc

#include "Fax"
#include "Modem"

void user_function_1(Fax& f) {
  f.fax_function_1();
  // ...
  f.fax_function_3(12);
}

void user_function_2(Modem& m, const char* command) {
  m.modem_function_1(command);
  // ...
  m.modem_function_3(1024);
}

void user_function_3(Fax& f, Modem& m) {
  f.fax_function_2("+390521906950");
  // ...
  m.modem_function_2();
}
```