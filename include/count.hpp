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
// Third-party libraries
// Miscellaneous

namespace bit {

// ========================================================================== //

template<class InputIt>
typename bit_iterator<InputIt>::difference_type
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
    word_type first_value = {};
    word_type last_value = {};

    // Computation when bits belong to several underlying words
    if (first.base() != last.base()) {
        if (first.position() != 0) {
            first_value = *first.base() >> first.position();
            result = _popcnt(first_value);
            ++it;
        }
        for (; it != last.base(); ++it) {
            result += _popcnt(*it);
        }
        if (last.position() != 0) {
            last_value = *last.base() << (digits - last.position());
            result += _popcnt(last_value);
        }
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

} // namespace bit

#endif // _COUNT_HPP_INCLUDED
// ========================================================================== //
