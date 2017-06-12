
template <typename Iter1, typename Iter2, typename BinPred>

find_first_of(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, BinPred comp) {
  for (Iter1 i = first1; i != last1; ++i) {
    for (Iter2 j = first2; j != last2; ++j) {
      if (comp(*i, *j))
	return i;
    }
  }
  return last1;
}
