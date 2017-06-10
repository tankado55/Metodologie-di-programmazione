// Scrivere principio violato! e mostrare conseguenze della violazione

#include <string>
using std::string;

class Manual_Generator {
public:
  virtual void put(const string& s) = 0;
  virtual void set_boldface() = 0;
  virtual void reset_boldface() = 0;
  virtual void hyperlink(const string& uri, const string& text) = 0;
  virtual void page_break() = 0;

  virtual ~Manual_Generator() {}
};

class HTML_Generator : public Manual_Generator {
public:
  void put(const string& s);
  void set_boldface();
  void reset_boldface();
  void hyperlink(const string& uri, const string& text);
  void page_break(); /*{
    this.put("<HR>");
    }*/
};

class ASCII_Generator : public Manual_Generator {
public:
  void put(const string& s);
  void set_boldface();
  void reset_boldface();
  void page_break();
  void hyperlink(const string& uri, const string& text); /*{ 
    this.put(text);
    this.put(uri);
    }*/
};

void f(Manual_Generator* mg_p) {
  // ...
  mg_p->hyperlink("http://www.cs.unipr.it/ppl", "PPL");
  mg_p->page_break();
}

