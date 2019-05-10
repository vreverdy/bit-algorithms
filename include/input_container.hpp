// ============================ INPUT CONTAINER ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: input_container.hpp
// Description: Container adapter for input iterator
// Creator: Vincent Reverdy
// Contributor(s): Collin Gress [2019] 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _INPUT_CONTAINER_HPP_INCLUDED
#define _INPUT_CONTAINER_HPP_INCLUDED
// ========================================================================== //


// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //


/* **************************** INPUT CONTAINER **************************** */
template <class Container>
class input_container {
    public:
    using reference = typename Container::reference;
    using value_type = typename Container::value_type;
    using size_type = std::size_t;
    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;
    using const_reference = typename Container::const_reference;
    using reverse_iterator = typename Container::reverse_iterator;
    using const_reverse_iterator = typename Container::const_reverse_iterator;

    private:
    Container container_;

    public:
    input_container(Container& container)
      : container_(container) {}

    reference at(size_type pos) {
        return container_.at(pos);
    }

    const_reference at(size_type pos) const {
        return container_.at(pos);
    }

    reference operator[](size_type pos) {
        return container_[pos];
    }

    const_reference operator[](size_type pos) const {
        return container_[pos];
    }
    
    size_type size() const noexcept {
        return container_.size();
    }

    iterator begin()  noexcept {
        return container_.begin();
    }

    const_iterator begin() const noexcept {
        return container_.begin();
    }

    const_iterator cbegin() const noexcept {
        return container_.cbegin();
    }

    reverse_iterator rbegin() noexcept {
        return container_.rbegin();
    }

    const_reverse_iterator rbegin() const noexcept {
        return container_.rbegin();
    }

    const_reverse_iterator crbegin() const noexcept {
        return container_.crbegin();
    }
};


// ========================================================================== //
} // namespace bit

#endif // _INPUT_CONTAINER_HPP_INCLUDED
// ========================================================================== //
