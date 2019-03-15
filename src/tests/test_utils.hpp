#pragma once

#include <iostream>
#include <random>
#include <string>

#include "bit.hpp"

std::string random_bit_str(std::size_t len) {
  std::random_device device;
  std::default_random_engine engine(device());
  std::uniform_int_distribution<int> uniform_dist(0, 1);

  std::string bit_str = "";
  for (std::size_t i = 0; i < len; i++) {
    int bit = uniform_dist(engine);
    int char_bit = '0' + bit;

    bit_str += char_bit;
  }
  return bit_str;
}

template <class NumericType>
NumericType random_number(
  NumericType lower_bound = std::numeric_limits<NumericType>::min(),
  NumericType upper_bound = std::numeric_limits<NumericType>::max()
) {
  std::random_device device;
  std::default_random_engine engine(device());
  std::uniform_int_distribution<NumericType> numeric_dist(lower_bound, upper_bound);

  return numeric_dist(engine);
}

template <class NumericType>
NumericType string_as_bits(std::string str) {
  NumericType num = 0;

  auto begin = bit::bit_iterator<NumericType*>(&num, 0);
  auto end = bit::bit_iterator<NumericType*>(&num + 1, 0);

  for (auto it = begin; it != end; ++it) {
    auto index = std::distance(begin, it);

    if (index > str.size() - 1) {
      break;
    }

    char cur = str[index];

    assert(cur == '0' || cur == '1');

    if (cur == '0') {
      *it = bit::bit0;
    } else {
      *it = bit::bit1;
    }
  }

  return num;
}
