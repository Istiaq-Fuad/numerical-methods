#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

class NewtonForward {
   private:
    ll factorial(int n) {
        ll ans = 1;
        for (int i = 1; i <= n; i++) ans *= i;
        return ans;
    }

    double calculate_u(double u, int t) {
        double up = 1;
        for (int i = 0; i < t; i++) {
            up *= u;
            u--;
        }

        return up / factorial(t);
    }

    void calculate_table(vector<vector<double>> &v) {
        int temp = v.size();
        for (int i = 2; i < v[0].size(); i++) {
            for (int j = 0; j < temp - 1; j++) {
                v[j][i] = v[j + 1][i - 1] - v[j][i - 1];
            }
            temp--;
        }
    }

   public:
    void print_table(vector<vector<double>> v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << ' ';
            }

            cout << '\n';
        }
    }

    double calculate_root(vector<vector<double>> &v, double value) {
        calculate_table(v);

        double a = v[0][0];
        double h = v[1][0] - v[0][0];
        double u = (value - a) / h;

        double ans = 0;
        for (int i = 0; i < v.size(); i++)
            ans += (calculate_u(u, i) * v[0][i + 1]);

        return ans;
    }
};

int main() {
    cout << fixed << setprecision(3);

    int n;
    cout << "number of inputs: " << ' ';
    cin >> n;

    vector<vector<double>> v(n, vector<double>(n + 1));
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i][0] = x;
        v[i][1] = y;
    }

    double value;
    cin >> value;

    NewtonForward newton_forward;
    cout << "the root is = " << newton_forward.calculate_root(v, value) << '\n';
}

// 6
// 1931 12
// 1941 15
// 1951 20
// 1961 27
// 1971 39
// 1981 52
// 1934