#include <iostream>
#include <vector>
using namespace std;

int activation(double x) { return x >= 0 ? 1 : 0; }

int main() {
    vector<vector<int>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<int> y = {0, 0, 0, 1};
    double w0 = 0, w1 = 0, bias = 0, lr = 0.1;

    for (int epoch = 0; epoch < 10; ++epoch) {
        for (size_t i = 0; i < X.size(); ++i) {
            int pred = activation(X[i][0] * w0 + X[i][1] * w1 + bias);
            int err = y[i] - pred;
            w0 += lr * err * X[i][0];
            w1 += lr * err * X[i][1];
            bias += lr * err;
        }
    }
    cout << "Training completed\nWeights: [" << w0 << " " << w1 << "]\nBias: " << bias << "\n\nPredictions:\n";
    for (auto& x : X) {
        int pred = activation(x[0] * w0 + x[1] * w1 + bias);
        cout << "[" << x[0] << " " << x[1] << "] -> " << pred << "\n";
    }
}
