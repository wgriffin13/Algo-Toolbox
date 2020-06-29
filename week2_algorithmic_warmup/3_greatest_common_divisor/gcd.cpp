#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int big_num = a;
  int small_num = b;
  if (a < b) {
    big_num = a;
    small_num = b;
  }
  int remainder = big_num % small_num;
  while (remainder != 0) {
    big_num = small_num;
    small_num = remainder;
    remainder = big_num % small_num;
  }
  return small_num;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
