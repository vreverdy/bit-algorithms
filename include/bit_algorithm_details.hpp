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
// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _BIT_ALGORITHM_DETAILS_HPP_INCLUDED
// ========================================================================== //
