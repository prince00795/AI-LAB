#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<string> facts = {"A", "B"};
vector<pair<set<string>, string>> rules = {
    {{"A", "B"}, "C"}, {{"C"}, "D"}, {{"D"}, "E"}
};

bool backward_chaining(const string& goal) {
    if (facts.count(goal)) {
        cout << goal << " is a known fact\n";
        return true;
    }
    for (auto& [conds, res] : rules) {
        if (res == goal) {
            cout << "Checking: " << goal << "\n";
            bool ok = true;
            for (auto& c : conds) if (!backward_chaining(c)) { ok = false; break; }
            if (ok) return true;
        }
    }
    return false;
}

int main() {
    string goal = "E";
    if (backward_chaining(goal)) cout << "Goal " << goal << " is proved\n";
    else cout << "Goal " << goal << " cannot be proved\n";
}
