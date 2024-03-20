#include <bits/stdc++.h>

using namespace std;

class Trapezoidal {
   public:
    double func(double x) {
        return exp(x);
    }

    void calculate(double upper, double lower, int n) {
        double ans = 0;
        ans += func(upper) + func(lower);
        double h = (upper - lower) / n;

        for (int i = 1; i < n; i++) {
            ans += (2 * func(lower + h * i));
        }

        ans *= h / 2;

        cout << ans << '\n';
    }
};

int main() {
    double upper, lower;
    int n;

    cin >> upper >> lower >> n;

    Trapezoidal trap;
    trap.calculate(upper, lower, n);
}