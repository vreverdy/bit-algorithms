#include <cmath>
#include <iostream>

#include "bit.hpp"

/* In this example, we count the number of unset bits in an unsigned short.
 * We also demonstrate the usage of bit::binary_digits<T>
 */
int main() {

  std::size_t num_binary_digits = bit::binary_digits<unsigned short>::value;
  std::cout << "There are " << num_binary_digits 
    << " bits in an unsigned short on your machine\n";

  /* we can create an unsigned short where the less significant half of the
     bits are all set.  
  */
  unsigned short num = static_cast<unsigned short>(-1) << (num_binary_digits / 2);

  /* We can create bit iterators to the beginning and end of num
     by wrapping raw pointers rather than actual iterators. 

     Here we use the bit iterator constructor
     bit_iterator<T>::bit_iterator(T iter, size_type pos) where
     iter is the iterator (in this case an address) and pos indicates
     the nth binary_digit of num, starting from the LSB
  */
  bit::bit_iterator<unsigned short*> beg(&num, 0); 
  bit::bit_iterator<unsigned short*> end(&num + 1, 0);

  std::cout << "The number " << num << " as binary: ";
  while (beg != end) {
    std::cout << *beg;
    ++beg;
  }
  std::cout << std::endl;
}
