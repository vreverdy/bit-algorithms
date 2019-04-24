// =============================== ACCUMULATE =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: accumulate.hpp
// Description: bit_iterator overloads for std::accumulate
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ACCUMULATE_HPP
#define _ACCUMULATE_HPP

namespace bit {

    // TODO
    template <class WrappedIter, class T>
    T accumulate(bit_iterator<WrappedIter> first, 
        bit_iterator<WrappedIter> last, T init) {

        first;
        last;
        init;

        return init;
    }

    // TODO
    template <class WrappedIter, class T, class BinaryOperation>
    T accumulate(bit_iterator<WrappedIter> first, 
        bit_iterator<WrappedIter> last, T init, BinaryOperation op) {
        
        first;
        last;
        init;
        op;
    
        return init;
    }

} // namespace bit

#endif // _ACCUMULATE_HPP
