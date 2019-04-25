// =============================== TEST UTILS =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: test_utils.hpp
// Description: Utility functions to make test writing easier 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _TEST_UTILS_HPP_INCLUDED
#define _TEST_UTILS_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
#include <iostream>
#include <random>
#include <string>
// Project sources
#include "bit.hpp"
// Third-party libraries

/**
 * Creates a length n string of the character '0' repeated
 * @param n the length of the string to be created
 * @return the constructed string
 */
std::string all_zero_str(std::size_t n) {
  return std::string(n, '0');
}

/**
 * Creates a length n string of the character '1' repeated
 * @param n the length of the string to be created
 * @return the constructed string
 */
std::string all_one_str(std::size_t n) {
  return std::string(n, '1');
}

/**
 * Copies a passed string and randomly sets n characters of the new 
 * string to the character passed to the function, c.
 * @param str the string to be copied and have its characters set
 * @param n the number of characters to be set (chosen at random)
 * @param c the character to set at random positions
 * @return a string with c set at n randomly selected positions
 */
std::string set_random_chars(std::string str, std::size_t n, char c) {
  std::vector<std::size_t> indices;
  for (std::size_t i = 0; i < str.size(); i++) {
    indices.push_back(i);
  }
  std::random_device device;
  std::default_random_engine engine(device());
  std::shuffle(indices.begin(), indices.end(), engine);

  for (std::size_t j = 0; j < n; j++) {
    std::size_t index = indices[j];
    str[index] = c;
  }
  return str;
}

/**
 * Copies a poassed string to a new string and randomly chooses
 * n characters of the string to set to '1'.
 * @param str the string to copy from
 * @param n the number of characters to set to '1'
 * @return a string with n characters, chosen at randon, set to '1'
 */
std::string set_n_random_bits(std::string str, std::size_t n) {
  return set_random_chars(str, n, '1');
}

/**
 * Copies a poassed string to a new string and randomly chooses
 * n characters of the string to set to '0'.
 * @param str the string to copy from
 * @param n the number of characters to set to '0'
 * @return a string with n characters, chosen at randon, set to '0'
 */
std::string unset_n_random_bits(std::string str, std::size_t n) {
  return set_random_chars(str, n, '0');
}

/**
 * Get a string of length len filled with 0s and 1s at random
 * @param len the length of the string to be constructed
 * @return the length len string filled with 0s and 1s
 */
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

/**
 * Chooses a number uniformly at random on the range [lower_bound, upper_bound]
 * @param lower_bound the lower bound of the uniform distribution to draw from
 * @param upper_bound the upper bound of the uniform distribution to draw from
 * @return a number drawn uniformly at random on [lower_bound, upper_bound]
 */
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

/**
 * Returns a vector of length len filled with random numbers drawn uniformly
 * @param len the number of elements in the vector
 * @return the vector of random numbers
 */
template <class NumericType>
std::vector<NumericType> get_random_vector(std::size_t len) {
  std::vector<NumericType> vec;
  for (std::size_t i = 0; i < len; i++) {
    vec.push_back(random_number<std::size_t>());
  }
  return vec;
}

/**
 * Converts a string of '0' and '1' to the decimal equivalent
 * @param str a string filled with the characters '0' and '1'
 * @return the decimal equivalent of str
 */
template <class NumericType>
NumericType string_as_bits(std::string str) {
  NumericType num = 0;

  auto begin = bit::bit_iterator<NumericType*>(&num, 0);
  auto end = bit::bit_iterator<NumericType*>(&num + 1, 0);

  for (auto it = begin; it != end; ++it) {
    std::size_t index = std::distance(begin, it);

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

// ========================================================================== //
#endif // _TEST_UTILS_HPP_INCLUDED
// ========================================================================== //
