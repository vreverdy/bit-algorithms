// =============================== ALG UTILS  =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: alg_utils.hpp
// Description: A set of utilities to assist in writing algorithms 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ALG_UTILS_HPP_INCLUDED
#define _ALG_UTILS_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
/*
 * Takes two words and merges them together.
 * 
 * @param w1 the first operand of the merge
 * @param w2 the second operand of the merge
 * @param w1_position the position within w1 to start the merge from
 * @return a word given by merging w1 and w2
 */ 
template <class T>
T shift_and_merge(T w1, T w2, std::size_t w1_position) {

  if (w1_position == 0) {
    return w1;
  }

  constexpr std::size_t num_digits = bit::binary_digits<T>::value;

  T tmp1 = w1 << w1_position;
  T tmp2 = w2 >> (num_digits - w1_position);
  return tmp1 | tmp2;
}

/*
 * This function reads a T's worth of bits starting from wherever
 * the start bit_iterator is pointing. This means that we might be making
 * a word read from words which span multiple words.
 *
 * @param start the bit_iterator to start reading from
 * @param guard the furthest position to read to, ensuring there are not
 * memory access violations
 * @return a word read starting from the start position
 */
template <class WrappedIter, class T = typename WrappedIter::word_type>
T _read_word_raw(WrappedIter start, WrappedIter guard) {
  const unsigned long dist = std::distance(start, guard);

  if (dist < bit::binary_digits<T>::value) {
    /* we don't have sufficient bits to read so 
       instead of accessing bad memory, just pad 
       the remainder of the read with 0s */
    return *(start.base()) << start.position();
  } else {
    // we have enough bits to read to form a word
    T lhs = *(start.base());
    T rhs = *(start.base() + 1);
    return shift_and_merge(lhs, rhs, start.position());
  }
} 

/*
 * This function writes a T's worth of bits starting from wherever
 * the start bit_iterator is pointing. This means that we might be writing
 * bits spanning multiple words.
 *
 * @param start the bit_iterator to start writing from
 * @param guard the furthest position to write to, ensuring there are not
 * memory access violations
 * @param word the word to be written at start
 */ 
template <class WrappedIter, class T = typename WrappedIter::word_type>
void _write_word_raw(WrappedIter start, WrappedIter guard, T word) {
  const unsigned long dist = std::distance(start, guard);

    if (dist < bit::binary_digits<T>::value) {
        /* we don't have enough room to write the whole word so
         * so just write however many we can starting from MSB */
        *(start.base()) |= word >> start.position();
    } else {
        *(start.base()) |= word >> start.position(); 
        *(start.base() + 1) |= word << 
          (bit::binary_digits<T>::value - start.position()); 
    }
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
void _set_within_word(BitIter first, BitIter last, 
    typename BitIter::iterator_type base, bit::bit_value bv) {
    using word_type = typename BitIter::word_type;
    
    word_type mask = (static_cast<word_type>(1) << (last - first)) - 1;
    mask <<= first.position();

    if (bv == bit1) {
        *base |= mask;
    } else {
        *base ^= *base & mask;
    }
} 

// ========================================================================== //
} // namespace bit

#endif // _ALG_UTILS_HPP_INCLUDED
// ========================================================================== //

