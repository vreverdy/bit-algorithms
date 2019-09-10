// ============================== COPY TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            copy.hpp
// Description:     Tests for copy, copy_if, copy_n and copy_backwards
//                  algorithms
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _COPY_TESTS_HPP_INCLUDED
#define _COPY_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ------------------------------- Copy Tests ------------------------------- //
TEMPLATE_TEST_CASE("Copy: One word copy of same size", "[copy]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {
  using num_type = TestType;
  auto digits = bit::binary_digits<num_type>::value;
  std::string bit_str1 = random_bit_str(digits);
  num_type bits_1 = string_as_bits<num_type>(bit_str1);
  std::string bit_str2 = random_bit_str(digits);
  num_type bits_2 = string_as_bits<num_type>(bit_str2);
  std::copy(bit_str2.begin(), 
            bit_str2.end(), 
            bit_str1.begin()
  ); 

  auto first = bit::bit_iterator<num_type*>(&bits_1, 0);
  num_type expected_after_copy = string_as_bits<num_type>(bit_str1);

  auto first2 = bit::bit_iterator<num_type*>(&bits_2, 0);
  auto last2 = bit::bit_iterator<num_type*>(&bits_2+1, 0);
  bit::copy(first2, 
            last2,
            first
  );
  REQUIRE(bits_1 == expected_after_copy);
}

TEMPLATE_TEST_CASE("Copy: One word partial copy", "[copy]",
  unsigned short) {
  using num_type = TestType;
  auto digits = bit::binary_digits<num_type>::value;
  std::string bit_str1 = random_bit_str(digits);
  num_type bits_1 = string_as_bits<num_type>(bit_str1);
  std::string bit_str2 = random_bit_str(digits);
  num_type bits_2 = string_as_bits<num_type>(bit_str2);
  std::copy(bit_str2.begin()+3, 
            bit_str2.end()-3, 
            bit_str1.begin()+2
  ); 

  auto first = bit::bit_iterator<num_type*>(&bits_1, 0);
  //auto last = bit::bit_iterator<num_type*>(&bits_1+1, 0);
  num_type expected_after_copy = string_as_bits<num_type>(bit_str1);

  auto first2 = bit::bit_iterator<num_type*>(&bits_2, 0);
  auto last2 = bit::bit_iterator<num_type*>(&bits_2+1, 0);
  bit::copy(first2+3, 
            last2-3,
            first+2
  );
  REQUIRE(bits_1 == expected_after_copy);
}

TEMPLATE_PRODUCT_TEST_CASE("Copy: copy to smaller words correct", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned char>
                                     (container_size*16); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);

    auto bret = bit::copy(
            bfirst1, 
            blast1,
            bfirst2
    );
    auto bool_ret = std::copy(
            bool_first1, 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            blast1,
            bfirst2
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            bfirst2
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            bfirst1, 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            bool_first1, 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Copy: copy to larger words correct", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned long long>
                                     (container_size*8); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);

    auto bret = bit::copy(
            bfirst1, 
            blast1,
            bfirst2
    );
    auto bool_ret = std::copy(
            bool_first1, 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            blast1,
            bfirst2
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            bfirst2
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            bfirst1, 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            bool_first1, 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

}


TEMPLATE_PRODUCT_TEST_CASE("Copy: same size not aligned copy correct", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 6;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type>
                                     (container_size*2); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);

    auto bret = bit::copy(
            bfirst1, 
            blast1,
            bfirst2
    );
    auto bool_ret = std::copy(
            bool_first1, 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            blast1,
            bfirst2
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            bfirst2
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            bfirst1, 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            bool_first1, 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bret = bit::copy(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::copy(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _COPY_TESTS_HPP_INCLUDED
// ========================================================================== //
