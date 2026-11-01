#include <iostream>
using namespace std;

int f(int x) { return -(x - 5) * (x - 5) + 25; }

pair<int, int> hill_climbing(int cur) {
    while (true) {
        if (f(cur - 1) > f(cur)) cur -= 1;
        else if (f(cur + 1) > f(cur)) cur += 1;
        else break;
    }
    return {cur, f(cur)};
}

int main() {
    int start = 0;
    auto [sol, val] = hill_climbing(start);
    cout << "Starting Point: " << start << "\nBest Solution: " << sol << "\nMaximum Value: " << val << endl;
}
