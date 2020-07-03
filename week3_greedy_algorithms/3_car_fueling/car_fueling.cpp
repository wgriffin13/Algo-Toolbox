#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int num_refills = 0;
    int next_refill = 0;
    int n = stops.size();
    int current_distance = 0;
    while (num_refills <= n + 1) {
        // Don't need to stop
        if ((dist - current_distance) < tank) {
            return num_refills;
        }
        // Find the next refill
        while (next_refill < n - 1 && (stops[next_refill] - current_distance) <= tank) {
            next_refill += 1;
        }
        // Cannot make it to the next stop
        if (current_distance == stops[next_refill]) {
            return -1;
        }
        // Update progress
        current_distance = stops[next_refill];
        num_refills += 1;
    }
    return -1;
}

int compute_min_refills_vec(int dist, int tank, vector<int> & stops) {
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    int num_refills = 0;
    int current_refill = 0;
    int n = stops.size();
    while (current_refill <= n) {
        int last_refill = current_refill;
        while (current_refill <= n && (stops[current_refill + 1] - stops[last_refill]) <= tank) {
            current_refill += 1;
        }
        if (current_refill == last_refill) {
            return -1;
        }
        if (current_refill <= n) {
            num_refills += 1;
        }
    }
    return num_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills_vec(d, m, stops) << "\n";

    return 0;
}
