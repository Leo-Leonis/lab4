#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <vector>
struct Result {
  double A;
  double B;
  int numeri;
};

class Regression {
 private:

  struct Point {
    double x;
    double y;
  };

  std::vector<Point> points_{};

 public:
  void add(double x, double y);
  Result fit() const;
};

#endif