#ifndef BA_SEARCH_TEST
#define BA_SEARCH_TEST

#include "catch2.hpp"
#include "test_utils.hpp"

TEMPLATE_TEST_CASE("Single number: finds a simple pattern", "[search]", unsigned short, unsigned int, unsigned long, unsigned long long) {
  using num_type = TestType;

  // pattern in question is 10101
  num_type needle = 21;
  bit_iterator<num_type*> n_beg(&needle, 0);
  bit_iterator<num_type*> n_end(&needle, 5);

  // searching in 0...10101001
  num_type haystack = 169;
  bit_iterator<num_type*> h_beg(&haystack, 0);
  bit_iterator<num_type*> h_end(&haystack + 1, 0);

  bit_iterator<num_type*> res = std::search(h_beg, h_end, n_beg, n_end);

  REQUIRE(res != h_end);
}

#endif
