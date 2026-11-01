#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

vector<char> bfs(map<char, vector<char>>& g, char start) {
    set<char> vis = {start};
    queue<char> q;
    q.push(start);
    vector<char> order;
    while (!q.empty()) {
        char u = q.front();
        q.pop();
        order.push_back(u);
        for (char v : g[u]) {
            if (!vis.count(v)) {
                vis.insert(v);
                q.push(v);
            }
        }
    }
    return order;
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}}, {'B', {'D', 'E'}}, {'C', {'F'}},
        {'D', {}}, {'E', {'F'}}, {'F', {}}
    };
    for (char c : bfs(graph, 'A')) cout << c << " ";
    cout << endl;
}
