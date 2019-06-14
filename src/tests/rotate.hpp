// ============================= ROTATE TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            rotate.hpp
// Description:     Tests for shift_left and shift_right algorithms 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _ROTATE_TESTS_HPP_INCLUDED
#define _ROTATE_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ------------------------------ Rotate Tests ------------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("Rotate: single_word", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned short)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;

    blast1_t = std::next(bfirst1, digits);
    bool_last1_t = std::next(bool_first1, digits);
    auto bret = bit::rotate(bfirst1_t, std::next(bfirst1_t, 3) , blast1_t);
    auto bool_ret = std::rotate(bool_first1_t, std::next(bool_first1_t, 3), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bfirst1_t = std::next(bfirst1, 4);
    bool_first1_t = std::next(bool_first1, 4);
    blast1_t = std::next(bfirst1, digits - 2);
    bool_last1_t = std::next(bool_first1, digits - 2);
    bret = bit::rotate(bfirst1_t, std::next(bfirst1_t, 5) , blast1_t);
    bool_ret = std::rotate(bool_first1_t, std::next(bool_first1_t, 5), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bfirst1_t = std::next(bfirst1, 2);
    bool_first1_t = std::next(bool_first1, 2);
    blast1_t = std::next(bfirst1, digits - 2);
    bool_last1_t = std::next(bool_first1, digits - 2);
    bret = bit::rotate(bfirst1_t, std::next(bfirst1_t, 6) , blast1_t);
    bool_ret = std::rotate(bool_first1_t, std::next(bool_first1_t, 6), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Rotate: multiple_word_subcases", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned short)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;

    // k <= digits
    auto bret = bit::rotate(bfirst1_t, std::next(bfirst1_t, 3) , blast1_t);
    auto bool_ret = std::rotate(bool_first1_t, std::next(bool_first1_t, 3), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bfirst1_t = std::next(bfirst1, 2);
    bool_first1_t = std::next(bool_first1, 2);
    bret = bit::rotate(bfirst1_t, std::next(bfirst1_t, 5) , blast1_t);
    bool_ret = std::rotate(bool_first1_t, std::next(bool_first1_t, 5), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bfirst1_t = std::next(bfirst1, 2);
    bool_first1_t = std::next(bool_first1, 2);
    blast1_t = std::next(bfirst1, digits*3 - 2);
    bool_last1_t = std::next(bool_first1, digits*3 - 2);
    bret = bit::rotate(bfirst1_t, std::next(bfirst1_t, 6) , blast1_t);
    bool_ret = std::rotate(bool_first1_t, std::next(bool_first1_t, 6), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // p <= digits
    bfirst1_t = bfirst1;
    bool_first1_t = bool_first1;
    blast1_t = blast1;
    bool_last1_t = bool_last1;
    bret = bit::rotate(bfirst1_t, std::next(bfirst1, container_size*digits-5) , blast1_t);
    bool_ret = std::rotate(bool_first1_t, std::next(bool_first1, container_size*digits-5), bool_last1_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::rotate(
            bfirst1_t, 
            std::next(bfirst1, (container_size-1)*digits - 3) , 
            std::next(bfirst1, container_size*digits-5)
    );
    bool_ret = std::rotate(
            bool_first1_t, 
            std::next(bool_first1, (container_size-1)*digits - 3), 
            std::next(bool_first1, container_size*digits-5)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::rotate(
            std::next(bfirst1, digits - 1), 
            std::next(bfirst1, (container_size-1)*digits - 7) , 
            std::next(bfirst1, container_size*digits-8)
    );
    bool_ret = std::rotate(
            std::next(bool_first1, digits - 1), 
            std::next(bool_first1, (container_size-1)*digits - 7), 
            std::next(bool_first1, container_size*digits - 8)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // k == p
    bret = bit::rotate(
            bfirst1, 
            std::next(bfirst1, container_size*digits/2), 
            std::next(bfirst1, container_size*digits)
    );
    bool_ret = std::rotate(
            bool_first1, 
            std::next(bool_first1, container_size*digits/2), 
            std::next(bool_first1, container_size*digits)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::rotate(
            std::next(bfirst1, digits-1), 
            std::next(bfirst1, container_size*digits/2), 
            std::next(bfirst1, container_size*digits - (digits-1))
    );
    bool_ret = std::rotate(
            std::next(bool_first1, digits-1), 
            std::next(bool_first1, container_size*digits/2), 
            std::next(bool_first1, container_size*digits - (digits-1))
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Rotate: REV_multiple_word_main", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned short)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);

    auto bret = bit::rotate(
            std::next(bfirst1, digits+1), 
            std::next(bfirst1, container_size*digits/2), 
            std::next(bfirst1, container_size*digits),
            bit::REVERSE
    );
    auto bool_ret = std::rotate(
            std::next(bool_first1, digits+1), 
            std::next(bool_first1, container_size*digits/2), 
            std::next(bool_first1, container_size*digits)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Rotate: STD_multiple_word_main aligned", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned short)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 5;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);

    // First and last aligned
    auto bret = bit::rotate(
                        bfirst1, 
                        std::next(bfirst1, container_size*digits/2-3), 
                        std::next(bfirst1, container_size*digits),
                        bit::STD
    );
    auto bool_ret = std::rotate(
                        bool_first1, 
                        std::next(bool_first1, container_size*digits/2-3), 
                        std::next(bool_first1, container_size*digits)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::rotate(
            bfirst1, 
            std::next(bfirst1, digits+2), 
            std::next(bfirst1, container_size*digits),
            bit::STD
    );
    bool_ret = std::rotate(
            bool_first1, 
            std::next(bool_first1, digits+2), 
            std::next(bool_first1, container_size*digits)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::rotate(
            bfirst1, 
            std::next(bfirst1, (container_size - 1) * digits - 2), 
            std::next(bfirst1, container_size*digits),
            bit::STD
    );
    bool_ret = std::rotate(
            bool_first1, 
            std::next(bool_first1, (container_size - 1) * digits - 2), 
            std::next(bool_first1, container_size*digits)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::rotate(
            bfirst1, 
            std::next(bfirst1, (container_size / 2) * digits - 1), 
            std::next(bfirst1, container_size*digits),
            bit::STD
    );
    bool_ret = std::rotate(
            bool_first1, 
            std::next(bool_first1, (container_size / 2) * digits - 1), 
            std::next(bool_first1, container_size*digits)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Rotate: STD_multiple_word_main unaligned", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned char)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    
    // !(First and last aligned)
    // f.pos() < nf.pos()
    auto bret = bit::rotate(
                        std::next(bfirst1, 1),
                        std::next(bfirst1, container_size*digits/2-3), 
                        std::next(bfirst1, container_size*digits - 6),
                        bit::STD
    );
    auto bool_ret = std::rotate(
                        std::next(bool_first1, 1), 
                        std::next(bool_first1, container_size*digits/2-3), 
                        std::next(bool_first1, container_size*digits - 6)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // f.pos() > nf.pos()
    bret = bit::rotate(
                    std::next(bfirst1, 6),
                    std::next(bfirst1, (container_size-4)*digits + 1), 
                    std::next(bfirst1, container_size*digits - 2),
                    bit::STD
    );
    bool_ret = std::rotate(
                    std::next(bool_first1, 6), 
                    std::next(bool_first1, (container_size-4)*digits + 1), 
                    std::next(bool_first1, container_size*digits - 2)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // f.pos() == nf.pos()
    bret = bit::rotate(
                    std::next(bfirst1, 6),
                    std::next(bfirst1, (container_size-4)*digits + 6), 
                    std::next(bfirst1, container_size*digits - 2),
                    bit::STD
    );
    bool_ret = std::rotate(
                    std::next(bool_first1, 6), 
                    std::next(bool_first1, (container_size-4)*digits + 6), 
                    std::next(bool_first1, container_size*digits - 2)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // f.pos() == nf.pos() and last is aligned
    bret = bit::rotate(
                    std::next(bfirst1, 6),
                    std::next(bfirst1, (container_size-4)*digits + 6), 
                    blast1,
                    bit::STD
    );
    bool_ret = std::rotate(
                    std::next(bool_first1, 6), 
                    std::next(bool_first1, (container_size-4)*digits + 6), 
                    bool_last1
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // f.pos() == nf.pos() and first is aligned
    bret = bit::rotate(
                    std::next(bfirst1, 0),
                    std::next(bfirst1, (container_size-4)*digits), 
                    std::next(bfirst1, container_size*digits - 2),
                    bit::STD
    );
    bool_ret = std::rotate(
                    std::next(bool_first1, 0), 
                    std::next(bool_first1, (container_size-4)*digits), 
                    std::next(bool_first1, container_size*digits - 2)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // f.pos() <= nf.pos() and first is aligned
    bret = bit::rotate(
                    std::next(bfirst1, 0),
                    std::next(bfirst1, (container_size-4)*digits-3), 
                    std::next(bfirst1, container_size*digits - 2),
                    bit::STD
    );
    bool_ret = std::rotate(
                    std::next(bool_first1, 0), 
                    std::next(bool_first1, (container_size-4)*digits), 
                    std::next(bool_first1, container_size*digits - 2)
     );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SHIFT_TESTS_HPP_INCLUDED
// ========================================================================== //
