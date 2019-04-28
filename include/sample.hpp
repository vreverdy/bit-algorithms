// =============================== SAMPLE =================================== //
// Project: The Experimental Bit Algorithms Library
// Name: sample.hpp
// Description: bit_iterator overloads for std::sample
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SAMPLE_HPP_INCLUDED
#define _SAMPLE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class PopulationIterator, class SampleIterator, class Distance, 
         class URBG> SampleIterator sample(bit_iterator<PopulationIterator> first, 
         bit_iterator<PopulationIterator> last, SampleIterator out, Distance n,
         URBG&& g) {
    return out;
}

// ========================================================================== //
} // namespace bit

#endif // _SAMPLE_HPP_INCLUDED
// ========================================================================== //
