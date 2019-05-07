#include <iostream>

namespace bit {

template <class Iterator>
class input_iterator {
public:
    using value_type = typename Iterator::value_type;
    using iterator_category = input_iterator;
private:
    Iterator it_;
public:
    input_iterator(Iterator it)
      : it_(it) {}

    bool operator==(const input_iterator<Iterator>& rhs) const {
        return it_ == rhs.it_;
    }

    bool operator!=(const input_iterator<Iterator>& rhs) const {
        return !operator==(rhs);
    } 
};

}
