// ============================== COUNT TESTS =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: count.hpp
// Description: Tests for std::count bit iterator overloads 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _COUNT_TESTS_HPP_INCLUDED
#define _COUNT_TESTS_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_utils.hpp"
// Third party libraries
#include "catch2.hpp"

TEMPLATE_TEST_CASE("Single number: correctly counts number of set bits in random number", 
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {

    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    std::string bit_str = all_zero_str(num_binary_digits);

    std::size_t num_bits_to_set = random_number<std::size_t>(0, num_binary_digits);
    bit_str = set_n_random_bits(bit_str, num_bits_to_set);

    std::size_t expected_bits_set = num_bits_to_set;
    
    num_type num = string_as_bits<num_type>(bit_str);

    std::size_t num_bits_set = count(bit::bit_iterator<num_type*>(&num, 0),
        bit::bit_iterator<num_type*>(&num + 1, 0), bit::bit1);

    REQUIRE(num_bits_set == expected_bits_set);
}

TEMPLATE_TEST_CASE("Single number: correctly counts number of unset bits in random number", 
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {

    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    std::string bit_str = all_one_str(num_binary_digits);

    std::size_t num_bits_to_unset = random_number<std::size_t>(0, num_binary_digits);
    bit_str = unset_n_random_bits(bit_str, num_bits_to_unset);

    std::size_t expected_bits_unset = num_bits_to_unset;
    
    num_type num = string_as_bits<num_type>(bit_str);

    std::size_t num_bits_unset = count(bit::bit_iterator<num_type*>(&num, 0),
        bit::bit_iterator<num_type*>(&num + 1, 0), bit::bit0);

    REQUIRE(num_bits_unset == expected_bits_unset);
}

TEMPLATE_TEST_CASE("Single number: correctly counts number of unset bits where bits all zero",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    num_type num = 0;
    std::size_t num_bits_unset = count(bit::bit_iterator<num_type*>(&num, 0),
        bit::bit_iterator<num_type*>(&num + 1, 0), bit::bit0);

    REQUIRE(num_bits_unset == num_binary_digits); 
}

TEMPLATE_TEST_CASE("Single number: correctly counts number of unset bits where bits all one",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    num_type num = -1;
    std::size_t num_bits_unset = count(bit::bit_iterator<num_type*>(&num, 0),
        bit::bit_iterator<num_type*>(&num + 1, 0), bit::bit0);

    REQUIRE(num_bits_unset == 0); 
}

TEMPLATE_TEST_CASE("Single number: correctly counts number of set bits where bits all zero",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    num_type num = 0;
    std::size_t num_bits_set = count(bit::bit_iterator<num_type*>(&num, 0),
        bit::bit_iterator<num_type*>(&num + 1, 0), bit::bit1);

    REQUIRE(num_bits_set == 0); 
}

TEMPLATE_TEST_CASE("Single number: correctly counts number of set bits where bits all one",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    num_type num = -1;
    std::size_t num_bits_set = count(bit::bit_iterator<num_type*>(&num, 0),
        bit::bit_iterator<num_type*>(&num + 1, 0), bit::bit1);

    REQUIRE(num_bits_set == num_binary_digits); 
}

TEMPLATE_TEST_CASE("Vector: correctly counts number of set bits in vector of random numbers", 
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    std::size_t vec_len = random_number<std::size_t>(2, 100);

    std::size_t expected_bits_set = 0;
    
    std::vector<num_type> nums;

    for (std::size_t i = 0; i < vec_len; i++) {
        std::size_t num_bits_to_set = random_number<num_type>(0, num_binary_digits);
        std::string str = all_zero_str(num_binary_digits);
        str = set_n_random_bits(str, num_bits_to_set);
        num_type num = string_as_bits<num_type>(str);
        nums.push_back(num);
        expected_bits_set += num_bits_to_set;
    }

    auto nums_begin = nums.begin();
    auto nums_end = nums.end();

    std::size_t num_bits_set = count(
        bit::bit_iterator<decltype(nums_begin)>(nums_begin),
        bit::bit_iterator<decltype(nums_end)>(nums_end),
        bit::bit1
    );

    REQUIRE(num_bits_set == expected_bits_set);
}

TEMPLATE_TEST_CASE("Vector: correctly counts number of unset bits in vector of random numbers", 
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    std::size_t vec_len = random_number<std::size_t>(2, 100);

    std::size_t expected_bits_unset = 0;
    
    std::vector<num_type> nums;

    for (std::size_t i = 0; i < vec_len; i++) {
        std::size_t num_bits_to_unset = random_number<num_type>(0, num_binary_digits);
        std::string str = all_one_str(num_binary_digits);
        str = unset_n_random_bits(str, num_bits_to_unset);
        num_type num = string_as_bits<num_type>(str);
        nums.push_back(num);
        expected_bits_unset += num_bits_to_unset;
    }

    auto nums_begin = nums.begin();
    auto nums_end = nums.end();

    std::size_t num_bits_unset = count(
      bit::bit_iterator<decltype(nums_begin)>(nums_begin),
      bit::bit_iterator<decltype(nums_end)>(nums_end),
      bit::bit0
    );

    REQUIRE(num_bits_unset == expected_bits_unset);
}

TEMPLATE_TEST_CASE("Vector: correctly counts number of set bits where bits all one",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    std::size_t vec_len = random_number<std::size_t>(2, 100);

    std::size_t expected_bits_set = num_binary_digits * vec_len;

    std::vector<num_type> nums(vec_len, -1);

    auto nums_begin = nums.begin();
    auto nums_end = nums.end();

    std::size_t num_bits_set = count(
        bit::bit_iterator<decltype(nums_begin)>(nums_begin),
        bit::bit_iterator<decltype(nums_end)>(nums_end),
        bit::bit1
    );

    REQUIRE(num_bits_set == expected_bits_set);
}

TEMPLATE_TEST_CASE("Vector: correctly counts number of unset bits where bits all one",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    std::size_t vec_len = random_number<std::size_t>(2, 100);
    std::size_t expected_bits_unset = 0;

    std::vector<num_type> nums(vec_len, -1);

    auto nums_begin = nums.begin();
    auto nums_end = nums.end();

    std::size_t num_bits_unset = count(
        bit::bit_iterator<decltype(nums_begin)>(nums_begin),
        bit::bit_iterator<decltype(nums_end)>(nums_end),
        bit::bit0
    );

    REQUIRE(num_bits_unset == expected_bits_unset);
}

TEMPLATE_TEST_CASE("Vector: correclty counts number of set bits where bits all zero",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    std::size_t vec_len = random_number<std::size_t>(2, 100);
    std::size_t expected_bits_set = 0;

    std::vector<num_type> nums(vec_len, 0);

    auto nums_begin = nums.begin();
    auto nums_end = nums.end();

    std::size_t num_bits_set = count(
        bit::bit_iterator<decltype(nums_begin)>(nums_begin),
        bit::bit_iterator<decltype(nums_end)>(nums_end),
        bit::bit1
    );

    REQUIRE(num_bits_set == expected_bits_set);
}

TEMPLATE_TEST_CASE("Vector: correctly counts number of unset bits where bits all zero",
    "[count]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    using num_type = TestType;

    constexpr auto num_binary_digits = bit::binary_digits<num_type>::value;

    std::size_t vec_len = random_number<std::size_t>(2, 100);

    std::size_t expected_bits_unset = num_binary_digits * vec_len;

    std::vector<num_type> nums(vec_len, 0);

    auto nums_begin = nums.begin();
    auto nums_end = nums.end();

    std::size_t num_bits_unset = count(
        bit::bit_iterator<decltype(nums_begin)>(nums_begin),
        bit::bit_iterator<decltype(nums_end)>(nums_end),
        bit::bit0
    );

    REQUIRE(num_bits_unset == expected_bits_unset);
}

// ========================================================================== //
#endif // _COUNT_TESTS_HPP_INCLUDED
// ========================================================================== //

