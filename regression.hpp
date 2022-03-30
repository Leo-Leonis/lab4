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
    bool operator==(Point const& other) const {
      return (x == other.x) && (y == other.y);
    }
  };

  std::vector<Point> points_{};

 public:
  void add(double x, double y);
  Result fit() const;
  void remove(double x, double y);
  void display_vector();
};

#endif