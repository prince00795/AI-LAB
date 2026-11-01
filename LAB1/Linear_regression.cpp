#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<double>> X = {{1000, 2}, {1500, 3}, {2000, 4}, {2500, 4}, {3000, 5}};
    vector<double> y = {200, 300, 400, 500, 600};
    int m = y.size(), iterations = 10000;
    double w1 = 0, w2 = 0, b = 0, alpha = 1e-8;

    for (int i = 0; i < iterations; ++i) {
        double dw1 = 0, dw2 = 0, db = 0, cost = 0;
        for (int j = 0; j < m; ++j) {
            double err = (b + w1 * X[j][0] + w2 * X[j][1]) - y[j];
            cost += err * err;
            dw1 += err * X[j][0];
            dw2 += err * X[j][1];
            db += err;
        }
        cost /= (2.0 * m);
        w1 -= alpha * (dw1 / m);
        w2 -= alpha * (dw2 / m);
        b -= alpha * (db / m);
        if (i % 1000 == 0) cout << "Iteration: " << i << " Cost: " << cost << endl;
    }
    cout << "\nFinal Parameters:\nw1 = " << w1 << "\nw2 = " << w2 << "\nb = " << b << endl;
}
