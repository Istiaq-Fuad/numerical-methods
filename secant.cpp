#include <bits/stdc++.h>

using namespace std;

const int lb = -1000;
const int ub = 1000;
const double error = 0.0001;

class Secant {
   public:
    double func(double x) {
        // return 3 * x - cos(x * 3.14159 / 180) - 1;
        return pow(x, 3) + x - 1;
    }

    double calculate_root(double x0, double x1) {
        double x2;

        while (abs(x0 - x1) >= error) {
            x2 = x1 - ((x1 - x0) / (func(x1) - func(x0))) * func(x1);
            x0 = x1;
            x1 = x2;
        }

        return x2;
    }
};

int main() {
    cout << fixed << setprecision(4);
    srand(time(0));

    Secant secant;
    double a = 0;
    double b = 1;
    while (secant.func(a) >= 0) a = (rand() % (ub - lb + 1)) + lb;
    while (secant.func(b) <= 0) b = (rand() % (ub - lb + 1)) + lb;

    cout << "the root is = " << secant.calculate_root(a, b) << '\n';
}