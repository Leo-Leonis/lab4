#include "regression.hpp"

void Regression::add(double x, double y) {
    points_.push_back({x, y});
}

Result Regression::fit() const {
    double sum_x{};
    double sum_y{};
    double sum_xx{};
    double sum_xy{};
    int N = points_.size();

    for (auto const& p : points_) {
      sum_x += p.x;
      sum_y += p.y;
      sum_xx += p.x * p.x;
      sum_xy += p.x * p.y;
    }

/*    for (int i = 0; i < N; i++) {
      sum_x += points_[i].x;
      sum_y += points_[i].y;
      sum_xx += points_[i].x * points_[i].x;
      sum_xy += points_[i].x * points_[i].y;
    }*/

    // intercept a
    double const a = ((sum_y * sum_xx) - (sum_x * sum_xy)) /
                     ((N * sum_xx) - (sum_x * sum_x));
    // slope b
    double const b =
        ((N * sum_xy) - (sum_x * sum_y)) / ((N * sum_xx) - (sum_x * sum_x));
    return {a, b, N};
  }

auto fit(Regression const &reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}