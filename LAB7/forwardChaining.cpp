#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<string> facts = {"A", "B"};
    vector<pair<set<string>, string>> rules = {
        {{"A", "B"}, "C"}, {{"C"}, "D"}, {{"D"}, "E"}
    };
    while (true) {
        bool added = false;
        for (auto& [conds, res] : rules) {
            if (!facts.count(res) && includes(facts.begin(), facts.end(), conds.begin(), conds.end())) {
                cout << "Derived: " << res << "\n";
                facts.insert(res);
                added = true;
            }
        }
        if (!added) break;
    }
    cout << "Final Facts: ";
    for (auto& f : facts) cout << f << " ";
    cout << "\n";
}
