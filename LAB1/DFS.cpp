#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

vector<char> dfs(map<char, vector<char>>& g, char start) {
    set<char> vis;
    stack<char> st;
    st.push(start);
    vector<char> order;
    while (!st.empty()) {
        char u = st.top();
        st.pop();
        if (!vis.count(u)) {
            vis.insert(u);
            order.push_back(u);
            auto& adj = g[u];
            for (auto it = adj.rbegin(); it != adj.rend(); ++it)
                if (!vis.count(*it)) st.push(*it);
        }
    }
    return order;
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}}, {'B', {'D', 'E'}}, {'C', {'F'}},
        {'D', {}}, {'E', {'F'}}, {'F', {}}
    };
    for (char c : dfs(graph, 'A')) cout << c << " ";
    cout << endl;
}
