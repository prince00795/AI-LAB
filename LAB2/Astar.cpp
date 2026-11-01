#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    map<char, vector<pair<char, int>>> graph = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'C', 2}, {'D', 5}}},
        {'C', {{'D', 1}}},
        {'D', {}}
    };
    map<char, int> h = {{'A', 5}, {'B', 3}, {'C', 1}, {'D', 0}};
    using State = tuple<int, char, vector<char>, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({h['A'], 'A', {'A'}, 0});
    map<char, int> vis;

    while (!pq.empty()) {
        auto [f, cur, path, g] = pq.top();
        pq.pop();
        if (cur == 'D') {
            cout << "Path: ";
            for (char c : path) cout << c << " ";
            cout << ", Cost: " << g << endl;
            return 0;
        }
        if (vis.count(cur) && vis[cur] <= g) continue;
        vis[cur] = g;
        for (auto& [nxt, w] : graph[cur]) {
            int ng = g + w;
            auto npath = path;
            npath.push_back(nxt);
            pq.push({ng + h[nxt], nxt, npath, ng});
        }
    }
}
