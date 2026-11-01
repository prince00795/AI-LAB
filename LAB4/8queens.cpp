#include <iostream>
#include <vector>
using namespace std;

bool is_safe(vector<vector<int>>& b, int r, int c, int n) {
    for (int i = 0; i < r; ++i) if (b[i][c]) return false;
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) if (b[i][j]) return false;
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; --i, ++j) if (b[i][j]) return false;
    return true;
}

bool solve(vector<vector<int>>& b, int r, int n) {
    if (r == n) return true;
    for (int c = 0; c < n; ++c) {
        if (is_safe(b, r, c, n)) {
            b[r][c] = 1;
            if (solve(b, r + 1, n)) return true;
            b[r][c] = 0;
        }
    }
    return false;
}

int main() {
    int n = 8;
    vector<vector<int>> b(n, vector<int>(n, 0));
    if (solve(b, 0, n)) {
        cout << "Solution:\n";
        for (auto& row : b) {
            for (int x : row) cout << (x ? "Q " : ". ");
            cout << "\n";
        }
    } else cout << "No solution exists.\n";
}
