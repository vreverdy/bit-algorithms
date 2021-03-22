// ================================= COUNT ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: count.hpp
// Description: bit_iterator overloads for std::count, std::count_if
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _COUNT_HPP_INCLUDED
#define _COUNT_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "bit.hpp"
#include <iterator>
// Third-party libraries
#include "simdpp/simd.h"
// Miscellaneous

#define is_aligned(POINTER, BYTE_COUNT) \
    (((uintptr_t)(const void *)(POINTER)) % (BYTE_COUNT) == 0)

namespace bit {

// ========================================================================== //

template <class RandomAccessIt>
constexpr typename bit_iterator<RandomAccessIt>::difference_type
count_dispatch(
        bit_iterator<RandomAccessIt> first, 
        bit_iterator<RandomAccessIt> last,
        std::random_access_iterator_tag
) {
    // Assertions
    _assert_range_viability(first, last);
    //assert(first.position() == 0);

    // Types and constants
    using word_type = typename bit_iterator<RandomAccessIt>::word_type;
    using difference_type = typename bit_iterator<RandomAccessIt>::difference_type;
    constexpr difference_type digits = binary_digits<word_type>::value;
    const auto N = SIMDPP_FAST_INT64_SIZE;
    const auto N_native_words = (N*64)/digits;
    using vec_type = simdpp::uint64<N>;

    // Initialization
    difference_type result = 0;
    RandomAccessIt it = first.base();

    if (first.position() != 0) {
        word_type first_value = *first.base() >> first.position();
        result = _popcnt(first_value);
        ++it;
    }
    for (; it != last.base() && !is_aligned(&(*it), 64); ++it) {
        result += _popcnt(*it);
    }
    for (; std::distance(it, last.base()) >= (unsigned int) N_native_words + 2; it += N_native_words) {
        vec_type v = simdpp::load(&(*it));
        simdpp::for_each(v, [&result](auto a) {result += _popcnt(a);});
    }
    for (; it != last.base(); ++it) {
        result += _popcnt(*it);
    }
    if (last.position() != 0) {
        word_type last_value = *last.base() << (digits - last.position());
        result += _popcnt(last_value);
    }
    return result;
}

template <class InputIt>
constexpr typename bit_iterator<InputIt>::difference_type
count_dispatch(
        bit_iterator<InputIt> first, 
        bit_iterator<InputIt> last,
        std::input_iterator_tag
) {
    // Assertions
    _assert_range_viability(first, last);
    //assert(first.position() == 0);

    // Types and constants
    using word_type = typename bit_iterator<InputIt>::word_type;
    using difference_type = typename bit_iterator<InputIt>::difference_type;
    constexpr difference_type digits = binary_digits<word_type>::value;

    // Initialization
    difference_type result = 0;
    InputIt it = first.base();

    if (first.position() != 0) {
        word_type first_value = *first.base() >> first.position();
        result = _popcnt(first_value);
        ++it;
    }
    for (; it != last.base(); ++it) {
        result += _popcnt(*it);
    }
    if (last.position() != 0) {
        word_type last_value = *last.base() << (digits - last.position());
        result += _popcnt(last_value);
    }
    return result;
}

// Status: complete
template<class InputIt>
constexpr typename bit_iterator<InputIt>::difference_type
count(
    bit_iterator <InputIt> first,
    bit_iterator <InputIt> last,
    bit_value value
) {
    // Assertions
    _assert_range_viability(first, last);

    // Types and constants
    using word_type = typename bit_iterator<InputIt>::word_type;
    using difference_type = typename bit_iterator<InputIt>::difference_type;
    constexpr difference_type digits = binary_digits<word_type>::value;

    // Initialization
    difference_type result = 0;
    auto it = first.base();

    // Computation when bits belong to several underlying words
    if (first.base() != last.base()) {
        result = count_dispatch(first, last, typename std::iterator_traits<InputIt>::iterator_category());
    // Computation when bits belong to the same underlying word
    } else {
        result = _popcnt(
            _bextr<word_type>(*first.base(), first.position(), last.position() 
              - first.position())
        );
    }

    // Negates when the number of zero bits is requested
    if (!static_cast<bool>(value)) {
        result = std::distance(first, last) - result;
    }

    // Finalization
    return result;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class T>
typename bit_iterator<ForwardIt>::difference_type count(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, bit_value value) {
    (policy, first, last, value);
    return 0;
}

// Status: on hold
template <class InputIt, class UnaryPredicate>
constexpr typename bit_iterator<InputIt>::difference_type count_if(
    bit_iterator<InputIt> first, bit_iterator<InputIt> last, UnaryPredicate p) {
    (first, last, p);
    return 0;
} 

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
typename bit_iterator<ForwardIt>::difference_type count_if(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (policy, first, last, p);
    return 0;
}

} // namespace bit

#endif // _COUNT_HPP_INCLUDED
// ========================================================================== //
