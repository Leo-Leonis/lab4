#include "regression.hpp"

void Regression::add(double x, double y) {
    ++N_;
    sumx_ += x;
    sumy_ += y;
    sumxx_ += x * x;
    sumxy_ += x * y;
}

Result Regression::fit() const {
    // quota a
    double const a = ((sumy_ * sumxx_) - (sumx_ * sumxy_)) /
                     ((N_ * sumxx_) - (sumx_ * sumx_));
    // pendenza b
    double const b =
        ((N_ * sumxy_) - (sumx_ * sumy_)) / ((N_ * sumxx_) - (sumx_ * sumx_));
    return {a, b};
  }

auto fit(Regression const &reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}