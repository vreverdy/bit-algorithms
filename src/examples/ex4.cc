#include <cmath>
#include <iostream>
#include <vector>

#include "bit.hpp"

int main() {
  unsigned int x = 3;

  bit::bit_iterator<unsigned int*> first(&x, 0);
  bit::bit_iterator<unsigned int*> last(&x, 4);

  bit::fill(first, last, bit::bit1); 
  assert(x == 15);

  bit::bit_iterator<unsigned int*> end(&x + 1, 0);
  bit::fill(first, end, bit::bit1);
  assert(x == static_cast<unsigned int>(-1));

  unsigned int another_one = 0;
  bit::bit_iterator<unsigned int*> inner_beg(&another_one, 2);
  bit::bit_iterator<unsigned int*> inner_end(&another_one, 6); 

  bit::fill(inner_beg, inner_end, bit::bit1);
  assert(another_one == 60);

  std::vector<unsigned int> v = {0, 0, 3, 4, 5};
  using vec_iter = std::vector<unsigned int>::iterator;

  vec_iter beg0 = v.begin();
  vec_iter beg2 = beg0 + 2;

  bit::bit_iterator<vec_iter> bit_beg0(beg0);
  bit::bit_iterator<vec_iter> bit_beg2(beg2);

  bit::fill(bit_beg0, bit_beg2, bit::bit1);

  assert(v[0] == static_cast<unsigned int>(-1) &&
         v[1] == static_cast<unsigned int>(-1));
}
