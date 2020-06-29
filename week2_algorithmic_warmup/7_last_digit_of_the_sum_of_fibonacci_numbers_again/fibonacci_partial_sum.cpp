#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int partial_sum_fibonacci_last_digit(long long from, long long to) {
    int end_num = (fibonacci_last_digit((to + 2) % 60) + 9) % 10;
    int start_num = (fibonacci_last_digit((from + 1) % 60) + 9) % 10;
    return (end_num - start_num + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << partial_sum_fibonacci_last_digit(from, to) << '\n';
}
