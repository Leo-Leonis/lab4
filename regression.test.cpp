#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "regression.hpp"

TEST_CASE("Testing Regression 0") {
  Regression reg;
  reg.add(0., 1.);
  reg.add(1., 2.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1.));
  CHECK(result.B == doctest::Approx(1.));
  CHECK(result.numeri == 2);
}

TEST_CASE("Testing Regression 1") {
  Regression reg;
  reg.add(65., -20.);
  reg.add(75., 17.);
  reg.add(85., 42.);
  reg.add(95., 94.);
  reg.add(105., 127.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(-263.35));
  CHECK(result.B == doctest::Approx(3.71));
  CHECK(result.numeri == 5);
}

TEST_CASE("Testing Regression 2") {
  Regression reg;
  reg.add(79., 8.);
  reg.add(82., 17.);
  reg.add(85., 30.);
  reg.add(88., 37.);
  reg.add(90., 52.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(-294.904));
  CHECK(result.B == doctest::Approx(3.817259));
  CHECK(result.numeri == 5);
}
