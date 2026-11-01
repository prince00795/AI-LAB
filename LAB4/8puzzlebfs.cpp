#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

void print_puzzle(const vector<int>& s) {
    for (int i = 0; i < 9; ++i) {
        cout << s[i] << (i % 3 == 2 ? "\n" : " ");
    }
    cout << endl;
}

int main() {
    vector<int> start = {1, 2, 3, 4, 0, 6, 7, 5, 8}, goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    queue<pair<vector<int>, vector<vector<int>>>> q;
    set<vector<int>> vis = {start};
    q.push({start, {start}});
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [s, path] = q.front();
        q.pop();
        if (s == goal) {
            cout << "Solution found!\nNumber of moves: " << path.size() - 1 << "\n\n";
            for (auto& st : path) print_puzzle(st);
            return 0;
        }
        int z = find(s.begin(), s.end(), 0) - s.begin();
        int r = z / 3, c = z % 3;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
                auto ns = s;
                swap(ns[z], ns[nr * 3 + nc]);
                if (!vis.count(ns)) {
                    vis.insert(ns);
                    auto npath = path;
                    npath.push_back(ns);
                    q.push({ns, npath});
                }
            }
        }
    }
    cout << "No solution found." << endl;
}
