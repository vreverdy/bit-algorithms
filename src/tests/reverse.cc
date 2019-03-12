#include <vector>
#include "bit.hpp"
#include "catch2.hpp"

using ULL = unsigned long long int;

TEST_CASE("placeholder", "[stuff]") {

  std::vector<ULL> vec;

  auto first = vec.begin();
  auto last = vec.end();

  bit::bit_iterator<decltype(first)> bit_first(first);
  bit::bit_iterator<decltype(last)> bit_last(last); 

  reverse(bit_first, bit_last);

  REQUIRE(1 == 1);
}
