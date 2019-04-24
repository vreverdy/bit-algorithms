// ============================= BINARY SEARCH ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: binary_search.hpp
// Description: bit_iterator overloads for std::binary_search
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _BINARY_SEARCH_HPP
#define _BINARY_SEARCH_HPP

namespace bit {

// TODO
template <class WrappedIt, class T>
constexpr bool binary_search(bit_iterator<WrappedIt> first,
    bit_iterator<WrappedIt> last, const T& value) {

    first;
    last;
    value;

    return true;
}

// TODO
template <class WrappedIt, class T, class Compare>
constexpr bool binary_search(bit_iterator<WrappedIt> first,
    bit_iterator<WrappedIt> last, const T& value, Compare comp) {

    first;
    last;
    value;
    comp; 

    return true;
}


} // namespace bit

#endif // _BINARY_SEARCH_HPP
