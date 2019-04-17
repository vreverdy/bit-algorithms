
#pragma once

namespace bit {
/*
 * Takes two words and merges them together.
 * Example: 00001000 01001101 with w1_position = 
 */ 
template <class WordType>
WordType shift_and_merge(WordType w1, WordType w2, std::size_t w1_position) {
  WordType tmp = w1 << (bit::binary_digits<WordType>::value - w1_position);
  WordType tmp2 = w2 >> w1_position;
  return tmp | tmp2;
}

/*
 * This function grabs 1 word_type worth of bits starting from the bit pointed
 * to by iter. This means the bits can span two different words and that unallocated
 * memory might be read. 
 *
 * @param iter an iterator to the bit to start drawing from
 * @return one complete word
 */
template <class WrappedIter, class WordType>
WordType fetch_word(bit::bit_iterator<WrappedIter> iter) {

  if (iter.position() == 0) {
    return *(iter.base());
  }

  WordType base = *(iter.base()); 
  WordType next = *(iter.base() + 1);

  return shift_and_merge(base, next, iter.position());
} 

/*
 * Allows the user to set or unset bits in range [begin, end) of the word at base
 *
 * @param begin the bit from which we start setting/unsetting 
 * @param end the bit from which we stop setting bits
 * @param base an iterator to the bit_value we wish to change
 * @param bv the bit value which we wish to set all bits in the range to.
 */
template <class BitIter>
void set_in_range(BitIter begin, BitIter end, typename BitIter::iterator_type base, bit::bit_value bv) {
  using word_type = typename BitIter::word_type;

  std::size_t low = begin.position();
  std::size_t high = end.position();

  word_type mask = static_cast<word_type>(1) << (high - low);
  mask <<= 1;
  mask--;
  mask <<= low;

  if (bv == bit::bit1) {
    *base |= mask;
  } else {
    word_type tmp = *base & mask;
    *base ^= tmp;
  }
} 

}
