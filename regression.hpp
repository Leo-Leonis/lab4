#ifndef REGRESSION_HPP
#define REGRESSION_HPP

struct Result {
  double A;
  double B;
};

class Regression {
 private:
  int N_{};
  double sumx_{};
  double sumy_{};
  double sumxx_{};
  double sumxy_{};

 public:
  void add(double x, double y);
  Result fit() const;
};

#endif