#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
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

int sum_fibonacci_last_digit(long long n) {
    return (fibonacci_last_digit((n + 2) % 60) + 9) % 10;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << sum_fibonacci_last_digit(n);
}
