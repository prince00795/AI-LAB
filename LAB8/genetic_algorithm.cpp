#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fitness(const string& c) {
    int x = stoi(c, nullptr, 2);
    return x * x;
}

string selection(const vector<string>& pop) {
    string best = "";
    for (int i = 0; i < 3; ++i) {
        const string& cand = pop[rand() % pop.size()];
        if (best.empty() || fitness(cand) > fitness(best)) best = cand;
    }
    return best;
}

pair<string, string> crossover(const string& p1, const string& p2) {
    int pt = 1 + rand() % 4;
    return {p1.substr(0, pt) + p2.substr(pt), p2.substr(0, pt) + p1.substr(pt)};
}

string mutation(string c) {
    for (char& b : c)
        if ((rand() / (double)RAND_MAX) < 0.1) b = (b == '0' ? '1' : '0');
    return c;
}

int main() {
    srand(time(nullptr));
    vector<string> pop(10, "00000");
    for (auto& c : pop)
        for (char& b : c) b = (rand() % 2 ? '1' : '0');

    auto cmp = [](const string& a, const string& b) { return fitness(a) < fitness(b); };

    for (int gen = 1; gen <= 20; ++gen) {
        vector<string> next_pop;
        while (next_pop.size() < 10) {
            auto [c1, c2] = crossover(selection(pop), selection(pop));
            next_pop.push_back(mutation(c1));
            next_pop.push_back(mutation(c2));
        }
        pop = next_pop;
        string best = *max_element(pop.begin(), pop.end(), cmp);
        cout << "Generation: " << gen << " Best: " << best << " Fitness: " << fitness(best) << "\n";
    }
    string best = *max_element(pop.begin(), pop.end(), cmp);
    cout << "\nBest Solution: " << stoi(best, nullptr, 2) << "\nMaximum Fitness: " << fitness(best) << "\n";
}
