#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, vector<vector<pair<char, int>>>> graph = {
    {'A', {{{'B', 1}}, {{'C', 4}}}},
    {'B', {{{'D', 2}, {'E', 3}}}},
    {'C', {{{'F', 2}}}},
    {'D', {}}, {'E', {}}, {'F', {}}
};

map<char, int> heuristic = {{'A', 6}, {'B', 3}, {'C', 4}, {'D', 0}, {'E', 0}, {'F', 0}};

pair<int, vector<char>> ao_star(char node) {
    if (graph[node].empty()) return {heuristic[node], {node}};
    int best_cost = 1e9;
    vector<char> best_sol;
    for (auto& option : graph[node]) {
        int total_cost = 0;
        vector<char> sol = {node};
        for (auto& [child, cost] : option) {
            auto [c_cost, c_sol] = ao_star(child);
            total_cost += cost + c_cost;
            sol.insert(sol.end(), c_sol.begin(), c_sol.end());
        }
        if (total_cost < best_cost) {
            best_cost = total_cost;
            best_sol = sol;
        }
    }
    return {best_cost, best_sol};
}

int main() {
    auto [cost, sol] = ao_star('A');
    cout << "AO* Algorithm\nSolution: ";
    for (char c : sol) cout << c << " ";
    cout << "\nCost: " << cost << endl;
}
