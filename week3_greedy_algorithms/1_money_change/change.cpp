#include <iostream>
#include <vector>
#include <math.h>

int get_change(int m) {
  //write your code here
  std::vector<int> coins = { 1, 5, 10 };
  int n = 0;
  while (m > 0) {
    if (m - coins.back() >= 0) {
      ++n;
      m -= coins.back();
    } else {
      coins.pop_back();
    }
  }
  return n;
}

int get_change_one_line(int m) {
  return floor(m /10) + floor((m % 10) / 5) + (m % 5);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change_one_line(m) << '\n';
}
