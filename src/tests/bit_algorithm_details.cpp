// ============================ ALG UTILS TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            bit_algorithm_details.hpp
// Description:     Tests for algorithm utilities 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _BIT_ALGORITHM_DETAILS_TESTS_HPP_INCLUDED
#define _BIT_ALGORITHM_DETAILS_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "catch2.hpp"
#include "bit.hpp"
#include "test_utils.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ---------------------------- Alg Utils Tests ----------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("bit_algorithm_details: is_within()", 
                           "[template][product]", 
                           (std::forward_list), 
                           (unsigned char)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    const auto container_size = 4;
    const auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont = make_random_container<container_type>
                                     (container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    REQUIRE(bit::is_within<0>(first, first) == true);
    REQUIRE(bit::is_within<1>(first, first) == true);
    REQUIRE(bit::is_within<1>(first, first+1) == true);
    REQUIRE(bit::is_within<digits>(first, first+(digits-1)) == true);
    REQUIRE(bit::is_within<digits>(first, first+digits) == true);
    REQUIRE(bit::is_within<digits+1>(first, first+digits) == true);
    REQUIRE(bit::is_within<digits+1>(first, first+digits+1) == true);
    REQUIRE(bit::is_within<2*digits>(first, first+(2*digits-1)) == true);
    REQUIRE(bit::is_within<2*digits>(first, first+(2*digits)) == true);
    REQUIRE(bit::is_within<0>(first, first+1) == false);
    REQUIRE(bit::is_within<1>(first, first+2) == false);
    REQUIRE(bit::is_within<1>(first, first+digits) == false);
    REQUIRE(bit::is_within<digits-1>(first, first+(digits)) == false);
    REQUIRE(bit::is_within<digits>(first, first+digits+1) == false);
    REQUIRE(bit::is_within<digits+1>(first, first+digits+2) == false);
    REQUIRE(bit::is_within<digits+1>(first, first+2*digits) == false);
    REQUIRE(bit::is_within<2*digits-1>(first, first+(2*digits)) == false);
    REQUIRE(bit::is_within<2*digits>(first, first+(3*digits-1)) == false);

    ++first;
    REQUIRE(bit::is_within<0>(first, first) == true);
    REQUIRE(bit::is_within<1>(first, first) == true);
    REQUIRE(bit::is_within<1>(first, first+1) == true);
    REQUIRE(bit::is_within<digits>(first, first+(digits-1)) == true);
    REQUIRE(bit::is_within<digits>(first, first+digits) == true);
    REQUIRE(bit::is_within<digits+1>(first, first+digits) == true);
    REQUIRE(bit::is_within<digits+1>(first, first+digits+1) == true);
    REQUIRE(bit::is_within<2*digits>(first, first+(2*digits-1)) == true);
    REQUIRE(bit::is_within<2*digits>(first, first+(2*digits)) == true);
    REQUIRE(bit::is_within<0>(first, first+1) == false);
    REQUIRE(bit::is_within<1>(first, first+2) == false);
    REQUIRE(bit::is_within<1>(first, first+digits) == false);
    REQUIRE(bit::is_within<digits-1>(first, first+(digits)) == false);
    REQUIRE(bit::is_within<digits>(first, first+digits+1) == false);
    REQUIRE(bit::is_within<digits+1>(first, first+digits+2) == false);
    REQUIRE(bit::is_within<digits+1>(first, first+2*digits) == false);
    REQUIRE(bit::is_within<2*digits-1>(first, first+(2*digits)) == false);
    REQUIRE(bit::is_within<2*digits>(first, first+(3*digits-1)) == false);
    
    first += digits-2;
    REQUIRE(bit::is_within<0>(first, first) == true);
    REQUIRE(bit::is_within<1>(first, first) == true);
    REQUIRE(bit::is_within<1>(first, first+1) == true);
    REQUIRE(bit::is_within<digits>(first, first+(digits-1)) == true);
    REQUIRE(bit::is_within<digits>(first, first+digits) == true);
    REQUIRE(bit::is_within<digits+1>(first, first+digits) == true);
    REQUIRE(bit::is_within<digits+1>(first, first+digits+1) == true);
    REQUIRE(bit::is_within<2*digits>(first, first+(2*digits-1)) == true);
    REQUIRE(bit::is_within<2*digits>(first, first+(2*digits)) == true);
    REQUIRE(bit::is_within<0>(first, first+1) == false);
    REQUIRE(bit::is_within<1>(first, first+2) == false);
    REQUIRE(bit::is_within<1>(first, first+digits) == false);
    REQUIRE(bit::is_within<digits-1>(first, first+(digits)) == false);
    REQUIRE(bit::is_within<digits>(first, first+digits+1) == false);
    REQUIRE(bit::is_within<digits+1>(first, first+digits+2) == false);
    REQUIRE(bit::is_within<digits+1>(first, first+2*digits) == false);
    REQUIRE(bit::is_within<2*digits-1>(first, first+(2*digits)) == false);
    REQUIRE(bit::is_within<2*digits>(first, first+(3*digits-1)) == false);
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _BIT_ALGORITHM_DETAILS_TESTS_HPP_INCLUDED
// ========================================================================== //
