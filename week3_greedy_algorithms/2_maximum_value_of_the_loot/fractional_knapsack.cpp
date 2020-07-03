#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double> v_w(n);
  for (int i = 0; i < n; ++i) {
    v_w[i] = (double)values[i] / weights[i];
  }
  // write your code here
  while (capacity > 0) {
    double max_value = 0.0;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
      if (weights[i] > 0 && v_w[i] > max_value) {
        max_value = v_w[i];
        idx = i;
      }
    }
    // Escape if there is nothing left to add
    if (idx == -1) {
      break;
    }
    int weight_to_add = std::min(capacity, weights[idx]);
    value = value + (double)values[idx] * weight_to_add / weights[idx];
    weights[idx] = 0;
    capacity -= weight_to_add;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
