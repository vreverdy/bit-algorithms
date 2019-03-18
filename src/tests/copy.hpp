#pragma once

#include "bit.hpp"
#include "catch2.hpp"
#include "test_utils.hpp"
#include <iostream>

TEMPLATE_TEST_CASE("One word copy of same size", "[copy]",
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
  auto last = bit::bit_iterator<num_type*>(&bits_1+1, 0);
  num_type expected_after_copy = string_as_bits<num_type>(bit_str1);

  auto first2 = bit::bit_iterator<num_type*>(&bits_2, 0);
  auto last2 = bit::bit_iterator<num_type*>(&bits_2+1, 0);
  bit::copy(first2, 
            last2,
            first
  );
  REQUIRE(bits_1 == expected_after_copy);
}

TEMPLATE_TEST_CASE("One word partial copy", "[copy]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {
  using num_type = TestType;
  auto digits = bit::binary_digits<num_type>::value;
  std::string bit_str1 = random_bit_str(digits);
  num_type bits_1 = string_as_bits<num_type>(bit_str1);
  std::string bit_str2 = random_bit_str(digits);
  num_type bits_2 = string_as_bits<num_type>(bit_str2);
  std::copy(bit_str2.begin()+8, 
            bit_str2.end()-4, 
            bit_str1.begin()+2
  ); 

  auto first = bit::bit_iterator<num_type*>(&bits_1, 0);
  auto last = bit::bit_iterator<num_type*>(&bits_1+1, 0);
  num_type expected_after_copy = string_as_bits<num_type>(bit_str1);

  auto first2 = bit::bit_iterator<num_type*>(&bits_2, 0);
  auto last2 = bit::bit_iterator<num_type*>(&bits_2+1, 0);
  bit::copy(first2+8, 
            last2-4,
            first+2
  );
  REQUIRE(bits_1 == expected_after_copy);
}

