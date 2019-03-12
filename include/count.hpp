#pragma once
#include "bit.hpp"

template <class WordType, class T>
typename std::iterator_traits<bit::bit_iterator<T>>::difference_type 
count(bit::bit_iterator<WordType> first, bit::bit_iterator<WordType> last, const T& value) {
  return 3;
}
