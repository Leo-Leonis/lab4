#include <iostream>
#include <vector>

struct Point {
  double x;
  double y;
};

int main() {
  std::vector<Point> points_;
  points_.push_back({65., -20.});
  points_.push_back({75., 17.});
  points_.push_back({85., 42.});
  points_.push_back({95., 94.});
  points_.push_back({105., 127.});

  double sum_x{};
  double sum_y{};
  double sum_xx{};
  double sum_xy{};
  int N = points_.size();

  for (int i = 0; i < N; i++) {
    sum_x += points_[i].x;
    sum_y += points_[i].y;
    sum_xx += points_[i].x * points_[i].x;
    sum_xy += points_[i].x * points_[i].y;
  }

  // intercept a
  double const a =
      ((sum_y * sum_xx) - (sum_x * sum_xy)) / ((N * sum_xx) - (sum_x * sum_x));
  // slope b
  double const b =
      ((N * sum_xy) - (sum_x * sum_y)) / ((N * sum_xx) - (sum_x * sum_x));

    std::cout << '\n' 
              << "RESULT: " << '\n'
              << "   sum_x = " << sum_x << '\n'
              << "   sum_y = " << sum_y << '\n'
              << "  sum_xx = " << sum_xx << '\n'
              << "  sum_xy = " << sum_xy << '\n'
              << "       N = " << N << '\n'
              << "       a = " << a << '\n'
              << "       b = " << b << '\n'
              << '\n';
}