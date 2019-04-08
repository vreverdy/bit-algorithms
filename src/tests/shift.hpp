#pragma once

#include "bit.hpp"
#include "catch2.hpp"
#include "test_utils.hpp"
#include "list"

TEMPLATE_PRODUCT_TEST_CASE("Shift: left_shift", 
                           "[template][product]", 
                           (std::forward_list), 
                           (unsigned short)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;
    display(std::cout, bfirst1_t, blast1_t);
    bit::shift_left(bfirst1_t, blast1_t, 3);
    display(std::cout, bfirst1_t, blast1_t);
    bit::word_shift_left(bool_first1_t, bool_last1_t, 3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    std::cout << "bitcont\n";
    display(std::cout, bfirst1, blast1);
    bit::shift_left(bfirst1_t, blast1_t, digits+3);
    display(std::cout, bfirst1, blast1);
    std::cout << "Boolcont\n";
    display(std::cout, bool_first1, bool_last1, digits);
    bit::word_shift_left(bool_first1_t, bool_last1_t, digits+3);
    display(std::cout, bool_first1, bool_last1, digits);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    bit::shift_left(bfirst1_t, blast1_t, digits*3);
    bit::word_shift_left(bool_first1_t, bool_last1_t, digits*3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

}
