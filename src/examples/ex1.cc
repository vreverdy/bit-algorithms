#include <iostream>
#include <vector>

#include "bit.hpp"

/* In this example, we count the number of bits set in a vector
 * of unsigned ints using count()
 */
int main() {
  
  std::vector<unsigned int> v = {4, 2, 3};
  // at a bit level on a big endian architecture: 
  // v[0] = 0...0100, v[1] = 0...0010, v[2] = 0...0011

  // get vector iterators as normal
  using vec_iter = std::vector<unsigned int>::iterator;
  vec_iter beg = v.begin();
  vec_iter end = v.end();

  // get bitwise iterators by wrapping vector iterator with bit::bit_iterator<T>
  using bit_iterator = bit::bit_iterator<vec_iter>;
  bit_iterator bit_begin(beg);
  bit_iterator bit_end(end);

  // count the number of bits equal to 1 (bit::bit1) in the range defined by bit_begin and bit_end
  std::size_t num_bits_set = count(bit_begin, bit_end, bit::bit1);
  std::cout << "Count: " << num_bits_set << "\n";

  return 0;
}
