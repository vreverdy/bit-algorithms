#include <vector>
#include "bit.hpp"

int main() {

  std::vector<unsigned int> v = {1, 2, 3};

  auto b = v.begin();
  auto e = v.end();

  auto it = bit::bit_iterator<decltype(b)>(b);

  std::cout << *it << "\n";

  return 0;
}
