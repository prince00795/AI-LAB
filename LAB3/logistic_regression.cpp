#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double sigmoid(double z) { return 1.0 / (1.0 + exp(-z)); }

int main() {
    vector<double> X = {1, 2, 3, 4, 5, 6}, y = {0, 0, 0, 1, 1, 1};
    double w = 0.0, b = 0.0, lr = 0.1;
    int epochs = 1000, n = X.size();

    for (int i = 0; i < epochs; ++i) {
        double dw = 0, db = 0, cost = 0;
        for (int j = 0; j < n; ++j) {
            double p = sigmoid(w * X[j] + b);
            double err = p - y[j];
            cost -= y[j] * log(p + 1e-9) + (1 - y[j]) * log(1 - p + 1e-9);
            dw += err * X[j];
            db += err;
        }
        w -= lr * (dw / n);
        b -= lr * (db / n);
        if (i % 100 == 0) cout << "Epoch: " << i << " Cost: " << cost / n << endl;
    }
    cout << "\nTrained Model\nWeight (w): " << w << "\nBias (b): " << b << endl;
    double x = 4.5, prob = sigmoid(w * x + b);
    cout << "\nNew Input: " << x << "\nProbability: " << prob << "\nPredicted Class: " << (prob >= 0.5 ? 1 : 0) << endl;
}
