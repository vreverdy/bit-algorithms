#pragma once

#include "catch2.hpp"
#include "test_utils.hpp"

TEMPLATE_TEST_CASE("tmp", "tmp",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  REQUIRE(2 == 2);
}
