// ============================= ______ TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            template.hpp
// Description:     template for testing files
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _TEMPLATE_TESTS_HPP_INCLUDED
#define _TEMPLATE_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ---------------------------- TEMPLATE Tests ------------------------------ //
TEMPLATE_PRODUCT_TEST_CASE("Rotate: single_word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
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

    auto bret = bit::rotate(
            bfirst, 
            std::next(bfirst, 3), 
            std::next(bfirst, digits)
    );
    auto bool_ret = std::rotate(
            bool_first, 
            std::next(bool_first, 3), 
            std::next(bool_first, digits)
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
    REQUIRE(std::distance(bfirst, bret) == std::distance(bool_first, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("template: multiple_word_subcases", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
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

    // k <= digits
    auto bret = bit::rotate(bfirst, std::next(bfirst, 3) , blast);
    auto bool_ret = std::rotate(bool_first, std::next(bool_first, 3), bool_last);
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
    REQUIRE(std::distance(bfirst, bret) == std::distance(bool_first, bool_ret));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _TEMPLATE_TESTS_HPP_INCLUDED
// ========================================================================== //
