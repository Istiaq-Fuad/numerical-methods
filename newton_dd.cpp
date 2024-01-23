#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

class NewtonDividedDifference {
   private:
    double calculate_u(vector<vector<double>> &v, double value, int t) {
        double u = 1;
        for (int i = 0; i < t; i++)
            u *= (value - v[i][0]);

        return u;
    }

    void calculate_table(vector<vector<double>> &v) {
        int temp = v.size();
        for (int i = 2; i < v[0].size(); i++) {
            for (int j = 0; j < temp - 1; j++) {
                v[j][i] = (v[j + 1][i - 1] - v[j][i - 1]) / (v[i + j - 1][0] - v[j][0]);
            }
            temp--;
        }
    }

   public:
    void print_table(vector<vector<double>> &v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << ' ';
            }

            cout << '\n';
        }
    }

    double calculate_root(vector<vector<double>> &v, double value) {
        calculate_table(v);

        double ans = 0;
        for (int i = 0; i < v.size(); i++)
            ans += (calculate_u(v, value, i) * v[0][i + 1]);

        return ans;
    }
};

int main() {
    cout << fixed << setprecision(5);

    int n;
    cout << "number of inputs: " << ' ';
    cin >> n;

    vector<vector<double>> v(n, vector<double>(n + 1));
    double x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i][0] = x;
        v[i][1] = y;
    }

    double value;
    cin >> value;

    NewtonDividedDifference newton_dd;
    cout << "the root is = " << newton_dd.calculate_root(v, value) << '\n';
}

/*
5
2.0 0.85467
2.3 0.75682
2.6 0.43126
2.9 0.22364
3.2 0.08567
2.8
ans -> 0.274617
*/