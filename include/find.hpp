// ================================== FIND ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: find.hpp
// Description: bit_iterator overloads for std::find, std::find_if, std::find_if_not
// Creator: Vincent Reverdy
// Contributor(s): Bryce Kille [2019] 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FIND_HPP_INCLUDED
#define _FIND_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// Status: needs revisions
template <class InputIt>
constexpr bit_iterator<InputIt> find(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit::bit_value bv) {

    using word_type = typename bit_iterator<InputIt>::word_type;
    std::size_t digits = binary_digits<word_type>::value;

    InputIt it = first.base();
    bit_iterator<InputIt> ret_it = last;

    std::size_t num_trailing_complementary_bits = (bv == bit1) 
        ? _tzcnt(static_cast<word_type>(*it >> first.position()))
        : _tzcnt(static_cast<word_type>(~(*it >> first.position())));
    
    if (first.base() == last.base()) {
        ret_it = first + std::min<size_t>(
            last.position() - first.position(), 
            num_trailing_complementary_bits
        );
    } else if (num_trailing_complementary_bits < digits - first.position()) {
        ret_it = first + num_trailing_complementary_bits;
    }
    else {
        ++it;
        for (;it != last.base(); ++it) {
            if (bv == bit1 && static_cast<word_type>(*it)) {
                std::size_t num_trailing_complementary_bits = _tzcnt(static_cast<word_type>(*it));
                    ret_it = bit_iterator<InputIt>(it, num_trailing_complementary_bits);
                    break;
            } else if (bv == bit0 && static_cast<word_type>(~*it)) {
                std::size_t num_trailing_complementary_bits = _tzcnt(static_cast<word_type>(~*it));
                    ret_it = bit_iterator<InputIt>(it, num_trailing_complementary_bits);
                    break;
            }
        }
        if (it == last.base() && last.position() != 0) {
            std::size_t num_trailing_complementary_bits = (bv == bit1) 
                ? _tzcnt(static_cast<word_type>(*it))
                : _tzcnt(static_cast<word_type>(~*it));
            ret_it = bit_iterator<InputIt>(
                it, 
                std::min<size_t>(
                    last.position(), 
                    num_trailing_complementary_bits
                )
            );
        }
    }
    return ret_it;
}

// Status: complete
template <class InputIt, class T>
constexpr bit_iterator<InputIt> find(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, const T& value) {
    return bit::find(first, last, value); 
}


// Status: to do
template <class ExecutionPolicy, class ForwardIt, class T>
bit_iterator<ForwardIt> find(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, const T& value) {
    (policy, last, value);
    return first;
}

// Status: on hold
template <class InputIt, class UnaryPredicate>
constexpr bit_iterator<InputIt> find_if(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, UnaryPredicate p) {
    (last, p);
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bit_iterator<ForwardIt> find_if(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    UnaryPredicate p) {
    (policy, last, p);
    return first;
}

// Status: on hold
template <class InputIt, class UnaryPredicate>
constexpr bit_iterator<InputIt> find_if_not(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, UnaryPredicate q) {
    (last, q);
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bit_iterator<ForwardIt> find_if_not(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    UnaryPredicate q) {
    (policy, last, q); 
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _FIND_HPP_INCLUDED
// ========================================================================== //
