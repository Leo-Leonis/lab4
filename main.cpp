#include <iostream>
#include <string>

#include "regression.hpp"

void iterate(int i, int n, Regression& reg) {
  double x;
  double y;
  std::cout << '\n'
            << "[INFO: iteration " << i << " of " << n << "]" << '\n'
            << "Please insert the values of x and y separeted by one space: ";
  std::cin >> x >> y;
  reg.add(x, y);
}

void loop_iterate(int& i, int n, Regression& reg) {
  while (i < n + 1) {
    iterate(i, n, reg);
    ++i;
  }
}

int main() {
  int n;
  int i = 1;
  std::cout << "Please insert the number of fitting iterations (at least 2): ";
  std::cin >> n;
  if (n < 2) {
    std::cout << '\n'
              << "ERROR: The number of iterations must be greater than 2!"
              << '\n';
  } else {
    Regression reg;
    loop_iterate(i, n, reg);
    std::string feedback;
    std::cout << '\n'
              << "OPTION: Do you want to add extra iterations?" << '\n'
              << "[Type 'Y' for yes, type anything else to proceed fitting.]"
              << '\n'
              << "ANSWER: ";
    std::cin >> feedback;
    if (feedback == "Y") {
      int m;
      std::cout
          << '\n'
          << "How many iterations do you want to add?" << '\n'
          << "[WARNING: LAST CALL, you cannot add other iterations later.] "
          << '\n'
          << "Number of extra iterations: ";
      std::cin >> m;
      loop_iterate(i, n + m, reg);
    }
    auto result = reg.fit();
    std::cout << '\n'
              << "RESULT:" << '\n'
              << "     intercept: " << result.A << '\n'
              << "         slope: " << result.B << '\n';
  }
}