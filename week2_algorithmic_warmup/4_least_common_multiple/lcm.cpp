#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {

  int big_num = a;
  int small_num = b;
  if (a < b) {
    big_num = b;
    small_num = a;
  }

  int remainder = 1;
  int i = 0;
  long long lcm = 0;
  while (remainder != 0) {
    ++i;
    lcm = (long long)small_num * i;
    remainder = lcm % big_num;
  }
  return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
