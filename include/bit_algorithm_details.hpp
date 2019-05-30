// ========================= BIT ALGORITHM DETAILS  ========================= //
// Project: The Experimental Bit Algorithms Library
// Name: bit_algorithm_details.hpp
// Description: A set of utilities to assist in writing algorithms 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
//                 Bryce Kille [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _BIT_ALGORITHM_DETAILS_HPP_INCLUDED
#define _BIT_ALGORITHM_DETAILS_HPP_INCLUDED
// ========================================================================== //


// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {


// -------------------------- Iterator Algorithms --------------------------- //
// Returns the number of increments needed to get to last from first. 
// May be negative if last comes before first (Only when input is RAI)
template <class InputIt>
typename bit_iterator<InputIt>::difference_type 
    distance(bit_iterator<InputIt> first,
             bit_iterator<InputIt> last
)
{
    //_assert_range_viability(first, last); 
    //TODO should _assert_range_viability work for reverse ranges as well?
    using word_type = typename bit_iterator<InputIt>::word_type;
    using size_type = typename bit_iterator<InputIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;
    return std::distance(first.base(), last.base())*digits 
           + (last.position() - first.position());
}

// Increments the iterator n times. (If n is negative, the iterator is decremented n times)
template <class InputIt, class Distance>
void advance(bit_iterator<InputIt>& first, Distance n)
{
    first += n;    
}
// -------------------------------------------------------------------------- //



// --------------------------- Utility Functions ---------------------------- //

// Get next len bits beginning at start and store them in a word of type T
template <class T, class InputIt>
T get_word(bit_iterator<InputIt> first, T len=binary_digits<T>::value)
{
    using native_word_type = typename bit_iterator<InputIt>::word_type;
    T native_digits = binary_digits<native_word_type>::value; 
    constexpr T ret_digits = binary_digits<T>::value; 
    assert(ret_digits >= len);
    T offset = native_digits - first.position();
    T ret_word = *first.base() >> first.position();

    // We've already assigned enough bits
    if (len <= offset) { 
        return ret_word;
    } 

    InputIt it = std::next(first.base());
    len -= offset;
    // Fill up ret_word starting at bit [offset] using it
    while (len > native_digits) {
        ret_word = _bitblend(
                ret_word,      
                static_cast<T>(static_cast<T>(*it) << offset),   
                offset,
                native_digits
        );
        ++it;
        offset += native_digits;
        len -= native_digits;
    }
    // Assign remaining len bits of last word
    ret_word = _bitblend(
            ret_word,            
            static_cast<T>(static_cast<T>(*it) << offset),   
            offset,
            len
    );
    return ret_word;
}


// Shifts the range [first, last) to the left by n, filling the empty
// bits with 0
// NOT OPTIMIZED. Will be replaced with std::shift eventually.
template <class ForwardIt>
ForwardIt word_shift_left(ForwardIt first,
                          ForwardIt last,
                          typename ForwardIt::difference_type n
)
{
    if (n <= 0 || n >= distance(first, last)) return last;
    ForwardIt mid = first;
    std::advance(mid, n);
    for (; mid != last; ++first, ++mid) {
        *first = *mid;
        *mid = 0;
    }
    return first;
}


// Shifts the range [first, right) to the left by n, filling the empty
// bits with 0
// NOT OPTIMIZED. Will be replaced with std::shift eventually.
template <class ForwardIt>
ForwardIt word_shift_right(ForwardIt first,
                          ForwardIt last,
                          typename ForwardIt::difference_type n
)
{
    auto d = distance(first, last);
    if (n <= 0 || n >= d) return first;
    ForwardIt it = first;
    std::advance(it, d-n);
    std::rotate(first, it, last);
    it = first;
    std::advance(it, n);
    std::fill(first, it, 0); 
    return it;
}

// returns a word consisting of all one bits 
constexpr auto _all_ones() {
    return -1;
} 

// returns a word consisting of all zero bits
constexpr auto _all_zeros() {
    return 0;
}

// checks that the passed iterator points to the first bit of a word
template <class It>
bool _is_aligned_lsb(bit_iterator<It> iter) {
    return iter.position() == 0;
}

// checks that maybe_end is one position past the last bit of base
template <class ForwardIt>
bool _is_one_past_last_bit(bit_iterator<ForwardIt> maybe_end, 
    ForwardIt base) {
    return maybe_end.position() == 0 && std::next(base) == maybe_end.base(); 
}

// checks that two bit iterators point to the same word
template <class It>
constexpr bool _in_same_word(bit_iterator<It> lhs, bit_iterator<It> rhs) {
    return lhs.base() == rhs.base();
}

// simple alias for right shift
template <class WordType>
WordType _shift_towards_lsb(WordType word, std::size_t n) {
    return word >> n; 
} 

// simple alias for left shift
template <class WordType>
WordType _shift_towards_msb(WordType word, std::size_t n) {
    return word << n;
}

/* Used to read partial/full words and pad any missing digits. Will not
 * read outside of the word pointed to by the first iterator (see case 4) 
 *
 * Case 0: 01011101
 *        L       F
 * Case 1: 01011101 -> padded with 0s -> 00001101
 *            L   F
 * Case 2: 01011101 -> padded with 1s -> 01011111 
 *        L    F 
 * Case 3: 01011101 -> padded with 0s -> 00011100
 *           L  F
 * Case 4: 01011101 11111111 -> treated as 01011101
 *           F           L                L  F
 *
 * Note: word is read from [first, last), meaning the element pointed
 * to by last is not included in the read. if first == last, behavior
 * is undefined
 */
template <class It>
typename bit_iterator<It>::word_type _padded_read(bit_iterator<It> first, 
    bit_iterator<It> last, const bit::bit_value bv) {

    using word_type = typename bit_iterator<It>::word_type;

    constexpr std::size_t num_digits = binary_digits<word_type>::value;
    const std::size_t first_position = first.position();
    const std::size_t last_position = last.position();
    const word_type read = *(first.base());
    constexpr word_type all_ones = _all_ones();

    word_type mask;

    if (_is_aligned_lsb(first)) {
        if (_in_same_word(first, last)) {
            // Case 1
            if (bv == bit0) {
                mask = _shift_towards_lsb(all_ones, num_digits - last_position);
                return read & mask;
            } else {
                mask = _shift_towards_msb(all_ones, last_position); 
                return read | mask;
            }
        } else {
            // Case 0
            return read;
        }
    } else {
        if (!_in_same_word(first, last)) {
            // Case 2
            if (bv == bit0) {
                mask = _shift_towards_msb(all_ones, first_position); 
                return read & mask;
            } else {
                mask = _shift_towards_lsb(all_ones, num_digits - first_position); 
                return read | mask;
            }
        } else {
            // Case 3
            if (bv == bit0) {
                mask = _shift_towards_msb(all_ones, first_position); 
                mask &= _shift_towards_lsb(all_ones, num_digits - last_position);
                return read & mask;
            } else {
                mask = _shift_towards_lsb(all_ones, num_digits - first_position);
                mask |= _shift_towards_msb(all_ones, last_position);
                return read | mask;
            }
        } 
    }
}

// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _BIT_ALGORITHM_DETAILS_HPP_INCLUDED
// ========================================================================== //
