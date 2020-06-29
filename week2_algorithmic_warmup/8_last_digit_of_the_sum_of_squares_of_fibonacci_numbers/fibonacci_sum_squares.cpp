#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_last_digit(long long n) {

    long long current   = 0;
    long long next      = 1;
    long long old_next  = 0;
    for (long long i = 0; i < n; ++i) {
        old_next = next;
        next = (current + next) % 10;
        current = old_next;
    }
    return current;
}

int sum_squares_fibonacci_last_digit(long long n) {
    int vertical_side = fibonacci_last_digit((n) % 60);
    int horizontal_side = fibonacci_last_digit((n + 1) % 60);
    return (vertical_side * horizontal_side) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << sum_squares_fibonacci_last_digit(n);
}
