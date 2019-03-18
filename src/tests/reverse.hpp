#pragma once

#include "bit.hpp"
#include "catch2.hpp"
#include "test_utils.hpp"

TEMPLATE_TEST_CASE("Single number: full reverse correct", "[reverse]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  using num_type = TestType;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);

  std::string bit_str_reversed = bit_str;
  std::reverse(bit_str_reversed.begin(), bit_str_reversed.end());

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);

  reverse(bit::bit_iterator<num_type*>(&num, 0), bit::bit_iterator<num_type*>(&num + 1, 0));
  REQUIRE(num == expected_after_reverse);
}

TEMPLATE_TEST_CASE("Single number: correct where all bits zero", "[reverse]", unsigned short, unsigned int,
  unsigned long, unsigned long long) {

  using num_type = TestType;

  num_type num = 0;
  num_type expected_after_reverse = 0;

  reverse(bit::bit_iterator<num_type*>(&num, 0), bit::bit_iterator<num_type*>(&num + 1, 0));
  REQUIRE(num == expected_after_reverse);
}

TEMPLATE_TEST_CASE("Single number: correct where all bits one", "[reverse]", unsigned short, unsigned int,
  unsigned long, unsigned long long) {

  using num_type = TestType;

  num_type num = -1;
  num_type expected_after_reverse = -1;

  reverse(bit::bit_iterator<num_type*>(&num, 0), bit::bit_iterator<num_type*>(&num + 1, 0));
  REQUIRE(num == expected_after_reverse);
}

TEMPLATE_TEST_CASE("Single number: reverses only within the iteration range (first-half)", "[reverse]", unsigned short, unsigned int,
  unsigned long, unsigned long long) {

  using num_type = TestType;

  constexpr auto num_digits = bit::binary_digits<num_type>::value;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);
  std::string bit_str_reversed = bit_str;

  std::reverse(bit_str_reversed.begin(), bit_str_reversed.begin() + num_digits / 2);

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);

  reverse(bit::bit_iterator<num_type*>(&num, 0), bit::bit_iterator<num_type*>(&num, num_digits / 2));
  REQUIRE(num == expected_after_reverse);
}

TEMPLATE_TEST_CASE("Single number: reverses only within the iteration range (second-half)", "[reverse]", unsigned short, unsigned int,
  unsigned long, unsigned long long) {

  using num_type = TestType;

  constexpr auto num_digits = bit::binary_digits<num_type>::value;

  std::string bit_str = random_bit_str(bit::binary_digits<num_type>::value);
  std::string bit_str_reversed = bit_str;

  std::reverse(bit_str_reversed.begin() + num_digits / 2, bit_str_reversed.end());

  num_type num = string_as_bits<num_type>(bit_str);
  num_type expected_after_reverse = string_as_bits<num_type>(bit_str_reversed);

  reverse(bit::bit_iterator<num_type*>(&num, num_digits / 2), bit::bit_iterator<num_type*>(&num + 1, 0));
  REQUIRE(num == expected_after_reverse);
}

TEMPLATE_TEST_CASE("Single number: does nothing if iteration range is empty", "[reverse]", unsigned short, unsigned int,
  unsigned long, unsigned long long) {

  using num_type = TestType;

  num_type num = random_number<num_type>();
  num_type expected_after_reverse = num;

  constexpr auto num_digits = bit::binary_digits<num_type>::value;
  auto random_position = random_number(static_cast<std::size_t>(0), num_digits - 1);

  reverse(bit::bit_iterator<num_type*>(&num, random_position), bit::bit_iterator<num_type*>(&num, random_position));
  REQUIRE(num == expected_after_reverse);
}
