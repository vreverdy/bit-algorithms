#pragma once

#include "bit.hpp"
#include "catch2.hpp"
#include "test_utils.hpp"
#include "list"

TEMPLATE_TEST_CASE("One word copy of same size", "[copy]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {
  using num_type = TestType;
  auto digits = bit::binary_digits<num_type>::value;
  std::string bit_str1 = random_bit_str(digits);
  num_type bits_1 = string_as_bits<num_type>(bit_str1);
  std::string bit_str2 = random_bit_str(digits);
  num_type bits_2 = string_as_bits<num_type>(bit_str2);
  std::copy(bit_str2.begin(), 
            bit_str2.end(), 
            bit_str1.begin()
  ); 

  auto first = bit::bit_iterator<num_type*>(&bits_1, 0);
  auto last = bit::bit_iterator<num_type*>(&bits_1+1, 0);
  num_type expected_after_copy = string_as_bits<num_type>(bit_str1);

  auto first2 = bit::bit_iterator<num_type*>(&bits_2, 0);
  auto last2 = bit::bit_iterator<num_type*>(&bits_2+1, 0);
  bit::copy(first2, 
            last2,
            first
  );
  REQUIRE(bits_1 == expected_after_copy);
}

TEMPLATE_TEST_CASE("One word partial copy", "[copy]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {
  using num_type = TestType;
  auto digits = bit::binary_digits<num_type>::value;
  std::string bit_str1 = random_bit_str(digits);
  num_type bits_1 = string_as_bits<num_type>(bit_str1);
  std::string bit_str2 = random_bit_str(digits);
  num_type bits_2 = string_as_bits<num_type>(bit_str2);
  std::copy(bit_str2.begin()+8, 
            bit_str2.end()-4, 
            bit_str1.begin()+2
  ); 

  auto first = bit::bit_iterator<num_type*>(&bits_1, 0);
  auto last = bit::bit_iterator<num_type*>(&bits_1+1, 0);
  num_type expected_after_copy = string_as_bits<num_type>(bit_str1);

  auto first2 = bit::bit_iterator<num_type*>(&bits_2, 0);
  auto last2 = bit::bit_iterator<num_type*>(&bits_2+1, 0);
  bit::copy(first2+8, 
            last2-4,
            first+2
  );
  REQUIRE(bits_1 == expected_after_copy);
}

TEMPLATE_PRODUCT_TEST_CASE("Copy: copy to smaller words correct", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned short>
                                     (container_size*8); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first1_t = bool_first1;
    auto bool_first2_t = bool_first2;
    auto bfirst1_t = bfirst1;
    auto bfirst2_t = bfirst2;
    auto bool_last1_t = bool_last1;
    auto bool_last2_t = bool_last2;
    auto blast1_t = blast1;
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

}

TEMPLATE_PRODUCT_TEST_CASE("Copy: copy to larger words correct", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned long long>
                                     (container_size*8); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first1_t = bool_first1;
    auto bool_first2_t = bool_first2;
    auto bfirst1_t = bfirst1;
    auto bfirst2_t = bfirst2;
    auto bool_last1_t = bool_last1;
    auto bool_last2_t = bool_last2;
    auto blast1_t = blast1;
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

}


TEMPLATE_PRODUCT_TEST_CASE("Copy: same size not aligned copy correct", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type>
                                     (container_size); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first1_t = bool_first1;
    auto bool_first2_t = bool_first2;
    auto bfirst1_t = bfirst1;
    auto bfirst2_t = bfirst2;
    auto bool_last1_t = bool_last1;
    auto bool_last2_t = bool_last2;
    auto blast1_t = blast1;
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    copy(bfirst1_t, blast1_t, bfirst2_t);
    std::copy(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));

}
