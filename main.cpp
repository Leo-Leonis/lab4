#include <iostream>
#include <string>

#include "regression.hpp"

void insert(int i, int n, Regression& reg) {
  double x;
  double y;
  std::cout << '\n'
            << "[INFO: iteration " << i << " of " << n << "]" << '\n'
            << "Please insert the values of x and y separated by one space: ";
  std::cin >> x >> y;
  reg.add(x, y);
}

void loop_insert(int& i, int n, Regression& reg) {
  while (i < n + 1) {
    insert(i, n, reg);
    ++i;
  }
}

void add(int& i, int& n, Regression& reg) {
      int m;
      std::cout
          << '\n'
          << "How many iterations do you want to add?"
          << '\n'
          << "Number of extra iterations: ";
      std::cin >> m;
      n += m;
      loop_insert(i, n, reg);
      reg.display_vector();
}

void remove(int& i, int& n, Regression& reg) {
  double xf;
  double yf;
  std::cout << '\n' << "Please type a pair of values separated by a space: ";
  std::cin >> xf >> yf;
  reg.remove(xf, yf);
  reg.display_vector();
  --i;
  --n;
}

void menu(int i, int n, Regression& reg) {
  std::cout << '\n' << "-----EDIT VECTOR PAGE-----" << '\n'
            << "Please type a letter to continue:"
            << '\n' <<  "[A]: add points; [R]: remove points; [anything else]: exit and fit points" << '\n';
  std::string feedback;
  std::cin >> feedback;
  if (feedback == "A") {add(i, n, reg); menu(i, n, reg);}
  if (feedback == "R") {remove(i, n, reg); menu(i, n, reg);}
}

int main() {
  int n;
  int i = 1;
  std::cout << "Please insert the number of fitting iterations (at least 2): ";
  std::cin >> n;
  if (n < 2) {
    // numero di iterazioni insufficiente (n < 2)
    std::cout << '\n'
              << "ERROR: The number of iterations must be greater than 2!"
              << '\n';
  } else {
    Regression reg;
    loop_insert(i, n, reg);
    reg.display_vector();
    std::cout << '\n' << "OPTION: Do you want to edit your vector of points?"
              << '\n' << "[type 'YES', otherwise anything else to proceed to fit] ";
    std::string feed;
    std::cin >> feed;
    if (feed == "YES") {menu(i, n, reg);}
    auto result = reg.fit();
    std::cout << '\n'
              << "RESULT:" << '\n'
              << "     intercept: " << result.A << '\n'
              << "         slope: " << result.B << '\n';

    std::cout << "-----------Program End-----------" << '\n';
  }
}