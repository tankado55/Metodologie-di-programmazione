using namespace std;

template <typename Cont1_Cont2, typename Cont3>

void f(const Cont1_Cont2& c1c2, Cont3& c3) {
  for (typename Cont1_Cont2::const_iterator c1c2_i = c1c2.begin(),
	 c1c2_end = c1c2.end(); c1c2_i != c1c2_end; ++c1c2_i) {
    typedef typename Cont1_Cont2::value_type Cont2
      for (typename Cont2::const_iterator c2_i = c1c2_i->begin(),
	     c2_i_end = c1c2_i->end(); c2_i != c2_i_end; ++c2_i)
	c3.pushback(*i);
  } 
}

// seconda parte

template <typename Iter1, typename Out>

void f(Iter1 first1, Iter1 last1, Out out) {
  for ( ; first1 != last1; ++first1) {
    typedef typename std::iterator_traits<iter1>::value_type Cont2;
    typedef typename Cont2::const_iterator Iter2;
    
    for (Iter2 first2 = first1->begin(), Iter2 last2 = first1->end(); first2 != last2; ++first2 ) {
      *out = *first2;
      ++out;
    }
  }
}

// Fornire un (semplice) esempio di applicazione della versione con
// iteratori che non possa essere codificato utilizzando la versione con contenitori.
// La versione con iteratori funziona solo con contenitori che hanno le funzioni begin() e end(),
// non funziona con gli array del C
