// ========================= NEXT_PERMUTATION TESTS ========================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            next_permutation.hpp
// Description:     Tests for next_permutation
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _NEXT_PERMUTATION_TESTS_HPP_INCLUDED
#define _NEXT_PERMUTATION_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ------------------------ next_permutation Tests -------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("next_permutation: single_word", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont = make_random_container<container_type>
                                     (container_size); 
    auto boolcont = bitcont_to_boolcont(bitcont);
    auto bfirst = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto blast = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    auto bool_first = std::begin(boolcont);
    auto bool_last = std::end(boolcont);
    
    bool bret;
    bool bool_ret;
    int test_idx = 0;
    display(std::cout, bfirst, std::next(bfirst, digits));
    bret = bit::next_permutation(
            next(bfirst, test_idx*digits), 
            next(bfirst, (test_idx + 1)*digits)
    );
    display(std::cout, bfirst, std::next(bfirst, digits));
    bool_ret = std::next_permutation(
            next(bool_first, test_idx*digits),
            next(bool_first, (test_idx + 1)*digits)
    );
    display(std::cout, bool_first, std::next(bool_first, digits), digits);
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
    REQUIRE(bret == bool_ret);
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _NEXT_PERMUTATION_TESTS_HPP_INCLUDED
// ========================================================================== //
