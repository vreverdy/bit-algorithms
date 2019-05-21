// ============================ INPUT CONTAINER ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            input_container.hpp
// Description:     Tests for input_container adapter 
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _INPUT_CONTAINER_TESTS_HPP_INCLUDED
#define _INPUT_CONTAINER_TESTS_HPP_INCLUDED
// ========================================================================== //


// =============================== PREAMBLE ================================= //
// C++ standard library
#include <deque>
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

/* Note on container types: std::forward_list doesn't support rbegin() or rend()
 * and std::list doesn't support operator[]. These methods were a requirement
 * for the input_container class as per vreverdy. So, at least for the time being,
 * these containers aren't being checked here. */

TEMPLATE_PRODUCT_TEST_CASE("input_container is correct size", "[template][product]", 
    (std::vector, std::deque), (unsigned short, unsigned int, unsigned long, 
    unsigned long long)) {

    using container_type = TestType;

    container_type con = {1, 2, 3};
    bit::input_container<container_type> input_cont(con);
    REQUIRE(input_cont.size() == 3);
}

TEMPLATE_PRODUCT_TEST_CASE("input_container returns a valid iterator", 
    "[template][product]", (std::vector, std::deque), (unsigned short, unsigned int, 
    unsigned long, unsigned long long)) {

    using container_type = TestType;
    container_type con = {1, 2, 3};
  
    bit::input_container<container_type> input_cont(con);
    
    typename bit::input_container<container_type>::iterator container_iter 
        = input_cont.begin();

    REQUIRE(*container_iter == 1);
    REQUIRE(*(++container_iter) == 2);
    REQUIRE(*(++container_iter) == 3);
}

TEMPLATE_PRODUCT_TEST_CASE("input_container mutable accessors are fine",
    "[template][product]", (std::vector, std::deque), (unsigned short, unsigned int,
    unsigned long, unsigned long long)) {
    using container_type = TestType;
    container_type con = {1, 2, 3, 4, 5};

    bit::input_container<container_type> input_cont(con);
    REQUIRE(input_cont[0] == 1);
    REQUIRE(input_cont.at(3) == 4);
    input_cont[0] = 7;
    REQUIRE(input_cont[0] == 7);
    input_cont.at(3) = 8;
    REQUIRE(input_cont.at(3) == 8);
}
    

#endif
