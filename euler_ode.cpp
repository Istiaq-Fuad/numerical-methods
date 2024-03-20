#include <bits/stdc++.h>

using namespace std;

class Euler {
   public:
    double func(double x, double y) {
        return -x * y * y;
    }

    void calculate(double x0, double y0, double xn, int n) {
        double h = (xn - x0) / n;
        double x;
        double y = y0;
        for (int i = 1; i <= n; i++) {
            x = x0 + i * h;
            y = y + h * func(x, y);
        }

        cout << "y = " << y << '\n';
    }
};

int main() {
    double x0, y0, xn;
    int n;

    cin >> x0 >> y0 >> xn >> n;

    Euler eu;
    eu.calculate(x0, y0, xn, n);
}