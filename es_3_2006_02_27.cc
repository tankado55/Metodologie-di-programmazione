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


// File FaxVirtual.hh  // Classe astratta

class FaxVirtual {
private:
  // ...
public:
  virtual void function_1() = 0;
  virtual void function_2(const char*) = 0;
  virtual void function_3(int) = 0;
  
  virtual ~FaxVirtual() {}
};
/*_________________________________________________*/


// File ModemVirtual.hh  // Classe astratta

class ModemVirtual {
private:
  // ...
public:
  virtual void function_1(const char*) = 0;
  virtual void function_2() = 0;
  virtual void function_3(unsigned int) = 0;
  
  virtual ~ModemVirtual() {}
};
/*_________________________________________________*/

// File Fax.hh

#include "FaxVirtual.hh"
#include "FaxModem.hh"            //inserire guardie
class Fax : public FaxVirtual {
private:
  FaxModem_AllStars* allstars;  
public:
  Fax(FaxModem_AllStars& fmas) : allstars(&fmas) {}   //costruttore
    
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

// File Modem.hh

#include "ModemVirtual.hh"
#include "FaxModem.hh"         //inserire guardie
class Modem : public ModemVirtual {
private:
  FaxModem_AllStars* allstars;
public:
  Modem(FaxModem_AllStars& fmas) : allstars(&fmas) {}  //costruttore
  
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

// File User.cc

#include "FaxVirtual"
#include "ModemVirtual"

void user_function_1(FaxVirtual& f) {
  f.fax_function_1();
  // ...
  f.fax_function_3(12);
}

void user_function_2(ModemVirtual& m, const char* command) {
  m.modem_function_1(command);
  // ...
  m.modem_function_3(1024);
}

void user_function_3(FaxVirtual& f, ModemVirtual& m) {
  f.fax_function_2("+390521906950");
  // ...
  m.modem_function_2();
}
