#include "regression.hpp"
#include <algorithm>
#include <iostream>

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

void Regression::remove(double xf, double yf){
  if (points_.size() <= 1) {
    std::cout << '\n' << "ERROR: At least two points are required for this option";
  } else {
    Point checkpoint{xf, yf};
    auto it = std::find(points_.begin(), points_.end(), checkpoint);  // iteratore del point da cercare
    if (it == points_.end()) {
      std::cout << '\n' << "RESULT: no matching point found." << '\n'
                << "type anything to continue...";
      std::string dummy;
      std::cin >> dummy;
    } else {std::cout << '\n' << "RESULT: found point: (" << it->x << ", " << it->y << ")" <<'\n' 
                      << "Do you want to remove this point? [type 'YES', otherwise anything else to proceed] ";
            std::string feedback;
            std::cin >> feedback;

            // rimozione del point cercato
            if (feedback == "YES") {
              points_.erase(it);
              std::cout << '\n' << "[INFO: point successfully removed!]"
                        << '\n' << "type anything to continue...";
              std::string dummy;
              std::cin >> dummy;
            }
    }
  }
}

void Regression::display_vector() {
  std::cout << '\n' << "Your vector is {" << '\n';
  for (int i = 0; points_.begin() + i != points_.end() - 1; i++) {
    std::cout << "(" << points_[i].x << ", " << points_[i].y << ")," << '\n';
  }
  std::cout << "(" << (points_.end() - 1)->x << ", " << (points_.end() - 1)->y << ")}" << '\n';
}