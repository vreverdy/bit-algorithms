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

  unsigned short a = 4389;
  unsigned short b = 4453; 

  using biter = bit::bit_iterator<unsigned short*>;

  biter a_biter_beg(&a, 0);
  biter a_biter_end(&a + 1, 0);
  biter b_biter_beg(&b, 0);
  biter b_biter_end(&b + 1, 0);

  std::pair<biter, biter> res = bit::mismatch(a_biter_beg, a_biter_end, 
      b_biter_beg, b_biter_end);

  std::cout << res.first.position() << std::endl;
  std::cout << res.second.position() << std::endl;

  std::vector<unsigned int> v1 = {1, 1};
  std::vector<unsigned int> v2 = {1, 1, 3, 4, 7};

  bit::bit_iterator<vec_iter> v1_beg(v1.begin());
  bit::bit_iterator<vec_iter> v1_end(v1.end());
  bit::bit_iterator<vec_iter> v2_beg(v2.begin());
  bit::bit_iterator<vec_iter> v2_end(v2.end());

  auto res2 = bit::mismatch(v1_beg, v1_end, v2_beg, v2_end);

  std::cout << res2.first.position() << std::endl; 
  std::cout << res2.second.position() << std::endl; 
}
