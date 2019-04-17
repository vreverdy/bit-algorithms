#ifndef BA_FILL_N
#define BA_FILL_N

namespace bit {

template <class WrappedIter, class Size>
void fill_n(bit_iterator<WrappedIter> first, Size count, bit::bit_value bv) {
  bit_iterator<WrappedIter> last = first + count;
  bit::fill(first, last, bv); 
}

}

#endif
