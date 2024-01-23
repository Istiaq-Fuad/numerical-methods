#include <bits/stdc++.h>

using namespace std;
#define MAX_ITER 1000000
const int lb = -1000;
const int ub = 1000;

class FalsePosition {
   public:
    double f(double x) {
        return x * x * x - x * x + 2;
    }

    double calculate_root(double a, double b) {
        double xr;
        for (int i = 0; i < MAX_ITER; i++) {
            xr = (a * f(b) - b * f(a)) / (f(b) - f(a));

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
    FalsePosition false_position;

    double a = 0;
    double b = 1;
    while (false_position.f(a) >= 0) a = (rand() % (ub - lb + 1)) + lb;
    while (false_position.f(b) <= 0) b = (rand() % (ub - lb + 1)) + lb;
    cout << a << ' ' << b << '\n';

    cout << "the root is = " << false_position.calculate_root(a, b) << '\n';
}