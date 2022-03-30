#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct Point {
  double x;
  double y;
  bool operator==(Point const& other) const {
    return (x == other.x) && (y == other.y);
  }
};

// funzione che mostra il vettore
void display_vector(std::vector<Point>& points_) {
  std::cout << '\n' << "Your vector is {" << '\n';
  for (int i = 0; points_.begin() + i != points_.end() - 1; i++) {
    std::cout << "(" << points_[i].x << ", " << points_[i].y << ")," << '\n';
  }
  std::cout << "(" << (points_.end() - 1)->x << ", " << (points_.end() - 1)->y
            << ")}" << '\n';
}

// funzione 1 che fa il fit dei dati
void calculate(std::vector<Point>& points_) {
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

// funzione 2 che cerca i points
void check_value(std::vector<Point>& points_) {
  assert(points_.size() > 1);
  // crea dall'input un oggetto di tipo Point
  double xf;
  double yf;
  std::cout << "Please type a pair of values separeted by a space: ";
  std::cin >> xf >> yf;
  Point checkpoint{xf, yf};

  // ricerca del vettore
  auto it = std::find(points_.begin(), points_.end(),
                      checkpoint);  // iteratore del point da cercare
  if (it == points_.end()) {
    std::cout << '\n' << "RESULT: no matching point found." << '\n';
  } else {
    std::cout
        << "RESULT: found point: (" << it->x << ", " << it->y << ")" << '\n'
        << "Do you want to remove this point? [type 'YES' or anything else] ";
    std::string feedback;
    std::cin >> feedback;

    // rimozione del point cercato
    if (feedback == "YES") {
      points_.erase(it);
      std::cout << '\n' << "[INFO: point successfully removed!]";
      display_vector(points_);
    }
  }
  std::cout << '\n'
            << "OPTION: Do you want to find other points? [type 'YES' or type "
               "anything else] ";
  std::string feedback1;
  std::cin >> feedback1;
  if (feedback1 == "YES") {
    check_value(points_);
  }  // recursion
}

int main() {
  // crea un vettore points_
  std::vector<Point> points_;
  points_.push_back({65., -20});
  points_.push_back({75., 17.});
  points_.push_back({85., 42.});
  points_.push_back({95., 94.});
  points_.push_back({105., 127.});

  // scelta della funzione da computare
  int check;
  std::cout << '\n'
            << "  1 = calculate regression " << '\n'
            << "  2 = find vector" << '\n'
            << '\n'
            << "Choose your function to be iterated: ";
  std::cin >> check;
  if (check == 1) calculate(points_);
  if (check == 2) check_value(points_);

  std::cout << '\n' << "-----------[Program End]-----------" << '\n';
}