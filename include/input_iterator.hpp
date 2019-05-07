// ============================= INPUT ITERATOR ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: input_iterator.hpp
// Description: input_iterator is a wrapper for normal iterators which constrains
// the how we can use the wrapped iterator to match that of an InputIterator 
// Creator: Vincent Reverdy
// Contributor(s): Collin Gress [2019] 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _INPUT_ITERATOR_HPP_INCLUDED
#define _INPUT_ITERATOR_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

#include <iostream>

namespace bit {

struct input_iterator_tag {};

template <class Iterator>
class input_iterator {
public:
    using value_type = typename Iterator::value_type;
    using reference = typename Iterator::reference;
    using pointer = typename Iterator::pointer;
    using iterator_category = input_iterator_tag;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
private:
    Iterator it_;
public:
    input_iterator(Iterator it)
      : it_(it) {}

    constexpr input_iterator(const input_iterator& src) {
        it_ = src.it_;
    }

    bool operator==(const input_iterator<Iterator>& rhs) const {
        return it_ == rhs.it_;
    }

    bool operator!=(const input_iterator<Iterator>& rhs) const {
        return !operator==(rhs);
    } 

    constexpr reference operator*() const noexcept {
        return *it_;
    }

    constexpr pointer operator->() const noexcept {
        return it_.operator->();
    }

    constexpr input_iterator<Iterator>& operator++() {
        ++it_;
        return *this;
    }

    constexpr input_iterator<Iterator> operator++(int) {
        input_iterator<Iterator> copy = *this; 
        ++it_;
        return copy;
    }
};

// ========================================================================== //
} // namespace bit

// ========================================================================== //
#endif
// ========================================================================== //
