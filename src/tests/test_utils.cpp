// ============================= TEST_UTILS ================================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            test_utils.cpp
// Description:     General utilities for testing
// Creator:         Bryce Kille
// Contributor(s):  Bryce Kille [2019], 
//                  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //


// ================================ PREAMBLE ================================ //
// C++ standard library
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
// Project sources
#include "bit.hpp"
#include "test_utils.hpp"
#include "test_utils.hpp"
// Third-party libraries
// Miscellaneous


// =============================== DEBUGGING ================================ //
// Display algorithm
template <class O, class Iterator> 
void display(O&& os, bit::bit_iterator<Iterator> first, bit::bit_iterator<Iterator> last)
{
    auto mem = first;
    for (auto it = first; it != last; ++it) {
        if (it.base() != mem.base()) {
            os << " ";
        } else if (it.position() % 8 == 0 && it.position() != 0) {
            os << '.';
        }
        std::forward<O>(os) << *it;
        mem = it;
    }
    std::forward<O>(os) << std::endl;
}

template <class O, class Iterator> 
void display(O&& os, Iterator first, Iterator last, size_t size)
{
    auto mem = first;
    auto position = 0;
    for (auto it = first; it != last; ++it) {
        if (position % size == 0 && position != 0) {
            os << " ";
        } else if (position % 8 == 0 && position != 0) {
            os << '.';
        }
        std::forward<O>(os) << *it;
        mem = it;
        ++position;
    }
    std::forward<O>(os) << std::endl;
}
// ========================================================================== //



// ================================ TESTING ================================- //
// ========================================================================== //



// =============================== BIT_STRING =============================== //
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
 * Copies a passed string to a new string and randomly chooses
 * n characters of the string to set to '1'.
 * @param str the string to copy from
 * @param n the number of characters to set to '1'
 * @return a string with n characters, chosen at randon, set to '1'
 */
std::string set_n_random_bits(std::string str, std::size_t n) {
  return set_random_chars(str, n, '1');
}

/**
 * Copies a passed string to a new string and randomly chooses
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
// ========================================================================== //
