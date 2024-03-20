#include <bits/stdc++.h>
using namespace std;

class GaussianElimination {
   public:
    void calculate(int n, vector<vector<double>> &v) {
        for (int i = 0; i < n; i++) {
            if (v[i][i] == 0) {
                cout << "invalid data" << '\n';
                return;
            }

            for (int j = i + 1; j < n; j++) {
                double ratio = v[j][i] / v[i][i];

                for (int k = j; k < n + 1; k++) {
                    v[j][k] -= v[i][k] * ratio;
                }
            }
        }

        // Back substitution
        double temp = v[n - 1][n] / v[n - 1][n - 1];
        v[n - 1][n - 1] = temp;
        char name = 'z';
        cout << name-- << " = " << temp << '\n';
        for (int i = n - 2; i >= 0; i--) {
            double sum = 0;
            for (int j = i + 1; j < n; j++) {
                sum += v[i][j] * v[i + 1][j];
                v[i][j] * v[i + 1][j];
            }

            temp = (v[i][n] - sum) / v[i][i];
            v[i][i] = temp;

            cout << name-- << " = " << temp << '\n';
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
   
    int n;
    cin >> n;

    vector<vector<double>> v(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    GaussianElimination ge;
    ge.calculate(n, v);
}

// 3
// 1 -1 2 3
// 1 2 3 5
// 3 -4 -5 -13