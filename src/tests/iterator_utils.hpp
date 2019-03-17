#pragma once

#include "bit.hpp"
#include "catch2.hpp"
#include "test_utils.hpp"

TEMPLATE_TEST_CASE("RAI: Positive difference", "[distance]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  using num_type = TestType;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);

  std::string bit_str_reversed = bit_str;
  std::reverse(bit_str_reversed.begin(), bit_str_reversed.end());

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);
  
  auto digits = bit::binary_digits<num_type>::value;
  auto n = 5;
  auto first_iter = bit::bit_iterator<num_type*>(&num, digits-3);
  auto last_iter = first_iter + n;
  auto bit_dist = bit::distance(first_iter, last_iter);
  REQUIRE(bit_dist == n);
  
  n += digits;
  last_iter = first_iter + n;
  bit_dist = bit::distance(first_iter, last_iter);
  REQUIRE(bit_dist == n);
}

TEMPLATE_TEST_CASE("RAI: Negative difference", "[distance]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  using num_type = TestType;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);

  std::string bit_str_reversed = bit_str;
  std::reverse(bit_str_reversed.begin(), bit_str_reversed.end());

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);
  
  auto digits = bit::binary_digits<num_type>::value;
  auto n = -3;
  auto first_iter = bit::bit_iterator<num_type*>((&num)+1, 6);
  auto last_iter = first_iter + n;
  auto bit_dist = bit::distance(first_iter, last_iter);
  REQUIRE(bit_dist == n);
  
  n -= digits;
  last_iter = first_iter + n;
  bit_dist = bit::distance(first_iter, last_iter);
  REQUIRE(bit_dist == n);
}

TEMPLATE_TEST_CASE("RAI: Positive advance", "[advance]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  using num_type = TestType;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);

  std::string bit_str_reversed = bit_str;
  std::reverse(bit_str_reversed.begin(), bit_str_reversed.end());

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);
  
  auto digits = bit::binary_digits<num_type>::value;
  auto n = 2;
  auto orig_iter = bit::bit_iterator<num_type*>((&num)+3, 6);
  auto test_iter = orig_iter;
  auto expected_iter = test_iter + n;
  bit::advance(test_iter, n);
  REQUIRE(test_iter == expected_iter);
  
  n += digits;
  test_iter = orig_iter;
  expected_iter = test_iter + n;
  bit::advance(test_iter, n);
  REQUIRE(test_iter == expected_iter);
}

TEMPLATE_TEST_CASE("RAI: Negative advance", "[advance]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  using num_type = TestType;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);

  std::string bit_str_reversed = bit_str;
  std::reverse(bit_str_reversed.begin(), bit_str_reversed.end());

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);
  
  auto digits = bit::binary_digits<num_type>::value;
  auto n = -2;
  auto orig_iter = bit::bit_iterator<num_type*>((&num)+3, 6);
  auto test_iter = orig_iter;
  auto expected_iter = test_iter + n;
  bit::advance(test_iter, n);
  REQUIRE(test_iter == expected_iter);
  
  n -= digits;
  test_iter = orig_iter;
  expected_iter = test_iter + n;
  bit::advance(test_iter, n);
  REQUIRE(test_iter == expected_iter);
}
