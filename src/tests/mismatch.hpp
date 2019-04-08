#pragma once

#include "catch2.hpp"
#include "test_utils.hpp"

using bit::bit_iterator;

TEMPLATE_TEST_CASE("Single number", "[mismatch]", unsigned short, unsigned int, unsigned long, unsigned long long) {
  using num_type = TestType;
  num_type n1 = 4;
  num_type n2 = 8;

  bit_iterator<num_type*> n1_beg(&n1, 0);
  bit_iterator<num_type*> n2_beg(&n2, 0);

  bit_iterator<num_type*> n1_end(&n1 + 1, 0);
  bit_iterator<num_type*> n2_end(&n2 + 1, 0);

  auto p = mismatch(n1_beg, n1_end, n2_beg, n2_end);

  REQUIRE(p.first.position() == 2);
}

TEMPLATE_TEST_CASE("Vector", "[mismatch]", unsigned short, unsigned int,
    unsigned long, unsigned long long) {
  
  using vec_type = std::vector<TestType>;

  vec_type vec1 = {2, 3, 4, 5};
  vec_type vec2 = {2, 3, 5, 4};
  
  bit_iterator<typename vec_type::iterator> b1(vec1.begin(), 0);
  bit_iterator<typename vec_type::iterator> b2(vec2.begin(), 0);
  bit_iterator<typename vec_type::iterator> e1(vec1.end(), 0);
  bit_iterator<typename vec_type::iterator> e2(vec2.end(), 0);

  bit_iterator<typename vec_type::iterator> expected1(vec1.begin() + 2, 0);
  bit_iterator<typename vec_type::iterator> expected2(vec2.begin() + 2, 0);

  auto p = mismatch(b1, e1, b2, e2); 
   
  REQUIRE(expected1.position() == p.first.position());
  REQUIRE(*expected1 == *(p.first));
  REQUIRE(expected2.position() == p.second.position());
  REQUIRE(*expected2 == *(p.second));
}
