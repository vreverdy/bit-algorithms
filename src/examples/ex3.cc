#include <iostream>
#include <list>
#include <vector>

#include "bit.hpp"

void print_list(std::list<unsigned short>& l) {
  auto begin = l.begin();
  std::cout << "[" << *begin;
  for (auto it = begin; it != l.end(); ++it) {
    std::cout << ", " << *it;
  } 
  std::cout << "]\n";
}

/* In this example, we show that bit iterators can be used for non-contiguously
 * allocated containers, while using raw pointers to these container elements 
 * does not work. 
 */
int main() {
  
  std::list<unsigned short> short_list(5, 0);

  print_list(short_list);

  using list_iter = std::list<unsigned short>::iterator;

  list_iter list_first = short_list.begin();
  list_iter list_second = ++short_list.begin();
  

  /* Bit iteration works even when items are not contiguous in memory. This is only 
     true if the bit iterator is wrapping a container iterator. That is -- wrapping
     raw pointers won't work.
  */
  std::cout << "Address of first short in list: " << &(*list_first) << "\n";
  std::cout << "Address of second short in list: " << &(*list_second) << "\n";
  std::cout << "Size of unsigned short: " << sizeof(unsigned short) << "\n";

  bit::bit_iterator<list_iter> bit_begin(list_first);
  bit::bit_iterator<list_iter> bit_end(short_list.end());

  for (auto it = bit_begin; it != bit_end; ++it) {
    // by dereferencing a bit iterator, we get a bit_reference which can be
    // used to alter a bit value at a particular position
    bit::bit_reference<unsigned short> bit_ref = *it; 
    bit_ref.set();
    assert(bit_ref == bit::bit1);
  }

  print_list(short_list);

  bit::bit_iterator<unsigned short*> first_item_iter(&(*list_first));
  bit::bit_iterator<unsigned short*> second_item_iter(&(*list_second));

  /* after the last bit of the number is reached, we cant expect the bit_iterator
     to move to the next element of the container as the bit_iterator has no reference
     to the container. 
  */
  std::advance(first_item_iter, bit::binary_digits<unsigned short>::value);
  assert(first_item_iter != second_item_iter);
}
