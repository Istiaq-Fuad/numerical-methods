#include <bits/stdc++.h>

using namespace std;

const int lb = -1000;
const int ub = 1000;
const double error = 0.001;

class Bisection {
   public:
    double f(double x) {
        return x * x * x - x * x + 2;
        // return x * x - 6 * x + 9;
    }

    double calculate_root(double a, double b) {
        double xr = (a + b) / 2;
        while ((b - a) >= error) {
            xr = (a + b) / 2;

            if (f(xr) == 0.0)
                return xr;
            else if (f(a) * f(xr) < 0)
                b = xr;
            else
                a = xr;
        }

        return xr;
    }
};

int main() {
    cout << fixed << setprecision(4);
    srand(time(0));
    Bisection bisection;

    double a = 0;
    double b = 1;
    while (bisection.f(a) >= 0) a = (rand() % (ub - lb + 1)) + lb;
    while (bisection.f(b) <= 0) b = (rand() % (ub - lb + 1)) + lb;
    cout << a << ' ' << b << '\n';

    cout << "the root is = " << bisection.calculate_root(a, b) << '\n';
}