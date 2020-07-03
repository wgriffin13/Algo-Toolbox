#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void selection_sort(vector<int>& z) {   
  for (int i = 0; i < z.size() - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < z.size(); ++j) {
      if (z[j] < z[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      int tmp = z[i];
      z[i] = z[minIndex];
      z[minIndex] = tmp;
    }
  }
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here

  selection_sort(a);
  selection_sort(b);

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
