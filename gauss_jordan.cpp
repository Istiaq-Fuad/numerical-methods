#include <bits/stdc++.h>
using namespace std;

class GaussJordan {
   public:
    void calculate(int n, vector<vector<double>> &v) {
        for (int i = 0; i < n; i++) {
            if (v[i][i] == 0) {
                cout << "invalid data" << '\n';
                return;
            }

            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                double ratio = v[j][i] / v[i][i];

                for (int k = 0; k < n + 1; k++) {
                    v[j][k] -= v[i][k] * ratio;
                }
            }
        }

        char name = 'a';
        for (int i = 0; i < n; i++) {
            cout << name++ << " = " << v[i][n] / v[i][i] << '\n';
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<double>> v(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    GaussJordan gj;
    gj.calculate(n, v);
}

// 3
// 1 -1 2 3
// 1 2 3 5
// 3 -4 -5 -13